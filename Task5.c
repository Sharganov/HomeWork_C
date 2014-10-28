/*Welcome to Storage
 Allocation of sign, exponent, significand in float number with using bitfield
 By Sharganov Artyom */

#include <stdio.h>
union 
{
	struct 
	{
	int mant: 23;
	unsigned int exp: 8;
	int sign: 1;
	} BitField;
	float f;
} str;

int main() 
{	
	scanf("%f",&str.f);
	if(str.BitField.exp == 0 && str.BitField.mant == 0) 
	{
			printf("zero");
	}
	else if (str.BitField.sign == 0 &&  str.BitField.exp == 255 && str.BitField.mant==0 ) 
	{
		printf(" + infinity ");
	}
	else if (str.BitField.sign == -1 &&  str.BitField.exp == 255 && str.BitField.mant==0)
	{
		printf(" - infinity ");
	} 
	else if (str.BitField.exp == 255 && str.BitField.mant != 0 )
	{
		printf("NuN");
	}
	else
	{
	printf ("(-1) ^ %d * 2^ %d * %f = %f", str.BitField.sign, str.BitField.exp - 127, 1+ str.BitField.mant / (float) (1 << 23), str.f);
	}
	return 0;
}
