#include "stdafx.h"
#include "BigInteger.h"

void assignMBInt(MBigInt *src1, MBigInt *src2)
{
	src1->alloclen = src2->alloclen;
	src1->length = src2->length;
	src1->sign = src2->sign;
	un_short *pt = NULL;
	pt = (un_short *)realloc(src1->pBigInt, sizeof(un_short)*src1->alloclen);
	if (pt == NULL)
	{
		cout << "memory reallocate failed" << endl;
		return;
	}
	src1->pBigInt = pt;
	for (int i = 0; i < src1->alloclen; i++)
		src1->pBigInt[i] = src2->pBigInt[i];
	return;
}