/*
+-----------------------------------------------------------------------+
| C++ Code Quick Sort                                                   |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <algorithm>
using namespace std;

void quickSort1(int arr[], int left, int right) {
	if (left < right) {
		int i = left, j = right;
		int key = arr[i];
		while (i < j) {
			while (i < j && arr[j] >= key) j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i] <  key) i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = key;
		quickSort1(arr, left, i - 1);
		quickSort1(arr, i + 1, right);
	}
}

int partition(int arr[], int left, int right) {
	while (true) {
		int i = left - 1, j = right + 1, key = arr[left];
		do {
			--j;
		} while (arr[j] > key);

		do {
			++i;
		} while (arr[i] < key);

		if (i < j)
			swap(arr[i], arr[j]);
		else
			return i;
	}
}

void quickSort2(int arr[], int left, int right) {
	if (left < right) {
		int key_index = partition(arr, left, right);
		quickSort2(arr, left, key_index - 1);
		quickSort2(arr, key_index + 1, right);
	}
}

struct display {
	void operator() (const int& x) {
		cout << x << " ";
	}
};

// int main() {
// 	int a[10] = {4,1,3,2,5,6,0,9,7,8};
// 	quickSort2(a, 0, 9);
// 	for_each(a, a + 10, display());
// 	return 0;

// }