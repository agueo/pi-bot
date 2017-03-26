/*
 * This is a Test that will be used for testing the GPIO pins on the raspberry pi
 * Agueo Lopez
 * 3/25/17
 *
 */
#include <stdio.h>
#include <stdlib.h> 
#include <wiringPi.h>

#define LED 18

int main(int argc, char **argv)
{
	wiringPiSetup(); // Initializes wiringPi using wiringPi's simplified number system
	wiringPiSetupGpio(); // Initializes wiringPi using Broadcom GPIO numbers
	
	/* Pin mode declaration: pinMode([pin],[mode]);
	* with modes being INPUT, OUTPUT, PWM_OUTPUT	*/
	pinMode(LED, OUTPUT);
	unsigned int _delay = 1000;

	while(1){
		/* Digital output: function that can set a desired pin to high or low.
		 * digitalWrite([pin],[HIGH/LOW])				*/
		digitalWrite(LED, HIGH);
		
		/* delay funtion:
		 * delay([milliseconds]);
		 * stops the program for the specified amount of time.*/
		delay(_delay);

		digitalWrite(LED, LOW);
		delay(_delay);
	}

	return 0;
}
