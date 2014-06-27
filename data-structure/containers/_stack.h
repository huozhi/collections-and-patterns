/*
+-----------------------------------------------------------------------+
| C++ Code Stack                                                        |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Stack {
public:
	Stack(int _setCapacity = 100): capacity(_setCapacity) {
		ele = new T[capacity];
		top = -1; // create stack
	}

	void Push(const T &val) {
		ele[++top] = val;
	}

	T& Top() {
		return ele[top];
	}

	void Pop() {
		if (!isEmpty()) {
			ele[top].~T();
			--top;
		}
	}

	bool isEmpty() const {
		return top == -1;
	}

	int Size() const {
		return top + 1;
	}

	Stack<T> Slipt(int fromIndex) {
		Stack<T> remains(top + 1 - fromIndex);
		for (int iter = top; iter >= 0; top--) {
			remains.Push(ele[iter]);
			Pop();
		}
		return remains;
	}

	void Merge(Stack<T> __x) {
        while (!__x.isEmpty()) {
			this->Push(__x.Top());
            __x.Pop();
        }
	}

	void Expand() {
		T *tempELe = new T[capacity * 2];
		copy(ele, ele + capacity, tempELe);
		delete [] ele;
		ele = tempELe;
	}

	void Clear() {
		while (!isEmpty())
			this->Pop();
	}

	friend ostream &operator<<(ostream &os, const Stack<T> s) {
		for (int i = 0; i < s.Size(); i++)
			os << s.ele[i] << " ";
		return os;
	}


protected:
	T *ele;
	int top;
	int capacity;
};

