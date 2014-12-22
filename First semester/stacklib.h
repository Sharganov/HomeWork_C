/*
Welcome to Storage
Library for stack struct
By Sharganov Artem
*/

#include "longnumlib.h"

typedef struct stack
{
	node* longnum;
	struct stack *next;
}stack;

void st_print(stack *element);
void st_push(stack *element, char arr[]);
void st_push_front(stack *element, node *longnum);
stack* st_get_last(stack *head);
stack* st_get_prelast(stack *element);
void st_delete_element(stack *element);
void st_delete_list(stack* head);
stack* st_pop(stack* element);
