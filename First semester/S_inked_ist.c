/*
Welcome to Storage

Реализация простейшего односвязного списка:
a - добавить элемент
r - удалить элемент
p - напечатать список
q - безопасный выход

By Sharganov Artem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    int val;
    struct node *next;
} node;


node* look_through(node *head,int number)
{
	
	while (head->next->val !=  number && head->next)
	{
		head = head->next;
	
	}
	return head;
}


void delete_element(node *head)
{
	node* tmp = head -> next;
	head->next = head->next->next;
	free(tmp);
 }

node* get_by_muber(node* head, int n) 
{
    int limit = 0;
    while (limit < n && head) {
        head = head->next;
        limit++;
    }
    return head;
}

node* get_last(node *head) 
{
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void delete_list(node *head)

{
	while(head->next)
	{
	node *tmp = head;
	head = head->next;
	free(tmp);
	}

}
void print_list(const node *head) {
    if(head == NULL) printf("There are not elements");
	while (head) {		
        printf("%d ", head->val);
        head = head->next;
    } 
	
    printf("\n");
}

void push(node *head, int number) 
{
	node *last = get_last(head);
    node *tmp = (node*) malloc(sizeof(node));
    tmp->val = number;
    tmp->next = NULL;
	if (last == NULL)
	{
    last = tmp;
	}else
	{
	last->next = tmp;
	}
}


int main()
{
	node *head = (node *)malloc(sizeof node);
	head ->next = NULL;
	int arg;
	char str[10];
	char str3[10]="q";
	char str_check1[10]="a";
	char str_check2[10]="p";
	char str_delete[10]="r";
	while (1)
	{
		scanf("%s",str);
		if (!strcmp(str3,str)) break;
		if (!strcmp(str,str_check1))
		{
			scanf("%d", &arg);
			push(head,arg);
		}
		else if(!strcmp(str,str_delete))
		{
			scanf("%d",&arg);
			delete_element(look_through(head, arg));
		}else if (!strcmp(str, str_check2))
		{
		print_list(head->next);
		}
		else printf("Wrong command!!!");
		
	}
	delete_list(head);
return 0;
}
