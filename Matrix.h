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
	using v_unsigned = vector<unsigned>;
	using vv_unsigned = vector<vector<unsigned>>;

	Matrix() = default;
	Matrix(const vv_unsigned &v) : elements(v) {}

	Matrix &setCursor();
	Matrix &setElement();
	
	vv_unsigned::const_iterator cbegin() const;

	unsigned getElement() const;
	unsigned getCursorColumn() const;
	v_unsigned getRow() const;


private:
	vv_unsigned elements;
	Cursor cursor;
	istream &readCursor(istream &);
	istream &readElement(istream &);
};