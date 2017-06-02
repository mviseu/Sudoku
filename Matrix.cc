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

unsigned Matrix::getDimensionSubSquare() const {
	if(isMatrixSquare()) {
		return sqrt(getNrRows());
	} else {
		return 0;
	}
}

Matrix &Matrix::setCursor(istream &is) {
	unsigned r, c;
	is >> r >> c;
	cursor.row = convertBase1to0(r);
	cursor.column = convertBase1to0(c);
	return *this;
}

Matrix &Matrix::setCursor() {
	printChangeCursor(cout);
	setCursor(cin);
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

Matrix & Matrix::setElement(const unsigned u) {
	if(!isElementEmpty(cursor)) {
		elements[cursor.row][cursor.column] = u;
	}
	return *this;
}

Matrix &Matrix::setElement(istream &is) {
	unsigned e;
	is >> e;
	return setElement(e);
}

Matrix &Matrix::setElement() {
	printChangeElement(cout);
	setElement(cin);
	return *this;
}

Matrix::vv_unsigned::const_iterator Matrix::cbegin() const {
	return elements.cbegin();
}

unsigned Matrix::getElement() const {
	// unsafe (empty vector)
	if(!isElementEmpty(cursor)) {
		return elements[cursor.row][cursor.column];
	}
	return 0; //error handling??
}

// For 2 next functions, may make sense to only return the cursor
// (client can always getCursor().row if they want)
unsigned Matrix::getCursorRow() const {
	return cursor.row;
}

unsigned Matrix::getCursorColumn() const {
	return cursor.column;
}

unsigned Matrix::getCursorSubSquarePositionInVector() const {
	unsigned vectorPosition{0}; 
	unsigned dimension = getDimensionSubSquare();
	if(dimension) {
		vectorPosition = cursor.row % dimension * dimension + cursor.column % dimension;
	}
	return vectorPosition;
}

Point Matrix::getCursorSubSquare() const {
	Point xy;
	unsigned dimension = getDimensionSubSquare();
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

//evaluate const auto to see if it is putting the high-level or low-level const

Matrix::v_unsigned Matrix::getSubSquare() const {
	v_unsigned v;
	Point xy = getCursorSubSquare();
	unsigned dimension = getDimensionSubSquare();
	// could split for less nesting/ better readibility
	if (dimension) {
		const auto begSubSquareRowIter = elements.cbegin() + xy.row * dimension;
		for(auto i = begSubSquareRowIter; i < begSubSquareRowIter + dimension; ++i) {
			/*
			<vv_unsigned>::const_iter getSubSquareRowBegIter() const
			<v_unsigned> getSubSquareElemBegIter(const <vv_unsigned>::const_iter subSquareRowBegIter) const

*/			const auto begSubSquareElemIter = i -> cbegin() + xy.column * dimension;
			for(auto j = begSubSquareElemIter; j < begSubSquareElemIter + dimension; ++j) {
				v.push_back(*j);
			}
		}
	}
	return v;
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
