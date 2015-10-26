#include "stdafx.h"
#include "BigInteger.h"

int write_radix(MBigInt *a, char *str)
{
	int radix = 10;
	unsigned int result1 = 0, result2 = 0;
	char *p = str;
	un_short mark = 0;
	MBigInt *dst = new MBigInt;
	initMBInt(dst,49);
	assignMBInt(dst, a);

	long len = a->length;
	long i = len - 1;
	if (len == 0)*p++ = char(a->pBigInt[0] + 48);
	while (len)
	{
		len = dst->length;
		if (dst->pBigInt[i]<10)
		{
			mark = dst->pBigInt[i];
			dst->pBigInt[i] = 0;
			--i;
			len--;
			dst->length = len;
			if (dst->length == 0)
			{
				*p++ = (char)(mark + 48);
				goto LAST;
			}
		}
		for (i = len - 1; i >= 0; i--)
		{
			result2 = (mark * 65536 + dst->pBigInt[i] + result1 * 65536) / radix;
			result1 = (mark * 65536 + dst->pBigInt[i] + result1 * 65536) % radix;
			dst->pBigInt[i] = result2;
			mark = 0;

		}
		*p++ = (char)(result1 + 48);
		result1 = 0;
		trimMBInt(dst);
	}
LAST:
	*p = '\0';
	reverse_char(str);
	if (str[0] == (char)48)
		str++;
	if (a->sign == -1)
	{
		for (i = strlen(str); i >= 0; i--)
			str[i] = str[i - 1];
		str[0] = '-';
	}
	return 1;
}
