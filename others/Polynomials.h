/*
+-----------------------------------------------------------------------+
| C++ Code Polynomial                                                   |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */



#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;


#define MAXSIZE 100


class Term;
class Polynomial;


class Term {
friend class Polynomial;
friend ostream &operator <<(ostream &, const Polynomial &);
protected:
	float	coef;
	int		exp;
};

class Polynomial
{
	friend ostream &operator <<(ostream &os, const Polynomial &_x) {
		cout << "start from: " << _x.start << " to " << _x.finish << endl;
		for (int iter = _x.start; iter <= _x.finish; iter++) {
			cout << _x.termArray[iter].coef << "X^" << _x.termArray[iter].exp;
			if (iter != _x.free - 1)
				cout << " + ";
		}
		cout << endl;
		return os;
	}
public:
	Polynomial() {
		start = free;
		finish = start - 1;
		//++free;
	}

	Polynomial(int polynome_len) {
		// Get  polynome size
		
		if (polynome_len <= 0)
			throw std::logic_error("length can't be shorter than 0!\n");
		Term *tempTermArray = new Term[polynome_len];
		cout << "input coef and exp of each term" << endl;
		// Input coef and exp
		int iter = 0;
		while (iter < polynome_len) {
			cin >> tempTermArray[iter].coef;
			cin >> tempTermArray[iter].exp;
			++iter;
		}
		start	= free;
		finish  = start + polynome_len - 1;
		// Copy temporary array
		copy(tempTermArray, tempTermArray + polynome_len, termArray + free);
		free   += polynome_len;
		delete tempTermArray;
	};

	~Polynomial() {}

	Term &operator [](int pos) {
		if (pos < 0 || pos >= free)
			throw logic_error("invalid position\n");
		return termArray[pos];
	} 

	void NewTerm(const float theCoeff, const int theExp) {
		// Expand capacity
		
		if (free == capacity) {
			capacity *= 2;
			Term *tempTerms = new Term[capacity];
			copy(termArray, termArray + free + 1, tempTerms);
			delete [] termArray;
			termArray = tempTerms;
		}
		// Assign
		termArray[++finish].coef = theCoeff;
		termArray[finish].exp  = theExp;
		free = finish + 1;
		// cout << "new free" << free << endl;
	}

	Polynomial operator+(const Polynomial &_x) {
		Polynomial sum;
		int aPos   = start;
		int bPos   = _x.start;
		int aTerms =    finish + 1;
		int bTerms = _x.finish + 1;
		cout << aTerms << " " << bTerms << endl;

		while ((aPos < aTerms) && (bPos < bTerms)) {
			if (termArray[aPos].exp == _x.termArray[bPos].exp) {
				float newCoef = termArray[aPos].coef + _x.termArray[bPos].coef;
				if (newCoef != 0) {
					// cout << "same" << endl;
					sum.NewTerm(newCoef, termArray[aPos].exp);

				}
				++aPos;
				++bPos;
			}
			else if (termArray[aPos].exp > _x.termArray[bPos].exp) {
				// cout << "greater" << endl;
				sum.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
				++aPos;
			}
			else {
				// cout << "less" << endl;
				sum.NewTerm(_x.termArray[bPos].coef, _x.termArray[bPos].exp);
				++bPos;
			}
		}
		while (aPos < aTerms) {
			sum.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
			++aPos;
		}
		while (bPos < bTerms) {
			sum.NewTerm(_x.termArray[bPos].coef, _x.termArray[bPos].exp);
			++bPos;
		}
		return sum;
	}

	Polynomial operator*(const Polynomial &_x) {
		Polynomial product;
		Polynomial tempSum;
		int aTerms =    finish -    start + 1;
		int bTerms = _x.finish - _x.start + 1;
		for (int i = 0; i < aTerms; i++) {
			for (int j = 0; j < bTerms; j++) {
				/*code*/
			}
		}
		return product;
	}

	int getFree() const { return this->free; }

protected:
	static Term	*termArray;
	static int	 capacity;
	static int	 free;
	int 		 start;
	int 		 finish;
};

int Polynomial::free 		= 0;
int Polynomial::capacity	= 100;
Term *Polynomial::termArray	= new Term[100];

