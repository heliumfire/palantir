/*
 * event_dispatch_manager.h
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#ifndef OS_EVENT_DISPATCH_MANAGER_H_
#define OS_EVENT_DISPATCH_MANAGER_H_

#include <event_auto.h>
#include <utils/list.h>
#include <utils/gen_queue.h>

class event_dispatch_provider;

/**
 * @brief Structure hosting the dispatcher data.
 * @param dispatcher_name string containing name of the dispatcher
 * @param dispatch_provider Pointer to event_dispatch_provider
 */
typedef struct EVENT_DISP_CONFIG{
	char* dispatcher_name;
	event_dispatch_provider* dispatch_provider;
}event_disp_config, *pevent_disp_config;

bool dispatcher_compare(pevent_disp_config m_orig_disp, pevent_disp_config m_in_disp){
	if(m_orig_disp != NULL || m_in_disp != NULL){
		if(m_orig_disp->dispatcher_name == NULL || m_in_disp->dispatcher_name == NULL)
			return false;
		if(strcmp(m_orig_disp->dispatcher_name, m_in_disp->dispatcher_name) != 0)
			return false;
	}
	return false;
}
/**
 * @brief Event Dispatch Manager handles all the dispatches supported by the module
 */
class event_dispatch_manager {
public:
	/**
	 * @brief get instance of event_dispatch_manager
	 * @detail As there can be only one instance of event_dispatch_manager the Ctor is private.
	 * Any access goes through this static function
	 * @return returns an instance of event_dispatch_manager
	 */
	static event_dispatch_manager* 	get_instance(){
		if(instance == NULL){
			instance =  new event_dispatch_manager();
		}
		return instance;
	};

	/**
	 * @brief registers a queue to the dispatcher based on configuration, If there is a match
	 * @param m_pevent_disp_config pointer to the descriptor of the dispatcher
	 * @return error code check status_codes.h
	 */
	template<class _type>
	static int register_dispatch_endpoint(char* m_pevent_disp_config, gen_queue<_type>* queue);

	/**
	 * @brief register a dispatch handler to the dispatch manager
	 * @param m_event_dispatch_provider pointer to the dispatcher config
	 * @return error code check status_codes.h
	 */
	static int register_dispatch_handler(event_dispatch_provider* m_event_dispatch_provider);

	/**
	 * @brief unregister a dispatch handler to the dispatch manager
	 * @param m_event_dispatch_provider pointer to the dispatcher config
	 * @return error code check status_codes.h
	 */
	static int unregister_dispatch_handler(event_dispatch_provider* m_event_dispatch_provider);

	/**
	 * @brief Dtor
	 */
	virtual ~event_dispatch_manager();
private:

	/**
	 * @brief instance of the event_dispatch_manager
	 */
	static event_dispatch_manager* instance;

	/**
	 * @brief Ctor
	 */
	event_dispatch_manager();

	list<event_disp_config, &dispatcher_compare>* dispatch_provider_list;
};

class event_dispatch_provider{
public:
	event_dispatch_provider();
	virtual int set_endpoint(void* m_event_queue);
	virtual pevent_disp_config get_dispatcher_configuration();
	virtual char* get_dispatcher_description();
	virtual void register_dispatcher(){event_dispatch_manager::register_dispatch_handler(this);}
	virtual void unregister_dispatcher(){event_dispatch_manager::unregister_dispatch_handler(this);}
	virtual ~event_dispatch_provider();
};

#endif /* OS_EVENT_DISPATCH_MANAGER_H_ */
