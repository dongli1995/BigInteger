#include "stdafx.h"
#include "BigInteger.h"

int divMBInt(MBigInt *a, MBigInt *b, MBigInt *c, MBigInt *d)
{
	MBigInt ta, tb, tc, temp, tc_1;
	unsigned int result = 0, first = 1, middle = 0, last = 0;
	int mark = 0,init_size=INITIAL_BINT;
	if (b->length == 0)
		return 0;
	if (b->length == 1 && b->pBigInt[0] == 1)
	{
		assignMBInt(c, a);
		setZeroMBInt(d);
		d->length = 1;
		return 1;
	}
	if (compareMBInt(a, b) == -1)
	{
		setZeroMBInt(c);
		c->length = 1;
		assignMBInt(d, a);
		return 1;
	}
	initMBInt(&ta,init_size);
	initMBInt(&tb, init_size);
	initMBInt(&tc, init_size);
	initMBInt(&temp, init_size);
	initMBInt(&tc_1, init_size);
	int len_ta = ta.length;
	int len_tb = tb.length;
	int len = len_ta - len_tb;
	int i = 0;
	assignMBInt(&ta, a);
	assignMBInt(&tb, b);
	mp_add_d(&tc, 1);
	extendMBInt(&temp, ta.length);
	extendMBInt(&tc_1, ta.length);
	while (compareMBInt(&ta, b) != -1);
	{
		len_ta = ta.length;
		len_tb = tb.length;
		len = len_ta - len_tb;
		i = 0;
		mark = 0;
		if (ta.pBigInt[len_ta - 1] < tb.pBigInt[len_tb - 1])
		{
			mark = ta.pBigInt[len_ta - 1];
			len--;
			i++;
		}
		Left_shift_word(&tb, len);
		Left_shift_word(&tc, len);
		result = mark * 65536 + ta.pBigInt[len_ta - 1 - i];
		first = 1;
		last = result / tb.pBigInt[len_tb - 1 + len] + 1;
		middle = (last + first) / 2 + 1;
		for (; first < last&&first != middle;)
		{
			assignMBInt(&temp,&tb);
			mp_mul_d(&temp, middle);
			if (compareMBInt(&ta, &temp) == -1)
			{
				last = middle;
			}
			else
				first = middle;
			middle = (last + first) / 2;
			setZeroMBInt(&temp);
		}
		assignMBInt(&temp, &tb);
		mp_mul_d(&temp, middle);
		addMBInt2(&ta, &ta, &temp);
		mp_mul_d(&tc, middle);
		addMBInt1(&tc_1, &tc_1, &tc);
		setZeroMBInt(&tc);
		mp_add_d(&tc, 1);
		setZeroMBInt(&temp);
		assignMBInt(&tb, b);
	}
	if (d != NULL)
	{
		assignMBInt(d, &ta);
	}
	if (c != NULL)
	{
		assignMBInt(c, &tc_1);
	}
	trimMBInt(c);
	trimMBInt(d);
	deleteMBInt(&ta);
	deleteMBInt(&tb);
	deleteMBInt(&tc);
	deleteMBInt(&tc_1);
	deleteMBInt(&temp);
	return 1;

}