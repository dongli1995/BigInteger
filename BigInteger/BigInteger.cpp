// BigInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BigInteger.h"

inline int compare(string str1, string str2) {
	if (str1.size()>str2.size()) return 1; 
	else if (str1.size()<str2.size()) return -1;
	else                              return str1.compare(str2); 
}
string SUB_INT(string str1, string str2);
string ADD_INT(string str1, string str2) {
	int sign = 1; 
	string str;
	if (str1[0] == '-') {
		if (str2[0] == '-') {
			sign = -1;
			str = ADD_INT(str1.erase(0, 1), str2.erase(0, 1));
		}
		else {
			str = SUB_INT(str2, str1.erase(0, 1));
		}
	}
	else {
		if (str2[0] == '-') {
			str = SUB_INT(str1, str2.erase(0, 1));
		}
		else { 
			string::size_type L1, L2;
			int i;
			L1 = str1.size();
			L2 = str2.size();
			if (L1<L2) {
				for (i = 1; i <= L2 - L1; i++) str1 = "0" + str1;
			}
			else {
				for (i = 1; i <= L1 - L2; i++) str2 = "0" + str2;
			}
			int int1 = 0, int2 = 0; 
			for (i = str1.size() - 1; i >= 0; i--) {
				int1 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) % 10;
				int2 = (int(str1[i]) - '0' + int(str2[i]) - '0' + int2) / 10;
				str = char(int1 + '0') + str;
			}
			if (int2 != 0) str = char(int2 + '0') + str;
		}
	}

	if ((sign == -1) && (str[0] != '0')) str = "-" + str;
	return str;
}
string SUB_INT(string str1, string str2) {
	int sign = 1; 
	string str;
	int i, j;
	if (str2[0] == '-') {
		str = ADD_INT(str1, str2.erase(0, 1));
	}
	else {
		int res = compare(str1, str2);
		if (res == 0) return "0";
		if (res<0) {
			sign = -1;
			string temp = str1;
			str1 = str2;
			str2 = temp;
		}
		string::size_type tempint;
		tempint = str1.size() - str2.size();
		for (i = str2.size() - 1; i >= 0; i--) {
			if (str1[i + tempint]<str2[i]) {
				j = 1;
				while (1) {
					if (str1[i + tempint - j] == '0') {
						str1[i + tempint - j] = '9';
						j++;
					}
					else {
						str1[i + tempint - j] = char(int(str1[i + tempint - j]) - 1);
						break;
					}
				}
				str = char(str1[i + tempint] - str2[i] + ':') + str;
			}
			else {
				str = char(str1[i + tempint] - str2[i] + '0') + str;
			}
		}
		for (i = tempint - 1; i >= 0; i--) str = str1[i] + str;
	}

	str.erase(0, str.find_first_not_of('0'));
	if (str.empty()) str = "0";
	if ((sign == -1) && (str[0] != '0')) str = "-" + str;
	return str;
}
string MUL_INT(string str1, string str2) {
	int sign = 1; 
	string str;
	if (str1[0] == '-') {
		sign *= -1;
		str1 = str1.erase(0, 1);
	}
	if (str2[0] == '-') {
		sign *= -1;
		str2 = str2.erase(0, 1);
	}
	int i, j;
	string::size_type L1, L2;
	L1 = str1.size();
	L2 = str2.size();
	for (i = L2 - 1; i >= 0; i--) { 
		string tempstr;
		int int1 = 0, int2 = 0, int3 = int(str2[i]) - '0';
		if (int3 != 0) {
			for (j = 1; j <= (int)(L2 - 1 - i); j++) tempstr = "0" + tempstr;
			for (j = L1 - 1; j >= 0; j--) {
				int1 = (int3*(int(str1[j]) - '0') + int2) % 10;
				int2 = (int3*(int(str1[j]) - '0') + int2) / 10;
				tempstr = char(int1 + '0') + tempstr;
			}
			if (int2 != 0) tempstr = char(int2 + '0') + tempstr;
		}
		str = ADD_INT(str, tempstr);
	}

	str.erase(0, str.find_first_not_of('0'));
	if (str.empty()) str = "0";
	if ((sign == -1) && (str[0] != '0')) str = "-" + str;
	return str;
}

void DIV_INT(string str1, string str2) {
	string quotient, residue;//商和余数
	int sign1 = 1, sign2 = 1;
	if (str2 == "0") {  //判断除数是否为0
		quotient = "ERROR!";
		residue = "ERROR!";
		cout << quotient << endl;
		cout << residue << endl;
		return;
	}
	if (str1 == "0") { //判断被除数是否为0
		quotient = "0";
		residue = "0";
		cout << quotient << endl;
		cout << residue << endl;
		return;
	}
	if (str1[0] == '-') {
		str1 = str1.erase(0, 1);
		sign1 *= -1;
		sign2 = -1;
	}
	if (str2[0] == '-') {
		str2 = str2.erase(0, 1);
		sign1 *= -1;
	}
	int res = compare(str1, str2);
	if (res<0) {
		quotient = "0";
		residue = str1;
	}
	else if (res == 0) {
		quotient = "1";
		residue = "0";
	}
	else {
		string::size_type L1, L2;
		L1 = str1.size();
		L2 = str2.size();
		string tempstr;
		tempstr.append(str1, 0, L2 - 1);
		for (int i = L2 - 1; i<L1; i++) { 
			tempstr = tempstr + str1[i];
			tempstr.erase(0, tempstr.find_first_not_of('0'));
			if (tempstr.empty()) tempstr = "0";
			for (char ch = '9'; ch >= '0'; ch--) { 
				string str;
				str = str + ch;
				if (compare(MUL_INT(str2, str), tempstr) <= 0) {
					quotient = quotient + ch;
					tempstr = SUB_INT(tempstr, MUL_INT(str2, str));
					break;
				}
			}
		}
		residue = tempstr;
	}

	quotient.erase(0, quotient.find_first_not_of('0'));
	if (quotient.empty()) quotient = "0";
	if ((sign1 == -1) && (quotient[0] != '0')) quotient = "-" + quotient;
	if ((sign2 == -1) && (residue[0] != '0')) residue = "-" + residue;
	cout << quotient  << endl;
	cout << residue << endl;
	return;
}


