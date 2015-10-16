#!/bin/sh

#  create_binary.sh
#  
#
#  Created by Anushruth on 09/11/2014.
#
CC=/usr/android/android-ndk-r10b/toolchains/arm-linux-androideabi-4.8/prebuilt/darwin-x86_64/bin/arm-linux-androideabi-gcc
CC -o avcodec ~/Documents/ports/libav/doc/examples/avcodec.c -I/usr/android/android-ndk-r10b/platforms/android-9/arch-arm/usr/include -I./android/arm/include -L/usr/android/android-ndk-r10b/platforms/android-9/arch-arm/usr/lib -L./android/arm/lib -lavcodec -lavdevice -lavformat -lavresample -lavutil -lswscale