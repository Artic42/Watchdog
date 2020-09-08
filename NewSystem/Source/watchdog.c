/*
File Name:	watchdog.c
//
Compiler:	gcc
Author:		Artic42
Description:	This is the main program for Watchdog, Watchdog is a program for a raspberry pi that send an email to the user when electricity goes out. It requieres some Hardware check documentation
Testd on:	Raspberry Pi Zero W 2020
*/

/****************************************
*		Include			*
*****************************************/

#include <unistd.h>
#include <stdlib.h>
#include <bcm2835.h>

/****************************************
*	Private Function Prtotype	*
****************************************/

char determineSignalEdge (char Signal);
char readSignal (void);
void configureInput (void);

/****************************************
*	Private Definitions		*
****************************************/



/****************************************
*	Private Global Variables	*
****************************************/



/****************************************
*	Private Constants		*
****************************************/

#define NOCHANGE 0
#define RAISING 1
#define FALLING 2

#define INPUT RPI_V2_GPIO_P1_40


/****************************************
*		Code			*
****************************************/

char readSignal ()
{
	if (access("SIGNAL", F_OK) == 0)	{ return 1; }
	else								{ return 0; }
}

void configureInput (void)
{
	;
}

char determineSignalEdge (char signal)
{
	static char prvValue;
	char result = NOCHANGE;

	if (prvValue == 0 && signal == 1)	{ result = RAISING; }
	if (prvValue == 1 && signal == 0)	{ result = FALLING; }
	prvValue = signal;

	return result;
}

int main (void)
{
	char Edge;

	determineSignalEdge (readSignal());

	while (1)
	{
		sleep (10);
		Edge = determineSignalEdge (readSignal());
		if (Edge == RAISING) { system ("python /home/artic/.bin/python/send-email.py emails/LightsBack.email"); }
		if (Edge == FALLING) { system ("python /home/artic/.bin/python/send-email.py emails/LightsOut.email"); }
	}
	return 0;
}
	
