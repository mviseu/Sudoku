#pragma once

#include <vector>
#include <iostream>

using std::vector;
using std::istream;
using std::cout;
using std::endl;

namespace {
	inline unsigned convertBase1to0(unsigned u) {
		u > 0 ? --u: u = 0;
		return u;
	}
}

struct Point {
	Point() = default;
	Point(const unsigned r, const unsigned c) : row(r), column(c) {}
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
	unsigned getSubSquareDimension() const;

	bool isRowEmpty(const unsigned r) const;
	bool isElementEmpty(const Point rc) const;

	Matrix &readPosition(istream &is);
	Matrix &readPositionFromCin();


	Matrix &readElement(istream &is);
	Matrix &readElement(const unsigned u);
	Matrix &readElementFromCin();
	
	vv_unsigned::const_iterator cbegin() const;

	unsigned getElement() const;
	unsigned getCursorColumn() const;
	unsigned getCursorRow() const;
	Point getCursorSubSquare() const;
	unsigned getCursorSubSquarePositionInVector() const;


	v_unsigned getRow() const;
	v_unsigned getColumn() const;
	v_unsigned getSubSquare() const;

	bool isElementInMatrix(unsigned u) const;

private:
	v_unsigned &addSubSquareRow(const vv_unsigned::const_iterator subSquareRowIter, v_unsigned &subSquare) const; 
	vv_unsigned elements;
	Point cursor;
};