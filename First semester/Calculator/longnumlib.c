/*
Welcome to storage
Realisation of longnum.h
By Sharganov Artem
*/

#include "longnumlib.h"

void long_sum(node *result, node* first_number,node *second_number)
{
	node *first_head = first_number;
	node *second_head = second_number;
	first_number = first_number->next;
	second_number = second_number->next;
	egualize(first_number, second_number);
	int extra = 0;	
	while (first_number && second_number)
	{		
		int k = second_number->val + first_number->val + extra;
		if(k>9)
		{
			lb_push(result,second_number->val + first_number->val + extra -10);
			first_number = first_number->next;
			second_number = second_number->next;
			extra = 1; 
		}
		else
		{
			lb_push(result,second_number->val + first_number->val + extra);
			first_number = first_number->next;
			second_number = second_number->next;	
			extra = 0;
		}			
		if((extra == 1) && (first_number == NULL))		
		{
			lb_push(result, 1);
		}
	}
}

void long_sub(node *result, node* first, node* second)
{
	unsigned int f_lenght = lb_lenght(first);
	unsigned int s_lenght = lb_lenght(second);
	int extra = 0;
	int r_sign = 0; 
	node *first_head = first;
	node *second_head = second;
	node *result_head = result;
	first = first->next;
	second = second->next;
	egualize(first, second);
	while(second)
	{	
		if (f_lenght == 1 && first->val == 0) 
		{
			lb_insert(result, second->val);
			second = second->next;
			result_head->val = 1;
		}
		else
		{
		lb_push(result, (first->val - second->val - extra + 10)%10);
		if(first->val - second->val - extra >= 0)
			extra = 0;
		else 
			extra = 1;
		first = first->next;
		second = second->next;
		}
	}	
	if( extra == 1 ) 
	{
		first = first_head->next;
		second = second_head->next;
		result_head->val = 1;
		delete_num(result);
		extra = 0;
		while (first)
		{
			
			lb_push(result, abs(first->val - second->val + extra - 10)%10);
			if((first->val - second->val) > 0) 
			{
				extra = 1;
			}
			else 
			{
				extra = 0;
			}
			first = first->next;
			second = second->next;
		}
	}
}

void long_mult(node *result, node *first, node *second)
{
	node *first_head = first;
	node *second_head = second;
	first = first->next;
	second = second ->next;	
	node *tmp1 = lb_get_new(0);
	node *tmp1_head = tmp1;
	node *tmp2 = lb_get_new(0);
	node *tmp2_head = tmp2;
	int extra = 0;
	int carry = 0;
	int p = 0;
	int q = 0;
	while(second)
	{
		extra = 0;
		carry = 0;
		while (first)
		{	
			lb_push(tmp2, (first->val*second->val + extra)%10);
			extra = (first->val*second->val + extra)/10;
			first = first->next;
			if((extra > 0) && (first == NULL))		
			{
				lb_push(tmp2, extra);
			}
			
		}
		q = p;
		while(q)
			{
				lb_insert(tmp2, 0);
				q--;
			}
		
		first = first_head->next;
		egualize(tmp1, tmp2);
		
		while (tmp2)
		{
			int q = tmp1->val;
			tmp1->val = (tmp1->val + tmp2->val + carry)%10;
			carry = (q + tmp2->val + carry)/10;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;	  
		}
		tmp2 = tmp2_head;
		delete_num(tmp2);
		tmp1 = tmp1_head;
		p++;
		second = second->next;
	}
	
	tmp1 = tmp1->next;
	while(tmp1)
	{
		lb_push(result, tmp1->val);
		tmp1 = tmp1->next;
	}
	tmp1 = tmp1_head;
	tmp2 = tmp2_head;
	lb_delete(tmp1);
	lb_delete(tmp2);
}

void long_dev(node *result, node *first, node *second)
{
	node *tmp1 = lb_get_new(0);
	node *tmp2 = lb_get_new(0);
	unsigned int f_lenght = lb_lenght(first);;
	unsigned int s_lenght = lb_lenght(second);
	first = lb_reverse(first);
	int res = 0;
	if (f_lenght >= s_lenght)
	{
		while(s_lenght--)
		{
			lb_front_pop(tmp1, first);
		}
		

		while (1)
		{
			if(tmp2->val == 1) lb_front_pop(tmp1, first);
			tmp2->val = 0;
			while(1)
			{
				long_sub(tmp2, tmp1, second);
				if(tmp2->val == 1)
				{
					delete_num(tmp2);
					break;
				}
				copy(tmp1, tmp2);
				delete_num(tmp2);
				res++;
				
			}
			lb_insert(result, res);
			res = 0;
			if(first->next == NULL) break;
		}
	}
	first->next = NULL;
	lb_delete(tmp1);
	lb_delete(tmp2);
}

void delete_num(node *head)
{
	if(head->next)
	{
	lb_delete(head->next);
	head->next = NULL;
	}
}

void ln_delln(node *head)
{
	printf("3");
	head = lb_reverse(head->next);
	while (head->next && head->next->val == 0)
	{
		lb_delete_element(head);	
	}
	printf("2");
	head = lb_reverse(head->next);
}
