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

/****************************************
*	Private Function Prtotype	*
****************************************/

char determineSignalEdge (char Signal);
char readSignal (void);

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

#define SIGNAL_PATH "/tmp/GPIO21/SIGNAL"

/****************************************
*		Code			*
****************************************/

char readSignal ()
{
	if (access(SIGNAL_PATH, F_OK) == 0)	{ return 1; }
	else								{ return 0; }
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
		sleep (60);
		Edge = determineSignalEdge (readSignal());
		if (Edge == RAISING) { system ("python ~/.bin/python/send-email.py emails/LightsBack.email"); }
		if (Edge == FALLING) { system ("python ~/.bin/python/send-email.py emails/LightsOut.email"); }
	}
	return 0;
}
	
