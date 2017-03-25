/*
 * This is a Test that will be used for testing the GPIO pins on the raspberry pi
 * Agueo Lopez
 * 3/25/17
 *
 */
#include <stdio.h>
#include <stdlib.h> 
#include <bcm2835.h>

#define LED RPI_V2_GPIO_P1_12

int main(int argc, char **argv)
{
	if(!bcm2835_init()) return 1;
	bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);		/* Sets LED to output */
	unsigned int delay = 1000;

	/* While loop that will turn on the LED, turn it off */
	while(1){
		bcm2835_gpio_set(12);	/* Sets LED GPIO pin to on */
		printf("Turned on LED\n");
		bcm2835_delay(delay);	/* Waits one second before continuing */
		bcm2835_gpio_clr(LED);	/* Sets LED GPIO pin to off */
		printf("Turned off LED\n");
		bcm2835_delay(delay);
	}
	return 0;
}
