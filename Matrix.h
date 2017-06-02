#pragma once

#include <vector>
#include <iostream>

using std::vector;
using std::istream;
using std::cout;
using std::endl;

namespace {
	inline unsigned convertBase1to0(unsigned u) {
		// unsafe (overflow could be surprising from client´s point of view)
		return u - 1;
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

	Matrix() = default; // unnecessary (+ unused ?)
	Matrix(const vv_unsigned &v) : elements(v) {}


	bool isMatrixSquare() const;
	unsigned getNrRows() const;
	unsigned getNrColumns() const;
	// getSubsquareDimension ?
	unsigned getDimensionSubSquare() const;

	bool isRowEmpty(const unsigned r) const;
	bool isElementEmpty(const Point rc) const;

	// rename -> readPositionFromCin ?
	Matrix &setCursor();
	// private ?
	// rename -> readPosition ?
	Matrix &setCursor(istream &is);

	// private ?
	// rename -> readElement ?
	Matrix &setElement(istream &is);
	Matrix &setElement(const unsigned u);
	// rename -> readElementFromCin ?
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

	bool isElementInMatrix(unsigned u) const;

private:
	vv_unsigned elements;
	Point cursor;
};