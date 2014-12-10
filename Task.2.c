/*
Welcome to storage
Involution
By Sharganov Atrem
*/

#include <stdio.h>
int binpow (int, int);
int main()
{
	int c = 0, d = 0;
	scanf("%d%d", &c, &d);
	int k = 0;
	k = binpow(c, d);
	printf("%d", k);
	return 0;
}
int binpow (int a, int n)
 {
	int res = 1;
	while (n)
	{
		if (n & 1)
 		{
			res *= a;
			--n;
		}
		else  
		{
			a *= a;
			n =n>> 1;
		}
	}
return res;
}
