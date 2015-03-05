/*
+-----------------------------------------------------------------------+
| C++ Code Binary Search                                                |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */



#include <vector>
using namespace std;

#define NOTFOUND -1
#define INVALID  -2

template <typename Type>
int BinarySearch(const vector<Type> &container, const Type &res, const int l, const int r) {
	int mid = (l+r)/2;
	if (mid < 0 || mid >= container.size())
		return INVALID;
	if (l > r)
		return NOTFOUND;
	else {
		if (res == container[mid])
			return mid;
		else if (res < container[mid])
			return BinarySearch(container, res, l, mid-1);
		else
			return BinarySearch(container, res, mid+1, r);
	}
}
