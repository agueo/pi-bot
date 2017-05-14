/* Pi-Bot - program to run a small rc car created with a raspbery pi 2
 * Agueo Lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

// TODO - Fill in the gpio motor numbers
#define M1_FWD
#define M1_BWD
#define M2_FWD
#define M2_BWD

void forward(int delay);
void backwards(int delay);
void right_turn(int delay);
void left_turn(int delay);

int main()
{
	/* initialize the wiringPi library */
	unsigned int _delay = 1000;
	wiringPiSetup();
	wiringPiSetupGpio();

	// TODO - add running loop
	while(1)
	{
		forward(_delay);
		backwards(_delay);
		right_turn(_delay);
		left_turn(_delay);
	}

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
	digitalWrite(M1_FWD, LOW);
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
void right_turn(int delay)
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
void left_turn(int delay)
{
	digitalWrite(M1_FWD, HIGH);
	digitalWrite(M2_BWD, HIGH);
	delay(_delay);
	digitalWrite(M1_FWD, LOW);
	digitalWrite(M2_BWD, LOW);
}

