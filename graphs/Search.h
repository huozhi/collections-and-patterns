/*
+-----------------------------------------------------------------------+
| C++ Code BFS & DFS                                                    |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graph {
private:
    struct node {
        int   data;
        node *next;

        node() : next(NULL) {}
        node(int __data) : data(__data),
            next(NULL) {}

    };
    typedef node* link;
private:
    link *_root;
    int   _size;
    bool *_visi;
public:
    graph() : _root(NULL), _size(0), _visi(NULL) {}

    graph(int *vertix, int *matrix, int n) : _size(n) {
        __make_adjmatrix();
        for (int __i = 0; __i < _size; ++__i) {
            _root[__i] = make_node(vertix[__i]);
            link current = _root[__i];
            for (int __k = 0; __k < _size; ++__k) {
                // if visited
                if (matrix[__i * _size + __k]) {
                    while (current->next)
                        current = current->next;
                    current->next = make_node(vertix[__k]);
                }
            }
        }
    }

    ~graph() {
        if (_root) {
            for (int __i = 0; __i < _size; ++__i) {
                if (_root[__i])
                    delete[] _root[__i];
            }
            delete[] _root;
        }
    }

    void printAdjacencyList() {
        for (int __i = 0; __i < _size; ++__i) {
            link current = _root[__i];
            for (int __k = 0; __k < _size; ++__k) {
                while (current) {
                    cout << current->data << "-> ";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }



    // deep first search
    void DFS() {
        initStatus();
        r_DFS(_root[0]);
    }

    // breadth first search
    void BFS() {
        initStatus();
        i_BFS();
    }

private:
    void initStatus() {
        _visi = new bool[_size];
        for (int __i = 0; __i < _size; ++__i)
            _visi[__i] = false;
    }

    void __make_adjmatrix() {
        _root = new link[_size];
        for (int i = 0; i < _size; ++i)
            _root[i] = new node;
    }

    node *make_node(int __data) {
        return new node(__data);
    }

    void visit(link __node) {
        cout << __node->data << "-> ";
        int curr_idx = get_idx(__node);
        _visi[curr_idx] = true;
    }

    int get_idx(link _node) {
        int __i = 0;
        while (__i < _size) {
            if (_root[__i]->data == _node->data)
                return __i;
            ++__i;
        }
        return __i; // error here
    }

    // recursive
    void r_DFS(link __node) {
        link curr = __node;
        int curr_idx, next_idx;
        while (curr) {
            // if not visited
            curr_idx = get_idx(curr);
            if (!_visi[curr_idx]) {
                // if not end of list
                if (curr->next)
                    next_idx = get_idx(curr->next);
                else
                    return;
                visit(curr);
                r_DFS(_root[next_idx]);
            }
            curr = curr->next;
        }
    }

    // iterative
    void i_BFS() {
        queue<link> scan;
        if (_root)
            scan.push(_root[0]);
        while (!scan.empty()) {
            link curr = scan.front();
            visit(curr);
            scan.pop();
            curr = curr->next;
            int curr_idx;
            while (curr) {
                curr_idx = get_idx(curr);
                if (!_visi[curr_idx]) {
                    scan.push(_root[curr_idx]);
                }
                curr = curr->next;
            }
        }
    }
};


/*
int main() {
    const int n = 6;
    int weight[n] = { 1, 2, 3, 4, 5, 6 };
    int matrix[n * n] = {
        0, 1, 0, 1, 0, 0,
        0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 1, 1,
        0, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 1
    };

    graph _G(weight, matrix, n);
    cout << "Adjacency List:" << endl;
    _G.printAdjacencyList();
    cout << endl << "DFS:" << endl;
    _G.DFS();
    cout << endl << "BFS:" << endl;
    _G.BFS();
    return 0;

}
*/
