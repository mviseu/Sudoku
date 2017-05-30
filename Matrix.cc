#include "Matrix.h"
#include <cmath>
#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::sqrt;

namespace {
	ostream &annouceChangeCursor(ostream &os) {
		os << "Provide the row and column of the cell you would like to change" << endl;
		return os;
	}
	ostream &annouceChangeElement(ostream &os) {
		os << "Provide the new value" << endl;
		return os;
	}
}

istream &Matrix::readCursor(istream &is) {
	unsigned r, c;
	is >> r >> c;
	cursor.row = convertBase1to0(r);
	cursor.column = convertBase1to0(c);
	return is;
}

istream &Matrix::readElement(istream &is) {
	unsigned e;
	is >> e;
	elements[cursor.row][cursor.column] = e;
	return is;
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
	return getNrColumns() == getNrColumns();
}


Matrix &Matrix::setCursor() {
	annouceChangeCursor(cout);
	readCursor(cin);
	return *this;
}

Matrix &Matrix::setElement() {
	annouceChangeElement(cout);
	readElement(cin);
	return *this;
}

Matrix::vv_unsigned::const_iterator Matrix::cbegin() const {
	return elements.cbegin();
}

unsigned Matrix::getElement() const {
	return elements[cursor.row][cursor.column];
}

unsigned Matrix::getCursorRow() const {
	return cursor.row;
}

unsigned Matrix::getCursorColumn() const {
	return cursor.column;
}

Point Matrix::getCursorSubSquare() const {
	Point xy;
	xy.row = cursor.row / 3;
	xy.column = cursor.column / 3;
	return xy;
}

Matrix::v_unsigned Matrix::getRow() const {
	return elements[cursor.row];
}

Matrix::v_unsigned Matrix::getColumn() const {
	v_unsigned v;
	for(const auto &row : elements) {
		v.push_back(row[cursor.column]);
	}
	return v;
}

Matrix::v_unsigned Matrix::getSubSquare() const {
	v_unsigned v;
	Point xy = getCursorSubSquare();
	if (isMatrixSquare()) {
		const auto subSquareSize = sqrt(getNrRows());
		const auto begSubSquareRowIter = elements.cbegin() + xy.row * subSquareSize;
		for(auto i = begSubSquareRowIter; i < begSubSquareRowIter + subSquareSize; ++i) {
			const auto begSubSquareElemIter = i -> cbegin() + xy.column * subSquareSize;
			for(auto j = begSubSquareElemIter; j < begSubSquareElemIter + subSquareSize; ++i) {
				v.push_back(*j);
			}
		}
	}
	return v;
}
