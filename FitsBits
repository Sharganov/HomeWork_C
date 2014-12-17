/*
Welcome  to storage
FitsBits
By Sharganov Artem

*/


#include <stdio.h>

int main()
{
	int n, w;
	scanf("%d %d", &n, &w);
	int t = sizeof(int) * 8 + 1 + ~w; 
	int res = ! (((n << t) >>t) ^ n); 
	printf("%d", res);
	return 0;
}
