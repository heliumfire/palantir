/*
 * thread.h
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#ifndef ANDROID_THREAD_H_
#define ANDROID_THREAD_H_

#include <pthread.h>

#define MUX_LOCK(__NAME)					pthread_mutex_t m ## __NAME
#define INIT_LOCK(__NAME)					pthread_mutex_init(&m ## __NAME, NULL)
#define LOCK(__NAME)						pthread_mutex_lock(&m ## __NAME)
#define UNLOCK(__NAME)						pthread_mutex_unlock(&m ## __NAME)

#define THREAD(__NAME)						pthread_t	m ## __NAME
#define TH_CREATE(__NAME, _FUNC, _DATA)		pthread_create(&m ## __NAME, NULL, _FUNC, _DATA)
#endif /* ANDROID_THREAD_H_ */
