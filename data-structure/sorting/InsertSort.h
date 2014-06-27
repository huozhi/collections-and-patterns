/*
+-----------------------------------------------------------------------+
| C++ Code Insert Sort                                                  |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */

#include <iostream>
using namespace std;


void insert_sort(int arr[], int Size, int i = 1)
{
    // return condition
    int pos = i;
    if (i == Size)
    {
        for (int j = 0; j < Size; j++)
            cout << arr[j] << " ";
        cout << endl;
        return;
    }
    // sort
    while (i > 0 && arr[i - 1] > arr[i])
    {
        swap(arr[i], arr[i - 1]);
        --i;
    }
    // recursion step
    insert_sort(arr, 10, pos + 1);
}

// int main()
// {
//     int arr[10] = { 4, 5, 6, 7, 1, 2, 3, 8, 9, 0 };
//     insert_sort(arr, 10);

//     return 0;
// }
