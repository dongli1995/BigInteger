#include "stdafx.h"
#include "BigInteger.h"

int compareMBInt(MBigInt *a, MBigInt *b)
{
	int i = 0;
	if (a->length > b->length)
		return 1;
	else if (a->length == b->length)
	{
		for (i = (a->length - 1); i >= 0; --i)
		{
			if (a->pBigInt[i] > b->pBigInt[i])
				return 1;
			else if (a->pBigInt[i] < b->pBigInt[i])
				return -1;
			else
				continue;
		}
		if (i < 0)
			return 0;
	}
	else
		return -1;
}