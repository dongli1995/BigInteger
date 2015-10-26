
#include "stdafx.h"
#include "BigInteger.h"
int initMBInt(MBigInt *mbi,int size)
{
	int allocSize = INITIAL_BINT;
	while (allocSize < size)
	{
		allocSize += STEP_BINT;
	}
	mbi->pBigInt = (un_short*)malloc(allocSize*sizeof(un_short));
	if (mbi->pBigInt == NULL)
	{
		cout << "memory allocate failed" << endl;
		return 0;
	}
	for (int i = 0; i < allocSize; ++i)
	{
		mbi->pBigInt[i] = 0;
	}
	mbi->length = 0;
	mbi->alloclen = allocSize;
	mbi->sign = 0;
	return 1;
}
