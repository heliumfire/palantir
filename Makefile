NDK=/Users/regnarts/android-ndk-r10c
SDK=/Users/regnarts/Downloads/android-sdk-macosx
ADB=${SDK}/platform-tools/adb
COMPILE_PREFIX=${NDK}/toolchains/x86_64-4.9/prebuilt/darwin-x86_64/bin/x86_64-linux-android-
CFLAGS=-fno-rtti -fno-exceptions -std=gnu++11 -pie --sysroot=${NDK}/platforms/android-21/arch-x86_64 -I${NDK}/platforms/android-21/arch-x86_64/usr/include -I. -L${NDK}/platforms/android-21/arch-x86_64/usr/lib64

SRC=main.cpp  
	
TEST:=test/gen_queue_test.cpp
	
all:
	${COMPILE_PREFIX}g++ ${CFLAGS} ${SRC} -o ev_automator -lstdc++
	${ADB} remount
	${ADB} push ev_automator /system/bin
	