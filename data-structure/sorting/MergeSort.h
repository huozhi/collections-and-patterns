/*
+-----------------------------------------------------------------------+
| C++ Code Merge Sort                                                   |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>
using namespace std;

void merge_sort(int *, int);
void _merge(int *, int, int *, int);

void merge_sort(int *_arr, int _size) {
    if (_size > 1) {
        int _half = _size / 2;
        // left part
        merge_sort(_arr, _half);
        // right part
        merge_sort(_arr + _half, _size - _half);

        _merge(_arr, _half, _arr + _half, _size - _half);
    }
}

void _merge(int *first, int fsize, int *second, int ssize) {
    // first, second, and result indexes
    int fi = 0;
    int si = 0;
    int ri = 0;
    int *res = new int[fsize + ssize];
    // select the larger one
    while (fi < fsize && si < ssize)
        res[ri++] = (first[fi] > second[si]) ? first[fi++] : second[si++];

    // copy left
    while (fi < fsize) res[ri++] = first[fi++];
    while (si < ssize) res[ri++] = second[si++];

    for (fi = 0; fi < (fsize + ssize); ++fi)
        first[fi] = res[fi];
    // release memory alloced
    delete [] res;
}

// #define N   10

// int main() {

//     int arr[N] = { 4, 9, 1, 3, 0, 6, 8, 7, 2, 5 };
//     merge_sort(arr, N);

//     for (int e : arr) cout << e << " ";
//     cout << endl;
//     return 0;
// }
