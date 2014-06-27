/*
+-----------------------------------------------------------------------+
| C++ Code Heap                                                         |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <vector>
#include <functional> // using comparsion operations
using namespace std;

template <class Type = int, class Compare = greater<Type>>
class Heap {
private:
	vector<Type> __data;
	Compare 	 __comp;
	int 		 __size;

public:
	Heap(int *data, int size) {
		for (int i = 0; i < size; i++)
			__data.push_back(*(data + i));
	}

	void adjust(int childIndex, Type adjustValue) {
		int holeIndex = childIndex;
		int secondChild = 2 * holeIndex + 2;
		while (secondChild < __size) {
			if (__comp(__data[secondChild], __data[secondChild - 1]))
				--secondChild;
			__data[holeIndex] = __data[secondChild];
			holeIndex = secondChild; // prelocate down
			secondChild = 2 * secondChild + 2;
		}

		if (secondChild == __size) {
			__data[holeIndex] = __data[secondChild];
			holeIndex = secondChild - 1;
		}
		__data[holeIndex] = adjustValue;
	}

	void make_heap() {
		if (__size < 2) return;
		int parent = (__size - 2) / 2;
		while (true) {
			adjust(parent, __data[parent]);
			if (parent == 0) return;
			--parent;
		}
	}

	void push_element(Type e) {
		__data.push_back(e);
		++__size;
		int holeIndex = __size - 1;
		int parent = (__size - 2) / 2;
		while (holeIndex > 0 && __comp(__data[parent], e)) {
			__data[holeIndex] = __data[parent];
			holeIndex = parent;
			holeIndex = (holeIndex - 1) / 2;
		}
	}

	void pop_element() {
		Type temp = __data[__size - 1];
		__data[__size - 1] = __data[0];
		--__size;
		adjust(0, temp);

	}

	void sort() {
		while (size != 0) pop_element();
	}
};