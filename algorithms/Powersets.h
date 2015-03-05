/*
+-----------------------------------------------------------------------+
| C++ Code iterative power set                                          |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */



#include <vector>
#include <iostream>
using namespace std;


void printPowerSet(vector<char> vec) {
	vector<char> vec;
	char c;
	while (cin >> c)
		vec.push_back(c);
	cout << "container size is " << vec.size() << endl;

	cout << "the powersets are:" << endl;
	cout << "( )" << endl;

	for (int i = 0; i < vec.size(); i++)
		for (int set_size = 1; set_size <= vec.size(); set_size++)
			for (int s = i; s < set_size; s++) {
				if (s == i) cout << "( ";
				cout << vec[s];
				if (s != set_size-1)
					cout << ", ";
				else cout << " )" << endl;
			}
}

