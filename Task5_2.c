#include <stdio.h>

union
{
float f;
int i;
}gen;

int main()
{
	scanf("%f",&gen.f);
	unsigned int mantisa  = (gen.i & 0x003fffff);
	unsigned int exp = (gen.i & 0x7f800000) >> 23;
	int sign  = gen.i & 0x100000000;
		if(exp == 0 &&  mantisa == 0) 
	{
			printf("zero");
	}
	else if (sign == 0 &&  exp == 255 && mantisa==0 ) 
	{
		printf(" + infinity ");
	}
	else if (sign == -1 &&  exp == 255 && mantisa==0)
	{
		printf(" - infinity ");
	} 
	else if (exp == 255 && mantisa != 0 )
	{
		printf("NaN");
	}
	else
	{

	printf ("(-1) ^ %d * 2^ %d * %f = %f", sign, exp - 127, 1+ mantisa / (float) (1 << 23), gen.f);
	}
    return 0;
}
