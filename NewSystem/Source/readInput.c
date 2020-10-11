/*
File Name:	readInput.c
//
Compiler:	gcc
Author:		Artic
Description:	Read an input in the pi if one creates file if 0 removes it. That way other programs no the state of the input
Testd on:	Raspberry pi Zero W
*/

/****************************************
*		Include			*
*****************************************/

#include <pigpio.h>
#include <unistd.h>
#include <stdlib.h>

/****************************************
*	Private Function Prtotype	*
****************************************/

int main (void);

#define PIN 21;

/****************************************
*		Code			*
****************************************/

int main (void);
{
	gpioInitialise(void);
	gpioSetMode(PIN, PI_INPUT); 
	gpioSetPullUpDown(PIN, PI_PUD_DOWN);

	while (1)
	{
		if (gpioRead(PIN))	{ system ("touch /tmp/GPIO21/SIGNAL"); }
		else				{ system ("rm /tmp/GPIO21/SIGNAL"); }
		sleep (1);
	}
