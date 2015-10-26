#include "stdafx.h"
#include "BigInteger.h"
#include <iostream>

void deleteMBInt(MBigInt *mbi)
{
	if (mbi->pBigInt != NULL)
	{
		for (int i = 0; i < mbi->length; ++i)
		{
			mbi->pBigInt[i] = 0;
		}
		free(mbi->pBigInt);
		mbi->pBigInt = NULL;
		mbi->length = 0;
		mbi->alloclen = 0;
		mbi->sign = 1;
	}
}