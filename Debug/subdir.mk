################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../EventDispatch.cpp \
../GenQueue.cpp 

OBJS += \
./EventDispatch.o \
./GenQueue.o 

CPP_DEPS += \
./EventDispatch.d \
./GenQueue.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	arm-linux-androideabi-g++ -I/Users/regnarts/android-ndk-r10c/platforms/android-19/arch-arm/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


