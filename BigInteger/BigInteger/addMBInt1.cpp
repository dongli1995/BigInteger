#include "stdafx.h"
#include "BigInteger.h"

int addMBInt1(MBigInt * dst, MBigInt *src1, MBigInt *src2)
{
	int len = 0;
	int dstlen = 0;
	int i = 0;
	un_short mark = 0;
	unsigned int result;
	int sign = src1->sign;
	dstlen = (src1->length >= src2->length) ? src1->length : src2->length;
	if (0 == extendMBInt(dst, dstlen+1))
		return 0;
	len = (src1->length > src2->length) ? src2->length : src1->length;
	for (i = 0; i < len; i++)
	{
		result = src1->pBigInt[i] + src2->pBigInt[i] + mark;
		dst->pBigInt[i] = (result & 0xffff);
		mark = result >> 16;
	}
	if (src1->length>src2->length)
	{
		while (i < src1->length)
		{
			result = src1->pBigInt[i] = mark;
			dst->pBigInt[i] = (result & 0xffff);
			mark = result >> 16;
			i++;
		}
		if (mark != 0)
		{
			dst->pBigInt[i] = mark;
			dstlen = src1->length + 1;
		}
	}
	else
	{
		while (i < src2->length)
		{
			result = src2->pBigInt[i] + mark;
			dst->pBigInt[i] = (result & 0xffff);
			mark = result >> 16;
			i++;
		}
		if (mark != 0)
		{
			dst->pBigInt[i] = mark;
			dstlen = src2->length + 1;
		}
	}
	dst->sign = sign;
	dst->length = dstlen;
	return 1;
}