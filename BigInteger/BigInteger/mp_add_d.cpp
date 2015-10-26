#include "stdafx.h"
#include "BigInteger.h"

int mp_add_d(MBigInt *mbi, int y)
{
	int i = 0;
	int res, len = mbi->length;
	int result = 0, mark = 0;
	result = mbi->pBigInt[0] + y;
	mbi->pBigInt[0] = (result & 0xffff);
	mark = result >> 16;
	i++;
	while ((mark != 0)&&(i<len))
	{
		result = mbi->pBigInt[i] + mark;
		mbi->pBigInt[i] = (result & 0xffff);
		mark = result >> 16;
		i++;
	}
	if (mark != 0)
	{
		if (len == mbi->alloclen)
		{
			res = extendMBInt(mbi, len + 1);
			if (res == 0)
				return 0;
		}
		mbi->pBigInt[i] = mark;
		mbi->length = mbi->length + 1;
	}
	return 1;
}