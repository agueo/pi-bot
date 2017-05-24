#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>

#define M1_FWD 23
#define M1_BWD 24
#define M2_FWD 17
#define M2_BWD 27

void forward(int _delay);
void backwards(int _delay);
void right_turn(int _delay);
void left_turn(int _delay);

int main()
{
	/* initialize the wiringPi library */
	unsigned int _delay = 2000;
	char cmd;
	wiringPiSetup();
	wiringPiSetupGpio();
	pinMode(M1_FWD, OUTPUT);
	pinMode(M1_BWD, OUTPUT);
	pinMode(M2_FWD, OUTPUT);
	pinMode(M2_BWD, OUTPUT);

	// TODO - add running loop
	while(1)
	{
		scanf("%c", &cmd);
		switch(cmd){
			case('w'):
				forward(_delay);
				break;
			case('s'):
				backwards(_delay);
				break;
			case('a'):
<<<<<<< HEAD
				left_turn(250);
				break;
			case('d'):
				right_turn(250);
=======
				right_turn(250);
				break;
			case('d'):
				left_turn(250);
>>>>>>> c91dfb957efc87ab9ea30bf5eaa4fa463a3d3d5f
				break;
			case('q'):
				return 0;
			default:
				printf("Not a valid command\n");
				break;
		}
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

