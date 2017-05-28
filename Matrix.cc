#include "Matrix.h"
#include <iostream>

using std::istream;

Matrix::vv_unsigned::const_iterator Matrix::cbegin() const {
	return elements.cbegin();
}

istream &Matrix::readCursor(istream &is) {
	unsigned r, c;
	is >> r >> c;
	//is there a better way to do this?
	//convert from user input to base 0
	cursor.row = convertBase1to0(r);
	cursor.column = convertBase1to0(c);
	return is;
}

istream &Matrix::changeElement(istream &is) {
	unsigned e;
	is >> e;
	elements[cursor.row][cursor.column] = e;
	return is;
}
