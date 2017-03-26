/* Counter -- will blink LED's using a binary counter	*/
/* Agueo Lopez											*/
/* 3/26/17												*/

#include <wiringPi.h>

#define GPIO_14 14
#define GPIO_15 15
#define GPIO_18 18

int main(int argc, char ** argv)
{
	/* initialize the wiringPi library	*/
	wiringPiSetup();
	wiringPiSetupGpio();

	pinMode(GPIO_14, OUTPUT);
	pinMode(GPIO_15, OUTPUT);
	pinMode(GPIO_18, OUTPUT);

	unsigned int _delay = 1000;
	int counter = 0;

	while(1){
		counter = 0;
		for(; counter < 8; counter++){
			switch(counter){
				case 0:
					digitalWrite(GPIO_18, LOW);
					digitalWrite(GPIO_15, LOW);
					digitalWrite(GPIO_14, LOW);
					break;
				case 1:
					digitalWrite(GPIO_18, LOW);
					digitalWrite(GPIO_15, LOW);
					digitalWrite(GPIO_14, HIGH);
					break;
				case 2:
					digitalWrite(GPIO_18, LOW);
					digitalWrite(GPIO_15, HIGH);
					digitalWrite(GPIO_14, LOW);
					break;
				case 3:
					digitalWrite(GPIO_18, LOW);
					digitalWrite(GPIO_15, HIGH);
					digitalWrite(GPIO_14, HIGH);
					break;
				case 4:
					digitalWrite(GPIO_18, HIGH);
					digitalWrite(GPIO_15, LOW);
					digitalWrite(GPIO_14, LOW);
					break;
				case 5:
					digitalWrite(GPIO_18, HIGH);
					digitalWrite(GPIO_15, LOW);
					digitalWrite(GPIO_14, HIGH);
					break;
				case 6:
					digitalWrite(GPIO_18, HIGH);
					digitalWrite(GPIO_15, HIGH);
					digitalWrite(GPIO_14, LOW);
					break;
				case 7:	
					digitalWrite(GPIO_18, HIGH);
					digitalWrite(GPIO_15, HIGH);
					digitalWrite(GPIO_14, HIGH);
					break;
				default:
					digitalWrite(GPIO_18, LOW);
					digitalWrite(GPIO_15, LOW);
					digitalWrite(GPIO_14, LOW);
					break;
			}
			delay(_delay);
		}
	}
	return 0;
}
