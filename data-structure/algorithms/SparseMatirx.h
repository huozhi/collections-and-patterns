/*
+-----------------------------------------------------------------------+
| C++ Code                                                              |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>
#include <algorithm>
using namespace std;


class MatrixTerm {
	friend class SparseMatrix;
public:
	MatrixTerm() {}
	MatrixTerm(int r, int c, int v): row(r), col(c), val(v) {}
	~MatrixTerm() {}
	void assignTerm() {
		cout << "Enter column, row, value" << endl;
		cin >> col;
		cin >> row;
		cin >> val;
	}
protected:
	int col;
	int row;
	int val;
};

class SparseMatrix {
public:
	SparseMatrix() {
		eleArray = (MatrixTerm *)NULL;
		rows = cols = terms = capacity = 0;
	}
	SparseMatrix(int _setTerms) {
		initCapacity();
		cout << "Enter size(rows and column):" << endl;
		cin >> rows;
		cin >> cols;
		cout << "Enter terms" << endl;
		terms = _setTerms;
		eleArray = new MatrixTerm[terms];
		for (int i = 0; i < terms; i++) {
			cin >> eleArray[i].col;
			cin >> eleArray[i].row;
			cin >> eleArray[i].val;
		}
	}
	SparseMatrix(MatrixTerm *mt, int rs, int cs, int ts, int cp) {
		eleArray = mt;
		rows = rs;
		cols = cs;
		terms = ts;
		capacity = cp;
	}
	~SparseMatrix() {}

	SparseMatrix FastTranspose() {
		SparseMatrix trans;
		if (terms <= 0) return trans;

		int *rowStart = new int[cols];
		fill(rowStart, rowStart + cols, 0);
		for (int i = 0; i < terms; i++) rowStart[eleArray[i].col]++;
		int temp = 0;
		int delta = 0;
		for (int i = 0; i < cols - 1; i++) {
			temp = rowStart[i + 1];
			rowStart[i + 1] = rowStart[i] + delta;
			delta = temp;
		}
		for (int i = 0; i < terms; i++) {
			int j = rowStart[eleArray[i].col];
			trans.eleArray[j].row = eleArray[i].col;
			trans.eleArray[j].col = eleArray[i].row;
			trans.eleArray[j].val = eleArray[i].val;
			++rowStart[eleArray[i].col];
		}
		delete [] rowStart;
		return trans;
	}
protected:
	void initCapacity() {
		capacity = 100;
	}
protected:
	/* data */
	MatrixTerm *eleArray;
	int rows;
	int cols;
	int terms;
	int capacity;
};

