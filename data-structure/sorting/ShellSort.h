/*
+-----------------------------------------------------------------------+
| C++ Code ShellSort                                                    |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
using namespace std;

template <class T>
void ShellSort(T *data, int size)
{
    // move by gap
    for (int step = size / 2; step > 0; step /= 2)
        for (int i = 0; i < size - step; ++i) {
            // insert sort
            int key = data[i + step];
            int j = 0;
            for (j = i ; j >= 0 && data[j] > key; j -=step) {
                data[j + step] = data[j];
            }
            data[j + step] = key;
        }
}

// int main() {
//     int arr[8] = { 4, 7, 6, 8, 21, 45, 32, 0 };
//     ShellSort(arr, 8);
//     for (int i = 0; i < 8; i++)
//         cout << arr[i] << endl;

//     return 0;
// }