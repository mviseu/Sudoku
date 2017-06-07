#include "Matrix.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::sqrt;
using std::string;
using std::stoi;

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

int Matrix::getNrRows() const {
	return elements.size();
}

int Matrix::getNrColumns() const {
	if(!elements.empty()) {
		return elements[0].size(); 
	} else {
		return 0;
	}
}

bool Matrix::isMatrixSquare() const {
	return getNrColumns() == getNrRows();
}

int Matrix::getSubSquareDimension() const {
	if(isMatrixSquare()) {
		return sqrt(getNrRows());
	} else {
		return 0;
	}
}

Matrix &Matrix::setPosition(Point xy) {
	cursor.row = xy.row;
	cursor.column = xy.column;
	return *this;
}

Matrix &Matrix::readPosition(istream &is) {
	int r, c ;
	is >> r >> c;
	cursor.row = r;
	cursor.column = c;
	return *this;
}

Matrix &Matrix::readPositionFromCin() {
	printChangeCursor(cout);
	readPosition(cin);
	return *this;
}

bool Matrix::isRowEmpty(const int r) const {
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

Matrix & Matrix::readElement(const int u) {
	if(!isElementEmpty(cursor)) {
		elements[cursor.row][cursor.column] = u;
	}
	return *this;
}

Matrix &Matrix::readElement(istream &is) {
	int e;
	is >> e;
	return readElement(e);
}

Matrix &Matrix::readElementFromCin() {
	printChangeElement(cout);
	readElement(cin);
	return *this;
}

Matrix::vv_int::const_iterator Matrix::cbegin() const {
	return elements.cbegin();
}

Matrix::vv_int::const_iterator Matrix::cend() const {
	return elements.cend();
}

int Matrix::getElement() const {
	if(!isElementEmpty(cursor)) {
		return elements[cursor.row][cursor.column];
	}
	return 0; //error handling??
}

int Matrix::getCursorRow() const {
	return cursor.row;
}

int Matrix::getCursorColumn() const {
	return cursor.column;
}

int Matrix::getCursorSubSquarePositionInVector() const {
	int vectorPosition{0}; 
	int dimension = getSubSquareDimension();
	if(dimension) {
		vectorPosition = cursor.row % dimension * dimension + cursor.column % dimension;
	}
	return vectorPosition;
}

Point Matrix::getCursorSubSquare() const {
	Point xy;
	int dimension = getSubSquareDimension();
	if(dimension) {
		xy.row = cursor.row / dimension;
		xy.column = cursor.column / dimension;
	}
	return xy;
}

Matrix::v_int Matrix::getRow() const {
    if(!isRowEmpty(cursor.row)) {
		return elements[cursor.row];
	}
	return {};
}


Matrix::v_int Matrix::getColumn() const {
	v_int v;
	for(auto rowIter = elements.cbegin(); rowIter < elements.cend(); ++rowIter) {
		const Point xy(rowIter - elements.cbegin(), cursor.column);
		if(!isElementEmpty(xy)) {
			const auto iterElem = rowIter -> cbegin() + cursor.column;
			v.push_back(*iterElem);
		}
	}
	return v;
}

Matrix::v_int Matrix::getSubSquare() const {
	v_int v;
	int dimension = getSubSquareDimension();
	const auto begSubSquareRowIter = elements.cbegin() + getCursorSubSquare().row * dimension;
	for(auto i = begSubSquareRowIter; i < begSubSquareRowIter + dimension; ++i) {
		addSubSquareRow(i, v);
	}
	return v;
}

Matrix::v_int &Matrix::addSubSquareRow(const vv_int::const_iterator subSquareRowIter, v_int &subSquare) const {
	int dimension = getSubSquareDimension();
	const auto begSubSquareElemIter = subSquareRowIter -> cbegin() + getCursorSubSquare().column * dimension;
	for(auto j = begSubSquareElemIter; j < begSubSquareElemIter + dimension; ++j) {
		subSquare.push_back(*j);
	}
	return subSquare;
}


bool Matrix::isElementInMatrix(int u) const {
	for(const auto &row : elements) {
		for(const auto &elem : row) {
			if(elem == u) {
				return true; 
			}
		}
	}
	return false;
}
