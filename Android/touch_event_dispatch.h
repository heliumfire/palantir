/*
 * event_dispatch.h
 *
 *  Created on: 13 Sep 2015
 *      Author: regnarts
 */

#ifndef OS_ANDROID_TOUCH_EVENT_DISPATCH_H_
#define OS_ANDROID_TOUCH_EVENT_DISPATCH_H_

#include <event_dispatch_manager.h>

#define NEWPAYLOAD() (payload*)malloc(sizeof(payload))

typedef enum {
    EVENT_TOUCH_DOWN,
    EVENT_TOUCH_REMOVE,
    EVENT_TOUCH_MOVE
}payload_type;


typedef struct{
    payload_type    pt;
    uint8_t         xp;
    uint8_t         yp;
    uint8_t         tid;
    uint8_t         pressure;
    uint8_t         major_axis;
#ifdef MINOR_AXIS_REQUIRED
    uint8_t         minor_axis;
#endif
} payload_t, *ppayload_t;

class touch_event_dispatch : event_dispatch_provider{
public:
	touch_event_dispatch();
	virtual ~touch_event_dispatch();
private:
	//char dispatcher_name[14] = "android_touch";
};

#endif /* OS_ANDROID_EVENT_DISPATCH_H_ */
