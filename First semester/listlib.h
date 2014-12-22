/*
Welcome to Storage
Library for linked list
By Sharganov Artem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} node;

void lb_push(node *head, int number);
void lb_delete(node *head);
void lb_delete_element(node *head);
node* lb_get_last(node *head);
void lb_insert(node *head,  int val);
int lb_lenght(node *head);
void lb_print(node *head);
void  lb_proccessing(char[], node *head);
node* lb_reverse(node *num);
void lb_front_pop(node* where_, node *from);
void egualize(node *first_number, node *second_number);
node* lb_get_new(int val);
void copy(node *where , node *from);
