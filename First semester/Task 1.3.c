/*
Welcome to Storage
Determination of sign (-1 for negative; 0  for "0"; 1 for positive)
By Sharganov Artem
*/


#include <stdio.h>
 
int main(){
	int n ;
	scanf("%d",&n);
	return ( (n>>0x1F) + !((n>>0x1f) + ~( !n + ~0 ) ));
}
 
