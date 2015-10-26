#include "stdafx.h"
#include "BigInteger.h"

int mp_mul_d(MBigInt *mbi, int radix)
{
	int i = 0;
	int res,len = mbi->length;
	MBigInt *dst = new MBigInt;
	initMBInt(dst, mbi->alloclen);
	int result = 0, mark = 0;
	for (i = 0; i < len; i++)
	{
		result = mbi->pBigInt[i] * radix + mark;
		dst->pBigInt[i] = (result & 0xffff);
		mark = result >> 16;
	}
	if (mark != 0)
	{
		if (len == dst->alloclen)
		{
			res=extendMBInt(dst, len + 1);
			if (res == 0)
				return 0;
		}
		dst->pBigInt[i] = mark;
		len = len + 1;
	}
	dst->sign = mbi->sign;
	dst->length = len;
	assignMBInt(mbi, dst);
	deleteMBInt(dst);
	return 1;
}