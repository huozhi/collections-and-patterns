/*
+-----------------------------------------------------------------------+
| C++ Code Queue                                                        |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <algorithm>
using namespace std;


template <class Type>
class CircleQueue {
public:
	CircleQueue(): capacity(10), _front(0), _rear(0) {
		ele = new Type[capacity];
	}

	CircleQueue(int _capacity): _front(0), _rear(0) {
		if (_capacity <= 0)
			throw "Invalid capacity setting!\n";
		capacity = _capacity;
		ele = new Type[capacity];
	}

	~CircleQueue() { }

	bool isEmpty() const {
		if (_rear < _front) {
			return true;
		}
		return false;
	}

	int Size() const {
		return (_rear - _front);
	}

	void Push(const Type &_item) {
		if (capacity == Size()) {
			Expand();
		}
		ele[_rear] = _item;
		_rear = (_rear + 1) % capacity;
	}

	void Pop() {
		if (isEmpty())
			throw "Queue is already empty!";
		_front = (_front + 1) % capacity;
	}

	const Type &Front() const {
		return ele[_front];
	}

	const Type &Back() const {
		return ele[_rear - 1];
	}

	friend ostream &operator<<(ostream &os, const CircleQueue<Type> cq) {
		for (int i = cq._front; i < cq.Size(); i++) {
			os << cq.ele[i];
			if (i < cq.Size() - 1)
                os << ' ';
		}
		return os;
	}

	CircleQueue<Type>& Slipt(int __splitPos) {
		CircleQueue<Type> *newQueue = new CircleQueue;
		for (int i = 0; i < __splitPos; i++) {
			Type _item = this->Front();
			this->Pop();
			newQueue->Push(_item);
		}
		return *newQueue;
	}

protected:
	void Expand() {
		Type *newEle = new Type[capacity * 2];
		copy(ele, ele + capacity, newEle);
		delete [] ele;
		ele = newEle;
	}

private:
	int _front;
	int _rear;
	int capacity;
	Type *ele;
};
