/*
Welcome to Storage
To find substring in string
By Sharganov Artem
*/

#include <stdio.h>
#include <string.h>

int main() 
{
	char str[1000];
	char sub_str[1000];
	int str_len = 0;
	int sub_len = 0;
	int p = 1;
	int counter = 0;
	int i,j;
	scanf("%s", str);
	scanf("%s", substr);
	str_len = strlen(str);
	sub_len = strlen(sub_str);
	for ( i = 0; i <= str_len - sub_len; i++)
    	{ 
		p = 1;
		for (j = 0; j < sub_len; j++ )
		{  
			if (str[i+j] != sub_str[j])
                	{   
				 p = 0;
                		 break;
                	}
        	 }
            if (p) counter++;
        }
    printf("%d\n", counter);
    return (0);
}
