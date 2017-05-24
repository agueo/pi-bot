/* Pi-Bot - program to run a small rc car created with a raspbery pi 2
 * Agueo Lopez
 */
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define M1_FWD 23
#define M1_BWD 24
#define M2_FWD 17
#define M2_BWD 27
#define TRIG 5
#define ECHO 6

int main()
{
	/* initialize the wiringPi library */
	wiringPiSetup();
	wiringPiSetupGpio();
	pinMode(M1_FWD, OUTPUT);
	pinMode(M1_BWD, OUTPUT);
	pinMode(M2_FWD, OUTPUT);
	pinMode(M2_BWD, OUTPUT);
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	digitalWrite(M1_FWD, LOW);
	digitalWrite(M1_BWD, LOW);
	digitalWrite(M2_FWD, LOW);
	digitalWrite(M2_BWD, LOW);

	printf("Resetting motors.\n");

	return 0;
}
