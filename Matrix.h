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

struct Point {
	unsigned row = 0;
	unsigned column = 0;
};


class Matrix {
public:
	using v_unsigned = vector<unsigned>;
	using vv_unsigned = vector<vector<unsigned>>;

	Matrix() = default;
	Matrix(const vv_unsigned &v) : elements(v) {}


	bool isMatrixSquare() const;
	unsigned getNrRows() const;
	unsigned getNrColumns() const;
	unsigned getDimensionSubSquare() const;

	Matrix &setCursor();
	Matrix &setElement();
	
	vv_unsigned::const_iterator cbegin() const;

	unsigned getElement() const;
	unsigned getCursorColumn() const;
	unsigned getCursorRow() const;
	Point getCursorSubSquare() const;
	unsigned getCursorSubSquarePositionInVector() const;


	v_unsigned getRow() const;
	v_unsigned getColumn() const;
	v_unsigned getSubSquare() const;


private:
	vv_unsigned elements;
	Point cursor;
	istream &readCursor(istream &);
	istream &readElement(istream &);
};