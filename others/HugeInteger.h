/*
+-----------------------------------------------------------------------+
| C++ Code big digit template                                           |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#ifndef __HUGEINTEGER_H__
#define __HUGEINTEGER_H__

#include <iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <cctype>

class HugeInt
{
	friend ostream &operator <<(ostream &, const HugeInt &);

public:
	explicit HugeInt()
	{
		length = 0;
		sign   = false;
		digit  = new int;
		*digit = 0;
	}

	explicit HugeInt(const int &Integer)
	{
		length = 0;
		int tmpInt = Integer;
		// judge sign
		if (tmpInt >= 0)
			sign = false;
		else sign = true;

		// store digits
		if (tmpInt == 0) {
			digit  = new int;
			*digit = 0;
		}
		else {
			while (tmpInt > 0) {
				tmpInt /= 10;
				length++;
			}
			digit = new int[length];
			tmpInt = Integer;
			int _pos = 0;
			while (_pos != length) {
				digit[_pos] = tmpInt % 10;
				tmpInt /= 10;
				++_pos;
			}
		}
	}

	explicit HugeInt(const string &str)
	{
		int _pos  = 0;
		int start = 0;
		length    = 0;

		// judge sign
		while (_pos != str.size() && !isdigit(str[_pos]) && (str[_pos]!='-'
				&& !isdigit(str[_pos]) && str[_pos]!='+'))
			++_pos;
		if (str[_pos] == '-')
			sign = true;
		else
			sign = false;
		
		// ignore characters not valid
		while (_pos != str.size() && (str[_pos] == '0' || !isdigit(str[_pos])))
			++_pos;
		
		// store digits
		int index = _pos;
		while (index != str.size()) {
			if (isdigit(str[index]))
				++length;
			++index;
		}
		digit = new int[length];
		index = 0;
		int intEnd = length - 1;
		while (_pos != str.size()) {
			if (isdigit(str[_pos])) {	
				digit[intEnd-index] = str[_pos] - '0';
				++index;
			}
			++_pos;
		}
	}

	bool isequal(const HugeInt &__x) const
	{
		if (length != __x.length || sign != __x.sign)
			return false;

		int index = 0;
		while (index != length) {
			if (digit[index] != __x.digit[index])
				return false;
			++index;
		}
		return true;
	}

protected:
	bool  sign;
	int *digit;
	int length;
};

ostream &operator <<(ostream &os, const HugeInt &bigInt)
{
	if (bigInt.sign)
		os << "-";
	for (int index = bigInt.length - 1; index >= 0; index--)
		os << bigInt.digit[index];
	return os;
}

#endif/*__HUGEINTEGER_H__*/