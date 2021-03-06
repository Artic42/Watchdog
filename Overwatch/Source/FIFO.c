/****************************************************
*						FIFO						*
****************************************************/
#include <stdlib.h>
#include "FIFO.h"
/****************************************************
*					Structures						*
****************************************************/

#define Create_Item() malloc(sizeof(struct FIFO_Item))

/****************************************************
*					Structures						*
****************************************************/

struct FIFO_Item {
	int Message_Code;
	struct FIFO_Item *Nxt;
	struct FIFO_Item *Prv;
};

/****************************************************
*					Private Variables				*
****************************************************/

struct FIFO_Item *FIFO_Head;
struct FIFO_Item *FIFO_Tail;
int FIFO_Nr_of_Item=0;

/****************************************************
*			Private Function Prototype				*
****************************************************/

void Remove_Item (struct FIFO_Item *Item);
void Add_Item_Empty_FIFO (struct FIFO_Item *Item);
void Add_Item_Tail_FIFO (struct FIFO_Item *Item);


/****************************************************
*				Functions							*
****************************************************/

void FIFO_Add_Item (int Code)
{
	struct FIFO_Item *Item;
	
	//Allocate memory for Item and save the ponter to it in Item
	Item = Create_Item();
	//Save code in the new item
	Item->Message_Code = Code;

	if (FIFO_Nr_of_Item == 0) 	{ Add_Item_Empty_FIFO(Item); }
	else						{ Add_Item_Tail_FIFO(Item); }

	FIFO_Nr_of_Item++;
}

int FIFO_Read_Item (void)
{
	int Result;
	//Sve result to return later
	Result = FIFO_Head->Message_Code;
	//Remove element for FIFO and replace new HEAD
	Remove_Item (FIFO_Head);
	return Result;
}

void Wipe_FIFO (void)
{
	FIFO_Tail = 0;
	while (FIFO_Head != 0)
	{
		Remove_Item (FIFO_Head);
	}
	FIFO_Nr_of_Item = 0;
}

int FIFO_Size (void)
{
	return FIFO_Nr_of_Item;
}

void Remove_Item (struct FIFO_Item *Item)
{
	struct FIFO_Item *Item_To_Delete;
	Item_To_Delete = FIFO_Head;
	FIFO_Head = FIFO_Head->Nxt;
	free (Item_To_Delete);
}

void Add_Item_Empty_FIFO (struct FIFO_Item *Item)
{
	FIFO_Head = Item;
	FIFO_Tail = Item;
}

void Add_Item_Tail_FIFO (struct FIFO_Item *Item)
{
	FIFO_Tail->Nxt = Item;
	Item->Prv = FIFO_Tail;
	FIFO_Tail = Item;
}
