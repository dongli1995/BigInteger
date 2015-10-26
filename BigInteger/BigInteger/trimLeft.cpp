#include "stdafx.h"
#include "BigInteger.h"

void trimLeft(char *str)
{
	int i = 0, j = 0;
	if (strlen(str) == 1 && str[0] == '0')
	{
		return;
	}
	for (i = 0; i < strlen(str) && str[i] == '0'; i++);
	memcpy(str, str + i, strlen(str) - i);
	str[strlen(str) - i] = '\0';
	return;
}