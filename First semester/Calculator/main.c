#include "Calculator.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{	
	stack *element = (stack*) malloc(sizeof stack);
	element->next = NULL;
	element->longnum = NULL;
	char str[10000];
	while (1)
	{
		scanf("%s", str);
		
	if(str[0] == '+')
		{
		brain(element, 1);
		}
		else if(str[0] == '*')
		{
			brain(element, 3);
		}
		else if(str[0] == '/')
		{
			brain(element, 4);
		}
		else if(str[0] == '-' && (str[1] == '\0'))
		{
			brain(element, 2);
		}
		else if(str[0] == '#') break;
		else if (str[0] == '=') 
		{
			st_print_head(element->next);
		}
		else 
		{
			st_push_char(element, str);
		}
	}
	st_delete_list(element);	
	_CrtDumpMemoryLeaks();
		return 0;
}	
