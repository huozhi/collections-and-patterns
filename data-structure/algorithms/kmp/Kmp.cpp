/*
+-----------------------------------------------------------------------+
| C++ Code KMP                                                          |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <vector>
#include <string>
#include <iostream>
using namespace std;


class KMP {
public:
	KMP(string _src, string _pat): src(_src), pat(_pat) {
		
	}
	~KMP() {
		src.~string();
		pat.~string();
		delete [] next;
	}

	/*
		getNext function for the defination of failure function
		original defination of failure array
		f(j) = {
			-1					(if j == 0)
			f^m(j - 1) + 1		(least int k for Pf^k(j-1) + 1 = Pj)
			-j 					(no k saytisfying the above)
		}
	*/
	void getNext() {
		/*
			movIndex is the index of source string
			cmpIndex is the start index of the pattern string
			when comparing with source string every time
		*/
		
		next = new int[pat.size()];
		int movInedx = 0;
		next[movInedx] = -1;
		int cmpIndex = next[movInedx];
		while (movInedx < pat.size()) {
			if (cmpIndex == -1 || pat[movInedx] == pat[cmpIndex]) {
				next[movInedx] = cmpIndex;
				++movInedx;
				++cmpIndex;
			}
			else
				cmpIndex = next[cmpIndex];
				/*
					this situation happends when comparing return result 'differnet'
					or pattern index is not 0(for value -1)
					the pattern index should be back to the last one
					until we put index to 0(for value -1) or comparing result return 'same'
				*/
		}
		printNext("getNext()");
	}
	
	int KmpCompare(int srcIndex = 0) {
		int patIndex = 0;

		while ((srcIndex < src.size()) && (patIndex < pat.size())) {
			if (src[srcIndex] == pat[patIndex]) {
				++patIndex;
				++srcIndex;
			}
			else {
				if (patIndex == 0)
					++srcIndex;
				else
					patIndex = next[patIndex - 1] + 1;
					/*
						use next arry to get the last position in pattern string
						if value is -1, then the pattern start index is 0
						means that it will re-compare two stirng from pattern's start
					*/
			}
		}
		// delete [] next;
		// next = (int *)NULL;
		if (patIndex < pat.size())
			return -1;
		else
			return srcIndex - pat.size();
	}

	void oldFailure() {
		next = new int[pat.size()];
		int movInedx = 0;
		next[movInedx] = -1;
		for (movInedx = 1; movInedx < pat.size(); movInedx++) {
			int cmpIndex = next[movInedx - 1];
			// backward to the first matched character
			while ((pat[movInedx] != pat[cmpIndex + 1]) && (cmpIndex != -1))
				cmpIndex = next[cmpIndex];
			// judge if the index is new start index
			// if different sign it with -1
			if (pat[movInedx] == pat[cmpIndex + 1])
				next[movInedx] = cmpIndex + 1;
			else
				next[movInedx] = -1;
		}
		printNext("oldFailure()");
	}

	/*
		newFailure function for the defination of failure function
		original defination of failure array
		f(j) = {
			least int i < j that P0...Pi = Pj-1...Pj and Pi+1 != Pj+1
			-j 					(no k saytisfying the above)
		}
	*/
	void newFailure() {
		int *next = new int[pat.size()];
		int index = 0;
		while (index < pat.size()) {
			int movInedx = index; // moveIndex for j
			int cmpIndex = (movInedx - 1) / 2; // cmpIndex for i
			while (cmpIndex >= 0) {
				if (pat[movInedx] != pat[cmpIndex])
					next[movInedx] = cmpIndex - 1;
				if (index != pat.size() - 1)
					if (pat[movInedx] == pat[cmpIndex])
						next[movInedx] = -1;
				--movInedx;
				--cmpIndex;
			}
			++index;
		}
		printNext("newFailure()");
	}

	void printNext(string title) {
		cout << "failure array got from function " << title << endl;
		for (int index = 0; index < pat.size(); index++)
			cout << next[index] << " ";
		cout << endl;
	}

protected:
	string src;
	string pat;
	int *next;
};


int main(int argc, char *argv[]) {
	string src("abcdadbcacd");
	string pat("dadb");

	KMP kmpStrCmp(src, pat);
	kmpStrCmp.oldFailure();
	
	kmpStrCmp.getNext();
	
	kmpStrCmp.newFailure();
	

	int index = kmpStrCmp.KmpCompare();
	int times = 1;
	cout << "times\tindex" << endl;
	if (index == -1)
		cout << "not found!" << endl;
	while (index != -1) {
		cout << times++ << '\t' << index << endl;
		index = kmpStrCmp.KmpCompare(index + 1);
	}
	return 0;
}