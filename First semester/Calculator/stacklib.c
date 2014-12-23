/*
Welcome to Storage
Realisation of stack.h
By Sharganov Artem
*/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "stacklib.h"

void st_push_char(stack *element, char arr[])
{
	node *num = lb_get_new(0);
	lb_proccessing(arr, num);
	stack *last = st_get_last(element);
	stack *tmp  = (stack*) malloc (sizeof stack);
	tmp->next = NULL;
	tmp->longnum = num;
	last->next = tmp;
}

void st_push_ln(stack *element, node *longnum)
{
	stack *last = st_get_last(element);
	stack *tmp  = (stack*) malloc (sizeof stack);
	tmp->next = NULL;
	tmp->longnum = longnum;
	last->next = tmp;
}

void st_push_front(stack *element, node *longnum)
{
	stack *new_el = (stack*)malloc(sizeof stack);
	new_el->longnum = longnum;
	new_el->next = element->next;
	element->next = new_el;
}

void st_print(stack *element)
{
	stack *element_head = element;
	if(element->longnum->val == 1) printf("-");
	while(element)
	{
		element->longnum = lb_reverse(element->longnum);
		lb_print(element->longnum->next);
		element->longnum = lb_reverse(element->longnum);
		element = element->next;
		
	}
	element = element_head;
	element->longnum = lb_reverse(element->longnum);
}

void st_print_head(stack *element)
{
	element = st_get_last(element);
	if(element->longnum->val == 1) printf("-");
	element->longnum = lb_reverse(element->longnum);
	//ln_delln(element->longnum);
	lb_print(element->longnum->next);
	element->longnum = lb_reverse(element->longnum);
}

stack* st_get_last(stack *head) 
{
    if (head == NULL) 
	{
        return NULL;
    }
    while (head->next) 
	{
        head = head->next;
    }
    return head;
}

stack* st_pop(stack* element)
{
	stack* prelast = st_get_prelast(element);
	if(prelast == NULL) 
	{
		printf("Not enough argument");
		return NULL;
	
	}
	stack *tmp = (stack*) malloc(sizeof stack);
	node *head = prelast->next->longnum;
	tmp->longnum = lb_get_new(prelast->next->longnum->val);
	prelast->next->longnum = prelast->next->longnum->next; 
	while(prelast->next->longnum)
	{
		lb_push(tmp->longnum, prelast->next->longnum->val);
		prelast->next->longnum = prelast->next->longnum->next;
	}
	prelast->next->longnum = head;
	st_delete_element(prelast);
	return tmp;
}

stack* st_get_prelast(stack *element)
{
	if(element->next == NULL) return NULL;
	while (element->next->next)
	{
		element = element->next;
	}
	return element;
}

void st_delete_element(stack *element)
{
	stack *tmp = NULL;
	if (element->next)
	{
		tmp = element->next;
		element->next = element->next->next;
	}else 
		printf("there is no element");
	lb_delete(tmp->longnum);
	free(tmp);
}

void st_delete_list(stack* head)
{
	while(head)
	{	
		stack *tmp = head;
		lb_delete(head->longnum);
		head = head->next;
		free(tmp);
	}
}
