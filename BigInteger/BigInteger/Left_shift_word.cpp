#include "stdafx.h"
#include "BigInteger.h"

int Left_shift_word(MBigInt *dst, int n)
{
	int i = 0;
	if (dst->length + n > dst->alloclen)
	{
		int result = 0;
		if ((result = extendMBInt(dst, dst->length + n)) != 1)
			return result;
	}
	for (i = dst->length - 1; i >= 0; i--)
	{
		dst->pBigInt[i + n] = dst->pBigInt[i];
	}
	for (i = 0; i < n; i++)
		dst->pBigInt[i] = 0;
	dst->length += n;
	return 1;
}