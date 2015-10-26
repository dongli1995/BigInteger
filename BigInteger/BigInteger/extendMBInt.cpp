#include "stdafx.h"
#include "BigInteger.h"

int extendMBInt(MBigInt *mbi, int size)
{
	if (mbi->alloclen < size)
	{
		int i = 0;
		un_short *pt = NULL;
		int newAlloc = mbi->alloclen;
		while (newAlloc < size)
		{
			newAlloc += STEP_BINT;
		}
		pt = (un_short *)realloc(mbi->pBigInt, sizeof(un_short)*newAlloc);
		if (pt == NULL)
		{
			cout << "memory reallocate failed" << endl;
			return 0;
		}
		mbi->pBigInt = pt;
		for (i = mbi->alloclen; i < newAlloc; ++i)
		{
			mbi->pBigInt[i] = 0;
		}
		mbi->alloclen = newAlloc;
	}
	return 1;
}