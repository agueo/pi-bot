CFLAGS= -Wall -o
INCLUDE= -lwiringPi

all:
	gcc $(CFLAGS) blink.o LED.c $(INCLUDE)
	gcc $(CFLAGS) count.o counter.c $(INCLUDE)

clean:
	rm *.o
