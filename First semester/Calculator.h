/*
Welcome to Storage 
Library for calculator
Possible operations: '+', '-', '*', '/'
By Sharganov Artem
*/

#include "stacklib.h"

void brain(stack *element, int k)
{
	node *result = lb_get_new(0);
	stack* num1 = st_pop(element);
	if(num1 == NULL) return;
	num1->next = NULL;
	stack* num2 = st_pop(element);
	if(num2 == NULL) return;
	num2->next = NULL;
	if(k == 1)
	{
		if(num1->longnum->val == num2->longnum->val)
		{
			long_sum(result, num1->longnum, num2->longnum);
			result->val = num1->longnum->val;
		}
		else if(num1->longnum->val == 0)
		{
			long_sub(result, num1->longnum, num2->longnum);
		
		}
		else if(num1->longnum->val == 1)
		{
			long_sub(result, num2->longnum, num1->longnum);		
		}
	}
	else if (k == 2)
	{
		if(num1->longnum->val == num2->longnum->val == 0)
		{
			long_sub(result, num2->longnum, num1->longnum);
		}
		else if(num1->longnum->val == num2->longnum->val == 1)
		{
			long_sub(result, num1->longnum, num2->longnum);		
		}
		else if(num1->longnum->val == 0)
		{
			result->val = 1;
			long_sum(result, num1->longnum, num2->longnum);
		}
		else if(num1->longnum->val == 1)
		{
			result->val = 0;		
			long_sum(result,num1->longnum, num2->longnum);
		}
	}
	else if(k == 3)
	{
		if(num2->longnum->val == num2->longnum->val) result->val = 0;
		else result->val = 1;
		long_mult(result, num2->longnum, num1->longnum);
	}
	else if(k == 4)
	{
		long_dev(result, num2->longnum, num1->longnum);
		
	}	
	st_push_front(element, result);
	//st_delete_list(num1);
	//st_delete_list(num2);

}
