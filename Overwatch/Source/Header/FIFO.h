/****************************************************
*						FIFO						*
****************************************************/


/****************************************************
*				Global Function Prototype			*
****************************************************/

void FIFO_Add_Item (int Code);
int FIFO_Read_Item (void);
void FIFO_Wipe (void);
int FIFO_Size (void);

/****************************************************
*					Structure						*
****************************************************/

struct FIFO_Item {
	int Message_Code;
	*FIFO_Item Nxt;
	*FIFO_Item Prv;
}

/****************************************************
*					Private Variables				*
****************************************************/

*FIFO_Item FIFO_Head;
*FIFO_Item FIFO_Tail;
int FIFO_Nr_of_Item;

/****************************************************
*			Private Function Prototype				*
****************************************************/

private void Add_Item_Empty_FIFO (*FIFO_Item Item);
private void Add_Item_Tail_FIFO (*FIFO_Item Item);

