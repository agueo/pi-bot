/*
 * This is a Test that will be used for testing the GPIO pins on the raspberry pi
 * Agueo Lopez
 * 3/25/17
 *
 */
#include <stdio.h>
#include <stdlib.h> 
#include <wiringPi.h>

#define LED RPI_V2_GPIO_P1_12

int main(int argc, char **argv)
{
	wiringPiSetup(); // Initializes wiringPi using wiringPi's simplified number system
	wiringPiSetupGpio(); // Initializes wiringPi using Broadcom GPIO numbers
	
	/* Pin mode declaration: pinMode([pin],[mode]);
	* with modes being INPUT, OUTPUT, PWM_OUTPUT	*/
	pinMode(18, OUTPUT);
	unsigned int _delay = 1000;

	while(1){
		/* Digital output: function that can set a desired pin to high or low.
		 * digitalWrite([pin],[HIGH/LOW])				*/
		digitalWrite(18, HIGH);
		
		/* delay funtion:
		 * delay([milliseconds]);
		 * stops the program for the specified amount of time.*/
		delay(_delay);

		digitalWrite(18, LOW);
		delay(_delay);
	}

	return 0;
}
