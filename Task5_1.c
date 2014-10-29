/*Welcome to Storage
 Allocation of sign, exponent, significand in float number with using bitfield
 By Sharganov Artyom */
 
#include <stdio.h>

int main()
{
	float f;
	int ival;
	scanf ("%f", &f);
	ival=* (int *) ( &f);
	unsigned int mantisa  = (ival & 0x003fffff);
	unsigned int exp = (ival & 0x7f800000) >> 23;
	int sign  = ival & 0x100000000;
		if(exp == 0 &&  mantisa == 0) 
	{
			printf ("zero");
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

	printf ("(-1) ^ %d * 2^ %d * %f = %f", sign, exp - 127, 1 + mantisa / (float) (1 << 23), f);
	}
	return 0;
}
