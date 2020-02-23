/************************************************************
						Overwatch							*
************************************************************/
int main (void);

#include <stdio.h>
#include "FIFO.h"

int main (void)
{
	int Codes[6] = {1,2,3,4,5,6};
 	for (int i = 0; i<=5 ; i++)
	{
		FIFO_Add_Item (Codes[i]);
	}
 	for (int i = 0; i<=5 ; i++)
	{
		int Result = FIFO_Read_Item();
		printf ("%d\n",Result);
	}
	return 0;
}

