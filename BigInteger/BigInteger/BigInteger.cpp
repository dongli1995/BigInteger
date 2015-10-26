// BigInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigInteger.h"

void main()
{
	char str;
	char *str1= new char;
	char *str2 = new char;;
	char *outstr = new char;;
	char *outstr2 = new char;;
	int init_size = INITIAL_BINT;
	MBigInt *src1 = new MBigInt;
	MBigInt *src2 = new MBigInt;
	MBigInt *dst1 = new MBigInt;
	MBigInt *dst2 = new MBigInt;
	initMBInt(src1,init_size);
	initMBInt(src2, init_size);
	initMBInt(dst1, init_size);
	initMBInt(dst2, init_size);
	cin >> str;
	cin >> str1;
	cin >> str2;
	read_radix(src1, str1);
	read_radix(src2, str2);

	if (str == '+')
	{
		addMBInt1(dst1, src1, src2);
		write_radix(dst1, outstr);
		if (outstr[0] == (char)48)
			outstr++;
		cout << outstr << endl;
		return;
	}
	else if (str == '-')
	{
		addMBInt2(dst1, src1, src2);
		write_radix(dst1, outstr);
		if (outstr[0] == (char)48)
			outstr++;
		cout << outstr << endl;
		return;
	}
	else if (str == '*')
	{
		mulBasicMBInt(dst1, src1, src2);
		write_radix(dst1, outstr);
		if (outstr[0] == (char)48)
			outstr++;
		cout << outstr << endl;
		return;
	}
	else if (str == '/')
	{
		divMBInt(dst1, dst2,src1, src2);
		write_radix(dst1, outstr);
		write_radix(dst2, outstr2);
		if (outstr[0] == (char)48)
			outstr++;
		if (outstr2[0] == (char)48)
			outstr2++;
		cout << outstr << endl;
		cout << outstr2 << endl;
		return;
	}
	return;
}
