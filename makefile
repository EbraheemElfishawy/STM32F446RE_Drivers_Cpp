CC      = arm-none-eabi-cpp
MACH    = cortex-m4
CFLAGS  = -c -mcpu=$(MACH) -mthumb -std=c++20 -Wall 
#-Wall all Warnings
LDFLAGS = -T Stm32f4_ls.ld -nostdlib -Wl,-Map=final.map

main.o: main.cpp
	#$(CC) $(CFLAGS) main.cpp -o main.o 
	#or
	$(CC) $(CFLAGS) $^ -o $@ 
gpio.o: gpio.cpp
	$(CC) $(CFLAGS) $^ -o $@
	
rcc.o: rcc.cpp
	$(CC) $(CFLAGS) $^ -o $@ 
	
Stm32f4_startup.o: Stm32f4_startup.c
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf *.o *.elf
	
final.elf: main.o gpio.o rcc.o Stm32f4_startup.o
	$(CC) $(LDFLAGS) $^ -o $@

load:
	openocd -f board/st_nucleo_f4.cfg
	
all: main.o gpio.o rcc.o Stm32f4_startup.o final.elf

