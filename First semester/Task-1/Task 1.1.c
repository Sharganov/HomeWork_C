/*
Welcome to storage
Перевод в двоичную систему счисления из десятичной

*/


#include <stdio.h>

void trans(int b)

{
   if (b)
   {
       trans(b >> 1);
       int c = 0;
       c = b & 1;
       printf("%d", c);
   }
}

int main()
{
   int a;
   printf("enter");	
   scanf("%d", &a);
   trans(a);

   return 0; 
}


