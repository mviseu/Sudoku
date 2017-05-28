#pragma once

#include <vector>
#include <iostream>

using std::vector;
using std::istream;
using std::cout;
using std::endl;

namespace {
	inline unsigned convertBase1to0(unsigned u) {
		return u - 1;
	}
}

struct Cursor {
	unsigned row = 0;
	unsigned column = 0;
};


class Matrix {
public:
	using vv_unsigned = vector<vector<unsigned>>;

	Matrix() = default;
	Matrix(const vv_unsigned &v) : elements(v) {}

	const vv_unsigned &returnElements() const {
		return elements; 		
	}
	vv_unsigned &returnElements() {
		return elements;
	}
	void printElements() const {
		for(const auto &row : elements) {
			for(const auto &e : row) {
				cout << e << " ";
			}
		cout << endl;
		}
	}
	istream &readCursor(istream &is);
	istream &changeElement(istream &is);
	vv_unsigned::const_iterator cbegin() const;


private:
	vv_unsigned elements;
	Cursor cursor;
};