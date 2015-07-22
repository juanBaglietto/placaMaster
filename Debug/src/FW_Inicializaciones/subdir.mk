################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Inicializaciones/FW_InitUART2.c \
../src/FW_Inicializaciones/FW_InitUART3.c \
../src/FW_Inicializaciones/KitInic.c \
../src/FW_Inicializaciones/UtilesInfo2.c \
../src/FW_Inicializaciones/cr_startup_lpc176x.c 

OBJS += \
./src/FW_Inicializaciones/FW_InitUART2.o \
./src/FW_Inicializaciones/FW_InitUART3.o \
./src/FW_Inicializaciones/KitInic.o \
./src/FW_Inicializaciones/UtilesInfo2.o \
./src/FW_Inicializaciones/cr_startup_lpc176x.o 

C_DEPS += \
./src/FW_Inicializaciones/FW_InitUART2.d \
./src/FW_Inicializaciones/FW_InitUART3.d \
./src/FW_Inicializaciones/KitInic.d \
./src/FW_Inicializaciones/UtilesInfo2.d \
./src/FW_Inicializaciones/cr_startup_lpc176x.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Inicializaciones/%.o: ../src/FW_Inicializaciones/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Juani\Documents\LPCXpresso_7.7.2_379\workspace\PlacaMaster\src\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


