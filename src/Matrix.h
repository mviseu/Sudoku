#pragma once

#include <vector>
#include <iostream>
#include "Point.h"

using std::vector;
using std::istream;
using std::cout;
using std::endl;

class Matrix {
public:
	using v_int = vector<int>;
	using vv_int = vector<vector<int>>;

	Matrix() = default; 
	Matrix(const vv_int &v) : elements(v) {}


	bool isMatrixSquare() const;
	int getNrRows() const;
	int getNrColumns() const;
	int getSubSquareDimension() const;

	bool isRowEmpty(const int r) const;
	bool isElementEmpty(const Point rc) const;

	Matrix &readPosition(istream &is);
	Matrix &readPositionFromCin();


	Matrix &readElement(istream &is);
	Matrix &readElement(const int u);
	Matrix &readElementFromCin();
	
	vv_int::const_iterator cbegin() const;

	int getElement() const;
	int getCursorColumn() const;
	int getCursorRow() const;
	Point getCursorSubSquare() const;
	int getCursorSubSquarePositionInVector() const;


	v_int getRow() const;
	v_int getColumn() const;
	v_int getSubSquare() const;

	bool isElementInMatrix(int u) const;

private:
	v_int &addSubSquareRow(const vv_int::const_iterator subSquareRowIter, v_int &subSquare) const; 
	vv_int elements;
	Point cursor;
};