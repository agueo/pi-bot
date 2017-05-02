#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define M1_FWD
#define M1_BWD
#define M2_FWD
#define M2_BWD

int main()
{
	unsigned int _delay = 1000;
	wiringPiSetup();
	wiringPiSetupGpio();

	return 0;
}
