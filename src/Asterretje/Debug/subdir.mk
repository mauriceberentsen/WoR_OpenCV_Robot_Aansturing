################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AStar.cpp \
../CommandLineParser.cpp \
../Graph.cpp \
../main.cpp 

OBJS += \
./AStar.o \
./CommandLineParser.o \
./Graph.o \
./main.o 

CPP_DEPS += \
./AStar.d \
./CommandLineParser.d \
./Graph.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/local/boost/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


