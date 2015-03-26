#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);


struct node {
    node():next(0) {}
    node(int val): value(val), next(0) { }
    node *next;
    int value;
};

class Queue {
private:
    node head;
    node* last;
public:
    Queue() {
        last = &head;
    }

    bool empty() const {
        return &head == last;
    }

    void push(int value) {
        last->next = new node(value);
        last = last->next;
    }

    void pop() {
        node *tmp = head.next;
        head.next = tmp->next;
        tmp->~node();
    }

    int front() const {
        return head.next->value;
    }

    int back() const {
        return last->value;
    }
};



/**
int main() { _
    Queue que;
    cout << boolalpha << que.empty() << endl;
    que.push(1);
    que.push(2);
    que.push(3);
    cout << que.front() << endl;
    cout << que.back() << endl;
    que.pop();
    cout << que.front() << endl;
    cout << que.back() << endl;
    return 0;
}
*/
