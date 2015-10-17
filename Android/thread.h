/*
 * thread.h
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#ifndef ANDROID_THREAD_H_
#define ANDROID_THREAD_H_

#include <pthread.h>

#define MUX_LOCK(__NAME) pthread_mutex_t m_ ## __NAME
#define INIT_LOCK(__NAME) pthread_mutex_init(&m_ ## __NAME, NULL)
#define LOCK(__NAME) pthread_mutex_lock(&m_ ## __NAME)
#define UNLOCK(__NAME) pthread_mutex_unlock(&m_ ## __NAME)

#define THREAD(__NAME) pthread_t	m_ ## __NAME
#define TH_CREATE(__NAME, _FUNC, _DATA)	pthread_create(&m_ ## __NAME, NULL, _FUNC, _DATA)
#define MUX_SIGNAL(__NAME) pthread_cond_t m_cond_ ## __NAME = PTHREAD_COND_INITIALIZER;
#define MUX_SIGNAL_INIT(__NAME) pthread_cond_init(&m_cond_ ## __NAME, NULL)
#define MUX_WAIT_FOR_SIGNAL(__NAME, __MUX) pthread_cond_wait(&m_cond_ ## __NAME, &m_ ## __MUX)
#define MUX_BCAST_SIGNAL(__NAME) pthread_cond_signal(&m_cond_ ## __NAME)
#endif /* ANDROID_THREAD_H_ */
