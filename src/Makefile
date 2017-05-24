CFLAGS = -Wall -o
INCLUDE = -l wiringPi

pi-bot.o: main.c
	gcc $(CFLAGS) $@ $< $(INCLUDE)
	
test.o: test.c
	gcc $(CFLAGS) $@ $< $(INCLUDE)

control.o: control.c
	gcc $(CFLAGS) $@ $< $(INCLUDE)

reset.o: reset.c
	gcc $(CFLAGS) $@ $< $(INCLUDE)

clean:
	rm *.o
