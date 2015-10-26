#include "stdafx.h"
#include "BigInteger.h"

void setZeroMBInt(MBigInt *mbi)
{
	int i = 0;
	for (i = 0; i < mbi->length; ++i)
	{
		mbi->pBigInt[i] = 0;
	}
	mbi->length = 0;
	mbi->sign = 1;
}