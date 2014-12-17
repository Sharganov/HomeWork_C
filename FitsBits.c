/*
Welcome  to storage
FitsBits
By Sharganov Artem

*/

#include <stdio.h>

int FitBits(int x, int n)
{
   return !((x >> (n - 1)) + (!!(x >> (n-1))));

}


int main()
{
    int x, n;
    scanf("%d", &x);
    scanf("%d", &n);
    printf("%d", fitBits(x, n));
    return 0;
}
