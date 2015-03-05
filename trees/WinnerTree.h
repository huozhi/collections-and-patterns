/*
+-----------------------------------------------------------------------+
| C++ Code winner tree                                                  |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <list>
using namespace std;

template <class Type, class Compare>
class WinnerTree {
private:
    int          ele_num;
    Compare      comp;
    vector<Type> tree; // tree[0] is winner

public:
    WinnerTree(): comp(greater<int>()) {}
    WinnerTree(Type *_data, int _size, Compare _comp):
        ele_num(_size), comp(_comp) {
        tree.resize(2 * ele_num - 1);

        int j = ele_num - 1;
        for (int i = 0; i < ele_num; i++, j++) {
            tree[j] = _data[i];
        }
    }

    void judge() {
        int idx = ele_num * 2 - 2;
        for (; idx > 0; idx -= 2) {
            tree[(idx - 2) / 2]
                = comp(tree[idx], tree[idx - 1])
                ? tree[idx] : tree[idx - 1];
        }
    }

    const Type getWinner() {
        return tree.at(0);
    }

    friend ostream& operator<<(ostream& os, const WinnerTree& wtree) {
        int level = 0;
        int count = 0;
        while (count < wtree.ele_num) {
            for (int i = 0; i < (int)pow(2, (double)level); i++) {
                cout << wtree.tree[count++] << " ";
            }
            ++level;
            cout << endl;
        }
        return os;
    }

};

