#include "stdafx.h"
#include "BigInteger.h"

void main()
{
	char ch;
	string s1, s2, res;
	cin >> ch >> s1 >> s2;
	switch (ch){
	case'+':
	{
			   res = ADD_INT(s1, s2);
			   cout << res << endl;
			   break;
	}
	case'-':
	{
			   res = SUB_INT(s1, s2);
			   cout << res << endl;
			   break;
	}
	case'*':
	{
			   res = MUL_INT(s1, s2);
			   cout << res << endl;
			   break;
	}
	case'/':
	{
			   DIV_INT(s1, s2);
			   break;
	}
	default:break;
	}
	return;
}
