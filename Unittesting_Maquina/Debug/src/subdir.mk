################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/maquina.cc 

CPP_SRCS += \
../src/TestMaquina.cpp 

CC_DEPS += \
./src/maquina.d 

OBJS += \
./src/TestMaquina.o \
./src/maquina.o 

CPP_DEPS += \
./src/TestMaquina.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -I"C:\Users\franm\Desktop\UNIVERSIDAD\Segundo\IngenieriaSoftware\implementacion_IS\Equipo-501\Unittesting_Maquina\cute" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -I"C:\Users\franm\Desktop\UNIVERSIDAD\Segundo\IngenieriaSoftware\implementacion_IS\Equipo-501\Unittesting_Maquina\cute" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


