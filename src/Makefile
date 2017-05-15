CFLAGS = -Wall -o
INCLUDE = -l wiringPi

pi-bot.o: control.c
	gcc $(CFLAGS) $@ $< $(INCLUDE)
	
clean:
	rm *.o
