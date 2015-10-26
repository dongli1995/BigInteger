#include "stdafx.h"
#include "BigInteger.h"

int addMBInt2(MBigInt *dst, MBigInt *src1, MBigInt *src2)
{
	int len = 0, len1 = 0;
	int dstlen = dst->alloclen;
	un_short mark = 0;
	int result = 0;
	int sign = 0;
	int i = 0;

	len = (src1->length > src2->length) ? src1->length : src2->length;
	len1 = (src1->length > src2->length) ? src2->length : src1->length;
	un_short *psrc1 = src1->pBigInt, *psrc2 = src2->pBigInt, *pdst = NULL;
	if (extendMBInt(dst, len) == 0)
		return 0;
	int re = compareMBInt(src1, src2);
	if (re == 0)
	{
		dst->length = 0;
		dst->sign = 0;
		return 1;
	}
	else if (re == -1)
	{
		sign = -1;
		psrc1 = src2->pBigInt;
		psrc2 = src1->pBigInt;
		len1 = src1->length;
	}
	for (i = 0; i < len1; i++)
	{
		if ((result = psrc1[i] - psrc2[i] - mark) < 0)
			mark = 1;
		else
			mark = 0;
		if (mark == 1)
			result += 65536;
		dst->pBigInt[i] = result;
	}
	while (i < len)
	{
		result = psrc1[i] - mark; 
		if (result >= 0)
		{
			dst->pBigInt[i++] = result;
			mark = 0;
		}
		else
		{
			dst->pBigInt[i++] = result + 65536;
		}
	}
	dst->length = len;
	dst->sign = sign;
	trimMBInt(dst);
	return 1;
}