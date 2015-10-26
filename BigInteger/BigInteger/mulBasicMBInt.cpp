#include "stdafx.h"
#include "BigInteger.h"

int mulBasicMBInt(MBigInt *product, MBigInt *biA, MBigInt *biB)
{
	MBigInt biT;
	unsigned int carry = 0;
	register un_short *pWordA = biA->pBigInt;
	register un_short *pWordB = biB->pBigInt;
	register un_short *pPrd = NULL;
	int result = 0, i = 0, j = 0;
	if ((result = initMBInt(&biT, biA->length + biB->length)) != 1)
		return result;
	biT.length = biA->length + biB->length;
	biT.sign = 1;
	pPrd = biT.pBigInt;
	for (i = 0; i < biA->length; ++i)
	{
		carry = 0;
		for (j = 0; j < biB->length; ++j)
		{
			pPrd[i + j] = (un_short)(carry = (unsigned int)pPrd[i + j] + (unsigned int)pWordA[i] * (unsigned int)pWordB[j] + (unsigned int)(un_short)(carry >> 16));
		}
		pPrd[i + j] += (un_short)(carry >> 16);
	}
	trimMBInt(&biT);
	assignMBInt(product, &biT);
	deleteMBInt(&biT);
	return 1;
}