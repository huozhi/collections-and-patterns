/*
+-----------------------------------------------------------------------+
| C++ Code Permutation                                                  |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */
#include <iostream>
using namespace std;

template <class T>
void perm(T *data, int from, int to) {
    if (from == to) {
        ostream_iterator<T> out(cout, " ");
        copy(data, data + to, out);
        cout << endl;
    }
    for (int start = from; start != to; start++) {
        std::swap(data[from], data[start]);
        perm(data, from + 1, to);
        std::swap(data[start], data[from]);
    }
}


