/*
+-----------------------------------------------------------------------+
| C++ Code List Problem                                                 |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> ll;
    for (int i = 0; i < 10; i++)
        ll.push_back(i + 1);
    list<int>::iterator first = ll.begin();
    list<int>::iterator second = ll.begin();
    int i = 5;
    while (--i)
        ++second; // point to ll's 4th element
    int sum = 0;
    while (second != ll.end()) {
        sum += (*first * *second);
        ++first; ++second;
    }
    cout << sum;
    return 0;
}
