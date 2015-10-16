/*
 * logging.h
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#ifndef ANDROID_LOGGING_H_
#define ANDROID_LOGGING_H_

//TODO: change to android logging
#include <android/log.h>

#define MODNAME "EVAUTO"

#define logd(...)  __android_log_print(ANDROID_LOG_VERBOSE, MODNAME __FILE__ ,__VA_ARGS__)





#endif /* ANDROID_LOGGING_H_ */
