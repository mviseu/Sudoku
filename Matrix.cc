#include "Matrix.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;

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
};

unsigned Matrix::getCursorColumn() const {
	return cursor.column;
};

Matrix::v_unsigned Matrix::getRow() const {
	return elements[cursor.row];
}
;