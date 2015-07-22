################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FW_Drivers/FW_DHTxx.c \
../src/FW_Drivers/FW_Pantalla.c \
../src/FW_Drivers/FW_TimersM.c \
../src/FW_Drivers/FW_UART2.c \
../src/FW_Drivers/FW_UART3.c \
../src/FW_Drivers/FW_isr.c \
../src/FW_Drivers/PR_Serie2.c \
../src/FW_Drivers/PR_Serie3.c 

OBJS += \
./src/FW_Drivers/FW_DHTxx.o \
./src/FW_Drivers/FW_Pantalla.o \
./src/FW_Drivers/FW_TimersM.o \
./src/FW_Drivers/FW_UART2.o \
./src/FW_Drivers/FW_UART3.o \
./src/FW_Drivers/FW_isr.o \
./src/FW_Drivers/PR_Serie2.o \
./src/FW_Drivers/PR_Serie3.o 

C_DEPS += \
./src/FW_Drivers/FW_DHTxx.d \
./src/FW_Drivers/FW_Pantalla.d \
./src/FW_Drivers/FW_TimersM.d \
./src/FW_Drivers/FW_UART2.d \
./src/FW_Drivers/FW_UART3.d \
./src/FW_Drivers/FW_isr.d \
./src/FW_Drivers/PR_Serie2.d \
./src/FW_Drivers/PR_Serie3.d 


# Each subdirectory must supply rules for building sources it contributes
src/FW_Drivers/%.o: ../src/FW_Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -I"C:\Users\Juani\Documents\LPCXpresso_7.7.2_379\workspace\PlacaMaster\src\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


