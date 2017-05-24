/* Pi-Bot - program to run a small rc car created with a raspbery pi 2
 * Agueo Lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <time.h>

#define M1_FWD 23
#define M1_BWD 24
#define M2_FWD 17
#define M2_BWD 27
#define TRIG 5
#define ECHO 6

void forward(int _delay);
void backwards(int _delay);
void right_turn(int _delay);
void left_turn(int _delay);
double distance(void);

int main()
{
	/* initialize the wiringPi library */
	unsigned int _delay = 2000;
	double dist;

	int i = 0;

	/* Initialize GPIO library and pins */
	wiringPiSetup();
	wiringPiSetupGpio();
	pinMode(M1_FWD, OUTPUT);
	pinMode(M1_BWD, OUTPUT);
	pinMode(M2_FWD, OUTPUT);
	pinMode(M2_BWD, OUTPUT);
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	/* Set all pins to LOW */
	digitalWrite(M1_FWD, LOW);
	digitalWrite(M1_BWD, LOW);
	digitalWrite(M2_FWD, LOW);
	digitalWrite(M2_BWD, LOW);
	digitalWrite(TRIG, LOW);

	//for(i = 0; i < 10; i++)
	while(1)
	{
		/* check if there is an object in the way */
		dist = distance();

		/* If there is no object in front of the car continue forward, else backup and turn around */
		if(dist > 15)
		{
			forward(_delay);
		}
		else if(dist <= 15)
		{
			backwards(_delay);
			right_turn(500);
			left_turn(1000);
		}
	}
	
	/* Reset all pins to LOW */
	digitalWrite(TRIG, LOW);
	digitalWrite(M1_FWD, LOW);
	digitalWrite(M1_BWD, LOW);
	digitalWrite(M2_FWD, LOW);
	digitalWrite(M2_BWD, LOW);

	return 0;
}

/* Forward function - Move the car forward
 * input: delay - How long the car should move forward for
 * ouput: none
 */
void forward(int _delay)
{
	digitalWrite(M1_FWD, HIGH);
	digitalWrite(M2_FWD, HIGH);
	delay(_delay);
	digitalWrite(M1_FWD, LOW);
	digitalWrite(M2_FWD, LOW);
}

/* Backwards function - Move the car in reverse
 * input: delay - How long the car should reverse
 * output: none
 */
void backwards(int _delay)
{
	digitalWrite(M1_BWD, HIGH);
	digitalWrite(M2_BWD, HIGH);
	delay(_delay);
	digitalWrite(M1_BWD, LOW);
	digitalWrite(M2_BWD, LOW);
}

/* right_turn - Turn the car to the right
 * input: delay - How long the car will turn right
 * output: none
 */
void right_turn(int _delay)
{
	digitalWrite(M1_BWD, HIGH);
	digitalWrite(M2_FWD, HIGH);
	delay(_delay);
	digitalWrite(M1_BWD, LOW);
	digitalWrite(M2_FWD, LOW);
}

/* left_turn - Turn the car to the left
 * input: delay - How long the car will turn left
 * ouput: none
 */
void left_turn(int _delay)
{
	digitalWrite(M1_FWD, HIGH);
	digitalWrite(M2_BWD, HIGH);
	delay(_delay);
	digitalWrite(M1_FWD, LOW);
	digitalWrite(M2_BWD, LOW);
}

/* distance - calculate the distance to anything around the car
 * input - none
 * output - double - The distance in cm to the nearest object
 */
double distance(void)
{
	clock_t start;
	clock_t end;
	double t_tot;
	double distance;
	
	/* Send out 10uS pulse */
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG, LOW);

	while(digitalRead(ECHO) == 0)
		start = clock();
	while(digitalRead(ECHO) == 1)
		end = clock();
	
	t_tot = ((double) end - start) / CLOCKS_PER_SEC; 
	distance = (t_tot * 34300) / 2;

	return distance;
}
