/*
+-----------------------------------------------------------------------+
| C++ Code Radix Sort                                                   |
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
using namespace std;


void radix_sort(int arr[], int n) {
    if (n < 1)
        return ;
    vector<int> bukets[10];
    int max_val = *max_element(arr, arr + n);
    for (int pow10 = 1; max_val != 0; pow10 *= 10, max_val /= 10) {
        for (int i = 0; i < n; i++) {
            int bkt_num = (arr[i] / pow10) % 10;
            bukets[bkt_num].push_back(arr[i]);
        }

        int arr_idx = 0;
        for (int i = 0; i < 10; i++) {
            for (vector<int>::iterator it=bukets[i].begin(); it!=bukets[i].end(); ++it) {
                arr[arr_idx++] = *it;
            }
            bukets[i].clear();
        }
    }
}

// int main() {
//     int v[] = { 432, 58, 576, 356 };
//     copy(v, v + 4, ostream_iterator<int>(cout, " "));
//     cout << endl;
//     radix_sort(v, 4);
//     copy(v, v + 4, ostream_iterator<int>(cout, " "));
//     cout << endl;
//     return 0;
// }
