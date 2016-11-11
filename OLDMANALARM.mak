CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega128  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x20000 -ucrtatmega.o -bfunc_lit:0x8c.0x20000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.4096 -fihx_coff -S2
FILES = main.o 12864time.o DS18B20.o basic.o LCD.o USART.o SYN7318.o ESP8266.o 

OLDMANALARM:	$(FILES)
	$(CC) -o OLDMANALARM $(LFLAGS) @OLDMANALARM.lk   -lcatm128
main.o: D:\iccv7avr\include\string.h D:\iccv7avr\include\_const.h D:\iccv7avr\include\stdio.h D:\iccv7avr\include\stdarg.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h D:\iccv7avr\include\iom128v.h .\DS18B20.h .\basic.h .\12864time.h .\LCD.h .\USART.h .\SYN7318.h .\ESP8266.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
12864time.o: D:\iccv7avr\include\iom128v.h .\12864time.h .\basic.h .\LCD.h
12864time.o:	12864time.c
	$(CC) -c $(CFLAGS) 12864time.c
DS18B20.o: D:\iccv7avr\include\iom128v.h .\DS18B20.h .\basic.h
DS18B20.o:	DS18B20.C
	$(CC) -c $(CFLAGS) DS18B20.C
basic.o:
basic.o:	basic.c
	$(CC) -c $(CFLAGS) basic.c
LCD.o: D:\iccv7avr\include\iom128v.h .\LCD.h .\basic.h
LCD.o:	LCD.c
	$(CC) -c $(CFLAGS) LCD.c
USART.o: D:\iccv7avr\include\iom128v.h .\basic.h .\USART.h
USART.o:	USART.c
	$(CC) -c $(CFLAGS) USART.c
SYN7318.o: D:\iccv7avr\include\string.h D:\iccv7avr\include\_const.h D:\iccv7avr\include\stdio.h D:\iccv7avr\include\stdarg.h D:\iccv7avr\include\iom128v.h .\USART.h .\basic.h .\SYN7318.h .\LCD.h
SYN7318.o:	SYN7318.c
	$(CC) -c $(CFLAGS) SYN7318.c
ESP8266.o: D:\iccv7avr\include\string.h D:\iccv7avr\include\_const.h D:\iccv7avr\include\stdio.h D:\iccv7avr\include\stdarg.h D:\iccv7avr\include\iom128v.h .\USART.h .\basic.h .\ESP8266.h
ESP8266.o:	ESP8266.c
	$(CC) -c $(CFLAGS) ESP8266.c
