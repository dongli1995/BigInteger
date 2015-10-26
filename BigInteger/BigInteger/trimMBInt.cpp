#include "stdafx.h"
#include "BigInteger.h"

int trimMBInt(MBigInt *mbi)
{
	int length = mbi->alloclen;
	for (int i = mbi->alloclen - 1; i >= 0; i--)
	{
		if (mbi->pBigInt[i] != 0) break;
		length--;
	}
	mbi->length = length;
	return length;
}
