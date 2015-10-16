/*
 * gen_queue_test.h
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#ifndef TEST_GEN_QUEUE_TEST_H_
#define TEST_GEN_QUEUE_TEST_H_

#include <os/os_thread.h>
#include <utils/gen_queue.h>
class gen_queue_test {
public:
	gen_queue_test();
	int 	start_test();
	virtual ~gen_queue_test();
};

#endif /* TEST_GEN_QUEUE_TEST_H_ */
