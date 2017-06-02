#include "Matrix.h"
#include <cmath>
#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::sqrt;

namespace {
	ostream &printChangeCursor(ostream &os) {
		os << "Provide the row and column of the cell you would like to change" << endl;
		return os;
	}
	ostream &printChangeElement(ostream &os) {
		os << "Provide the new value" << endl;
		return os;
	}
}

unsigned Matrix::getNrRows() const {
	return elements.size();
}

unsigned Matrix::getNrColumns() const {
	if(!elements.empty()) {
		return elements[0].size(); 
	} else {
		return 0;
	}
}

bool Matrix::isMatrixSquare() const {
	return getNrColumns() == getNrRows();
}

unsigned Matrix::getSubSquareDimension() const {
	if(isMatrixSquare()) {
		return sqrt(getNrRows());
	} else {
		return 0;
	}
}

Matrix &Matrix::readPosition(istream &is) {
	unsigned r, c;
	is >> r >> c;
	cursor.row = convertBase1to0(r);
	cursor.column = convertBase1to0(c);
	return *this;
}

Matrix &Matrix::readPositionFromCin() {
	printChangeCursor(cout);
	readPosition(cin);
	return *this;
}


bool Matrix::isRowEmpty(const unsigned r) const {
	if(elements.cbegin() + r < elements.cend()) {
		return false;
	}
	return true;
}

bool Matrix::isElementEmpty(const Point rc) const {
	if(!isRowEmpty(rc.row)) {
		const auto &r = elements[rc.row];
		if(r.cbegin() + getCursorColumn() < r.cend()) {
			return false;
		}
	}
	return true;
}

Matrix & Matrix::readElement(const unsigned u) {
	if(!isElementEmpty(cursor)) {
		elements[cursor.row][cursor.column] = u;
	}
	return *this;
}

Matrix &Matrix::readElement(istream &is) {
	unsigned e;
	is >> e;
	return readElement(e);
}

Matrix &Matrix::readElementFromCin() {
	printChangeElement(cout);
	readElement(cin);
	return *this;
}

Matrix::vv_unsigned::const_iterator Matrix::cbegin() const {
	return elements.cbegin();
}

unsigned Matrix::getElement() const {
	if(!isElementEmpty(cursor)) {
		return elements[cursor.row][cursor.column];
	}
	return 0; //error handling??
}

unsigned Matrix::getCursorRow() const {
	return cursor.row;
}

unsigned Matrix::getCursorColumn() const {
	return cursor.column;
}

unsigned Matrix::getCursorSubSquarePositionInVector() const {
	unsigned vectorPosition{0}; 
	unsigned dimension = getSubSquareDimension();
	if(dimension) {
		vectorPosition = cursor.row % dimension * dimension + cursor.column % dimension;
	}
	return vectorPosition;
}

Point Matrix::getCursorSubSquare() const {
	Point xy;
	unsigned dimension = getSubSquareDimension();
	if(dimension) {
		xy.row = cursor.row / dimension;
		xy.column = cursor.column / dimension;
	}
	return xy;
}

Matrix::v_unsigned Matrix::getRow() const {
    if(!isRowEmpty(cursor.row)) {
		return elements[cursor.row];
	}
	return {};
}


Matrix::v_unsigned Matrix::getColumn() const {
	v_unsigned v;
	for(auto rowIter = elements.cbegin(); rowIter < elements.cend(); ++rowIter) {
		const Point xy(rowIter - elements.cbegin(), cursor.column);
		if(!isElementEmpty(xy)) {
			const auto iterElem = rowIter -> cbegin() + cursor.column;
			v.push_back(*iterElem);
		}
	}
	return v;
}

Matrix::v_unsigned Matrix::getSubSquare() const {
	v_unsigned v;
	unsigned dimension = getSubSquareDimension();
	const auto begSubSquareRowIter = elements.cbegin() + getCursorSubSquare().row * dimension;
	for(auto i = begSubSquareRowIter; i < begSubSquareRowIter + dimension; ++i) {
		addSubSquareRow(i, v);
	}
	return v;
}

Matrix::v_unsigned &Matrix::addSubSquareRow(const vv_unsigned::const_iterator subSquareRowIter, v_unsigned &subSquare) const {
	unsigned dimension = getSubSquareDimension();
	const auto begSubSquareElemIter = subSquareRowIter -> cbegin() + getCursorSubSquare().column * dimension;
	for(auto j = begSubSquareElemIter; j < begSubSquareElemIter + dimension; ++j) {
		subSquare.push_back(*j);
	}
	return subSquare;
}


bool Matrix::isElementInMatrix(unsigned u) const {
	for(const auto &row : elements) {
		for(const auto &elem : row) {
			if(elem == u) {
				return true; 
			}
		}
	}
	return false;
}
