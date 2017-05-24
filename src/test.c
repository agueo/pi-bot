#include <stdio.h> 
#include <stdlib.h> 
#include <wiringPi.h>
#include <time.h>

#define TRIG 5
#define ECHO 6

int main(void)
{
	unsigned int _delay = 2000;
	clock_t t_off;
	clock_t t_on;
	double t_tot;
	double distance;	
	int i = 0;

	wiringPiSetup();
	wiringPiSetupGpio();

	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	digitalWrite(TRIG, LOW);
	printf("Waiting for sensor to settle\n");
	delay(_delay);

	for(i = 0; i < 5; i++)
	{
		digitalWrite(TRIG, HIGH);
		delayMicroseconds(10);
		digitalWrite(TRIG,LOW);

		while(digitalRead(ECHO) == 0)
			t_off = clock();
		while(digitalRead(ECHO) == 1)
			t_on = clock();

		t_tot = ((double)(t_on - t_off)) / CLOCKS_PER_SEC;
		printf("time taken in sec: %f.\n", t_tot);

		distance = (t_tot*34300)/2;

		printf("Distance in cm: %f.\n", distance);
		
		digitalWrite(TRIG,LOW);
		delay(_delay);
	}
	return 0;
}
