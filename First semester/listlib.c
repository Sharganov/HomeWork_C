/*
Welcome to Storage
Realisation of listlib.h
By Sharganov Artem
*/
#include "listlib.h"

void lb_insert(node *head,  int val) 
{
	node *tmp = lb_get_new(val);
	if(tmp)
	{
       if (head->next) 
	   {
        tmp->next = head->next;
       } else 
	   {
        tmp->next = NULL;
	   }
	   head->next = tmp;
	}
}

void lb_push(node *head, int number) 
{
	node *last = lb_get_last(head);
	if(last)
	{
		node *tmp = (node*) malloc(sizeof(node));
		tmp->val = number;
		tmp->next = NULL;
		if (last == NULL) 
		{
			last = tmp;

		}
		else 
		{
			last->next = tmp;
		}
	}
}

int lb_lenght(node *head)
{
	int lenght=0;
	while (head) 
	{	
		lenght++;
        head = head->next;
    }
	return lenght - 1;
}

void lb_delete_element(node *head)
{   
	node* tmp = NULL;
	if(head == NULL) return;
	if(head->next)
	{
		tmp = head -> next;
		head->next = head->next->next;
	}
	else printf("there is no this element");
	free(tmp);
 }

node* lb_get_last(node *head) 
{
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void lb_delete(node *head)
{
	if(head == NULL)
	{
		printf("There is not elements!");
		return;
	}
	while(head)
	{
		
	node *tmp = head;
	head = head->next;
	free(tmp);
	}

}

void lb_print(node *head) {
    if(head == NULL) printf("There is not elements!");	
	while (head) 
	{
        printf("%d", head->val);
       	head = head->next;
    }
    printf("\n");
}

void lb_proccessing(char arr[], node *head) 
{
	int i;
	if (arr[0] == '-')
	{
		head->val = 1;
		for (i=1; i < strlen(arr);i++)
			{
				if ((arr[i] -'0')>9 || (arr[i] - '0')< 0)	
				{
					printf("Wrong argument!");
					return;
				}
			lb_insert(head, (int) arr[i] - '0');
			
			}
	}
	else
	{
		for (i=0; i < strlen(arr);i++)
		{
			if ((arr[i] -'0')>9 || (arr[i] - '0')< 0)
				{
					printf("Wrong argument!");
					return;
				}
			lb_insert(head,(int) arr[i]- '0');
		}
	}	
}

void lb_front_pop(node* where_, node *from)
{
	lb_insert(where_, from->next->val);
	lb_delete_element(from);
}

node* lb_get_new(int val)
{
	node * tmp = (node*) malloc(sizeof node);
	if(tmp == NULL) 
	{
		printf("Not enough memory!");
		return NULL;
	}
	tmp->next  = NULL;
	tmp->val = val;
	return tmp;
}

node* lb_reverse(node *num)
{
	node *tmp = lb_get_new(0);
	node *num_head = num;
	num = num->next;
	while (num)
	{
		lb_insert(tmp, num->val);
		num = num->next;
		
	}
	lb_delete(num_head);
	return tmp;
}

void copy(node *where , node *from)
{
	egualize(where, from);
	while(from)
	{
		where->val = from->val;
		where = where->next;
		from = from->next;
	}

}

void egualize(node *first_number, node *second_number)
{
	unsigned int f_lenght = lb_lenght(first_number);
	unsigned int s_lenght = lb_lenght(second_number);
	if(f_lenght > s_lenght)
	{
		
		int k = f_lenght - s_lenght;
		while(k--)
		{
			lb_push(second_number, 0);
		}
	}
	if (f_lenght < s_lenght)
	{
		int k = s_lenght - f_lenght;
		
		while(k--)
		{
			lb_push(first_number, 0);
		}
	}
}
