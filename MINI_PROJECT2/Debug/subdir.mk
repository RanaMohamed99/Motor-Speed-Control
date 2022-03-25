################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ExternInterrupt.c \
../adc.c \
../lcd.c \
../motor.c \
../project.c \
../timers.c 

OBJS += \
./ExternInterrupt.o \
./adc.o \
./lcd.o \
./motor.o \
./project.o \
./timers.o 

C_DEPS += \
./ExternInterrupt.d \
./adc.d \
./lcd.d \
./motor.d \
./project.d \
./timers.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


