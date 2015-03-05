#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

template <class Type>
class SingleList {
private:
    template <class T>
    struct ListNode {
        Type     data;
        ListNode<Type> *next;
        ListNode(Type val):next(NULL) {
            data = val;
        }
    };

    ListNode<Type> *head;
public:
    SingleList(): head(NULL) {

    }

    void insert(Type val) {
        if (!head) {
            head = new ListNode<Type>(val);
        }
        else {
            ListNode<Type> *curr = head;
            while (curr->next) curr = curr->next;
            curr->next = new ListNode<Type>(val);
        }
    }

    vector<Type> toArray() {
        vector<Type> v;
        ListNode<Type> *curr = head;
        while (curr) {
            v.push_back(curr->data);
            curr = curr->next;
        }
        return v;
    }

    void remove(Type val) {
        ListNode<Type> *trash, *prev = NULL, *curr = head;
        while (curr) {
            if (curr->data == val) {
                trash = curr;
                if (prev) {
                    curr = curr->next;
                    prev->next = curr;
                }
                else {
                    head = curr->next;
                }
                delete trash;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
    }
};

#endif // SINGLELIST_H_INCLUDED
