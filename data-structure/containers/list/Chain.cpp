/*
+-----------------------------------------------------------------------+
| C++ Code SingleList                                                   |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int data;
	node *next;
};

class LinkedList {
private:
	node *head;
public:
    class Iterator;
	LinkedList() {
		head = (node *)NULL;
	}

	~LinkedList() {
		delete [] head;
	}

	void add(int _data) {
		node *_new = new node;
		_new->data = _data;
		_new->next = (node *)NULL;

		if (!head)	head = _new;
		else {
			node *temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = _new;
		}
	}

	const int length() const {
		node *temp = head;
		int counter = 0;
		while (temp) {
			temp = temp->next;
			++counter;
		}
		return counter;
	}

	void Copy(Iterator from, Iterator to, int*& arr) {
        int i = 0;
        while (from != to) {
            arr[i] = *from;
            ++i;
            ++from;
        }
	}

	Iterator begin() {
		return head;
	}

	Iterator end() {
	    return Iterator(NULL);
	}

	void remove(node *position) {
		node *current = head;
		node *previous = (node *)NULL;
		while (current) {
			if (position->data == head->data) {
				node *temp = head;
				head = head->next;
				delete temp;
				break;
			}
			else if (position->data == current->data) {
				// found and delete
				previous->next = current->next;
				delete current;
				break;
			}
			// iteration
			previous = current;
			current = current->next;
		}
	}

	void print() {
		node *temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse() {
		node *prev_n = NULL;
		node *curr_n = head;
		while (curr_n) {
			node *temp = curr_n->next;
			curr_n->next = prev_n;
			prev_n = curr_n;
			curr_n = temp;
		}
		head = prev_n;
	}

	/*
	 *	Iterator class
	 *
	 */

	class Iterator {
	private:
		node *iter;
	public:
		Iterator(node *position = (node *)NULL) {
			iter = position;
		}

		int& operator*() const { return iter->data; }
		int* operator->() const { return &iter->data; }

		//post-increament
		Iterator operator++(int) {
			Iterator temp = *this;
			iter = iter->next;
			return temp;
		}

		// pre-increament
		Iterator& operator++() {
			iter = iter->next;
			return *this;
		}

		void operator=(Iterator __iter) {
			iter = __iter.iter;
		}

		bool operator!=(Iterator __iter) {
			return iter != __iter.iter;
		}

	};
};


int main() {

	LinkedList mList;
	for (int i = 0; i < 10; i++)
		mList.add(i + 1); // 10 nodes
	mList.add(2013); // 1 node
	for (int i = 10; i < 20; i++)
		mList.add(i + 1); // 10 nodes

	// currently, 21 nodes

	cout << "Length: " << mList.length() << endl;
	cout << "list conatins:" << endl;
	mList.print();

	node *_new = new node;
	_new->data = 2013;
	_new->next = NULL;

	// remove
	mList.remove(_new);
	cout << "remove 2013" << endl;
	mList.print();

	// reverse
	mList.reverse();
	cout << "reverse:" << endl;
	mList.print();

	// iterative copy
	int len = 0;
	LinkedList::Iterator it;
	for (it = mList.begin(); it != NULL; ++it)
		++len;

    cout << "len: " << len << endl;
	int *arr = new int[len];
	mList.Copy(mList.begin(), mList.end(), arr);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}
