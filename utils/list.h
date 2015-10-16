/*
 * list.h
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#ifndef UTILS_LIST_H_
#define UTILS_LIST_H_

#include <event_auto.h>

/**
 * @brief Class to maintain a list of elements
 * @detail This is a list wherein you can push elements and then retrieve them based on compare
 * @param _type Type of the element
 * @param compare comparison function to be run on the element
 */
template <class _type, bool (*compare)(_type*,_type*)>
class list{
public:
	/**
	 * @brief Ctor, initialize both head and tail
	 */
	list() : head(0), tail(0) {};

	/**
	 * @brief push to the list
	 * @param element element to be added to the list
	 * @return status/error code. Please refer to status_codes.h
	 */
	int	push(_type* element){
		if(head == NULL){
			head			= new list_t;
			head->element	= element;
			head->next		= NULL;
			tail 			= head;
		}
		else{
			tail->next 		= new list_t;
			tail			= tail->next;
			tail->element	= element;
			tail->next		= NULL;
		}
	};

	/**
	 * @brief check if the element exists in the list
	 * @param element The element to be checked
	 * @return true if the element exists on the list, else false
	 */
	bool check(_type* element){

	}

	/**
	 * @brief remove an element from the list
	 * @param element The element to be removed
	 * @return status/error code. Please refer to status_codes.h
	 */
	int remove(_type* element){

	}

	/**
	 * @brief get the element from the list
	 * @param element an element that would result true on compare on atleast one of the elements of the list
	 * @return NULL on failure or the required element
	 */
	_type* get(_type* element){

	}

private:

	/**
	 * @brief Structure containing the list
	 */
	typedef struct LIST_E{
		_type* 			element;
		struct LIST_E*	next;
	}list_t, *plist_t;
	plist_t	head, tail;
};



#endif /* UTILS_LIST_H_ */
