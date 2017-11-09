/*

queue adapter example, implemented by double linked list

*/

#include <bits/stdc++.h>
using namespace std;


template <class Type>
class QueueAdapter {
private:
    list<Type> sequence;
public:
    QueueAdapter() { }
    Type fron() {
        return sequence.front();
    }

    Type back() {
        return sequence.back();
    }

    void offer(Type value) {
        sequence.push_back(value);
    }

    Type poll() {
        Type tmp = sequence.front();
        sequence.pop_front();
        return tmp;
    }

    size_t size() const { return sequence.size(); }
};


int main() {
    QueueAdapter<string> que;
    que.offer("hello");
    que.offer("world");
    que.offer("my");
    que.offer("sir");

    while (que.size()) {
        cout << que.poll() << endl;
    }
}


/*

Output

hello
world
my
sir

*/ 