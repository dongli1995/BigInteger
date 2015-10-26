#include "stdafx.h"
#include "BigInteger.h"
#include <string>

void reverse_char(char *str)
{
	int len = strlen(str);
	char temp;
	for (int i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return;
}