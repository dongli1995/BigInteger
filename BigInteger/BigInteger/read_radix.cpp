#include "stdafx.h"
#include "BigInteger.h"

int read_radix(MBigInt *a, const char *str)
{
	int radix = 10;
	int y, res = 0, neg=1;
	y = *str - 48;
	a->pBigInt[0] = y;
	a->length = 1;
	str++;
	while (*str != '\0')
	{
		y = *str - 48;
		if (y < radix)
		{
			if ((res = mp_mul_d(a, radix)) != 1)
				return res;
			if ((res = mp_add_d(a, y)) != 1)
				return res;
		}
		else
			break;
		++str;
	}
	a->sign = neg;
	trimMBInt(a);
	return 1;
}