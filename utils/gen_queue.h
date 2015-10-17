/*
 * GenQueue.h
 *
 *  Created on: 9 Sep 2015
 *      Author: regnarts
 */

#ifndef GEN_QUEUE_H_
#define GEN_QUEUE_H_

#include <os/os_thread.h>

//TODO: Change to EA_STATUS codes
#define GENQUEUE_SUCCESS	0
#define GENQUEUE_FAILURE	1
#define GENQUEUE_NOMEM		2
#define GENQUEUE_INIP		3
#define GENQUEUE_EMPTY		4

template <class _type>
class gen_queue {
public:
	/**
	 * @brief Ctor Initializes the lock, head and tail pointers of the queue
	 */
	gen_queue() : head(0), tail(0) {
		INIT_LOCK(gen_queue);
		MUX_SIGNAL_INIT(gen_queue);
		size = 0;
	};

	/**
	 * @brief Push into the queue
	 * @param data data to be pushed
	 * @param size size of the data
	 * @return status/error code. Please refer to status_codes.h
	 */

	int push(_type* data){
		if(data == NULL)
			return GENQUEUE_INIP;
		ppayload_t 	tmp;
		tmp = new payload_t();
		tmp->data = data;
		LOCK(gen_queue);
		printf("pushing to %p %d\n", tmp, size);
		if(head == NULL || tail == NULL){
			tmp->next = NULL;
			head = tmp;
			tail = head;
		}
		else{
			head->next = tmp;
			tmp->next = NULL;
			head = tmp;
		}
		size++;
		MUX_BCAST_SIGNAL(gen_queue);
		UNLOCK(gen_queue);
		return GENQUEUE_SUCCESS;
	};

//	/**
//	 * @brief pull an element from the queue
//	 * @param data pointer to the _type being pulled
//	 * @param size param size being pulled
//	 * @return status/error code. Please refer to status_codes.h
//	 */
//	int pull(_type* &data, int &size){
//		if(head == NULL || tail == NULL)
//			return GENQUEUE_EMPTY;
//		ppayload_t tmp;
//		LOCK(gen_queue);
//		printf("pulling from %p \n", tail);
//		data = tail->data;
//		tmp = tail;
//		tail = tail->next;
//		UNLOCK(gen_queue);
//		delete tmp;
//		return GENQUEUE_SUCCESS;
//	};

	/**
	 * @brief pull an element from the queue, wait (thread sleeps) until element is available
	 * @param data pointer to the _type being pulled
	 * @param size param size being pulled
	 */
	_type* pull(){
		_type* dq_data;
		ppayload_t tmp;
		LOCK(gen_queue);
		if(head == NULL || tail == NULL){
			MUX_WAIT_FOR_SIGNAL(gen_queue, gen_queue);
		}
		printf("pulling from %p %d\n", tail, size);
		dq_data = tail->data;
		tmp = tail;
		tail = tail->next;
		size--;
		UNLOCK(gen_queue);
		delete tmp;
		return dq_data;
	};

	virtual ~gen_queue(){
		_type* tmp;
		int size;
		LOCK(gen_queue);
		while(size != 0){
			tmp = pull();
			delete tmp;
		}
		UNLOCK(gen_queue);
	};
private:
	typedef struct PAYLOAD_E{
		_type*				data;
		struct PAYLOAD_E*	next;
	}payload_t, *ppayload_t;
	MUX_LOCK(gen_queue);
	MUX_SIGNAL(gen_queue);
	int size;
	ppayload_t		head;
	ppayload_t		tail;
};

#endif /* GEN_QUEUE_H_ */
