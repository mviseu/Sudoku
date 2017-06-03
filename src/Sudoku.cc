#include "Sudoku.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::invalid_argument;


namespace {
	void printOneElement(const int &u) {
		if(u != 0) {
			cout << u;
		} else {
			cout << " ";
		}
	}

	bool isSeparatorNeeded(const int &i, const int nrElements) {
		return (i % 3 == 2 && i != nrElements - 1);
	}

	void printDivider(const int nrElements) {
		for(int i = 0; i != nrElements; ++i) {
			cout << (isSeparatorNeeded(i, nrElements) ? "- + " : "- ");
		}
	}

	ostream &announcePrintSudoku(ostream &os) {
		os << "Here is your grid:" << endl;
		return os;
	}

	ostream &warnInvalidElement(ostream &os) {
		os << "Oh dear... The value is invalid." << endl;
		return os;
	}
	ostream &warnInvalidPosition(ostream &os) {
		os << "Think again... The position is invalid." << endl;
		return os;
	}
	ostream &warnDuplicateInRow(ostream &os) {
		os << "Pay attention! This number is already in the same row." << endl;
		return os;
	}
	ostream &warnDuplicateInColumn(ostream &os) {
		os << "Pay attention! This number is already in the same column." << endl;
		return os;
	}
	ostream &warnDuplicateInSubSquare(ostream &os) {
		os << "Pay attention! This number is already in the same square block." << endl;
		return os;
	}
}

void Sudoku::printRow(const v_int &row) const {
	const auto beg = row.cbegin();
	for(auto iter = beg; iter != beg + nrRows; ++iter) {
		printOneElement(*iter);
		if(isSeparatorNeeded(iter - beg, nrRows)) {
			cout << " |";
		}
		cout << " ";
	}
}

Sudoku &Sudoku::doPrintSudoku() const {
	const auto beg = data.cbegin();
	for(auto iter = beg; iter != beg + nrRows; ++iter) {
		printRow(*iter);
		if(isSeparatorNeeded(iter - beg, nrRows)) {
			cout << endl;
			printDivider(nrRows);
		} 
		cout << endl;
	}
	return const_cast<Sudoku &>(*this);
}

bool Sudoku::isElementInvalid() const {
	if(data.getElement() > 9 || data.getElement() < 1) {
		return true;
	} 
	return false;
}

bool Sudoku::isPositionInvalid() const {
	if(data.getCursorRow() > 8 || data.getCursorRow() < 0 ||
	   data.getCursorColumn() > 8 || data.getCursorColumn() < 0) {
		return true;
	}
	return false;
}

void Sudoku::readValidElementFromCin() {
	while(isElementInvalid()) {
		warnInvalidElement(cout);
		data.readElementFromCin();
	}
}

void Sudoku::readValidPositionFromCin() {
	while(isPositionInvalid()) {
		warnInvalidPosition(cout);
		data.readPositionFromCin();
	}
}

Sudoku &Sudoku::readPositionAndElementFromCin() {
	bool isPossibleExceptionPosition = true;
	while(isPossibleExceptionPosition == true) {
		try  {
			data.readPositionFromCin();
			readValidPositionFromCin();
			isPossibleExceptionPosition = false;

		} catch(invalid_argument err) {
			cout << "Invalid argument" << endl;
		}
	}
	bool isPossibleExceptionElement = true;
	while(isPossibleExceptionElement == true) {
		try  {
			data.readElementFromCin();
			readValidElementFromCin();
			isPossibleExceptionElement = false;

		} catch(invalid_argument err) {
			cout << "Invalid argument" << endl;
		}
	}
	return *this;
}

bool Sudoku::isValueDuplicateOfCursorElement(int cursorIndex, v_int::const_iterator beg, 
											 v_int::const_iterator iter) const {
	return iter - beg != cursorIndex && *iter == data.getElement();
}

bool Sudoku::isDuplicateInCursorVector(int cursorIndex, const vector<int> &v) const {
	const auto beg = v.cbegin();
	for(auto iter = beg; iter != v.cend(); ++iter) {
		if(isValueDuplicateOfCursorElement(cursorIndex, beg, iter)) {
			return true;
		}
	}
	return false;
}

bool Sudoku::isDuplicateInRow() const {
	return isDuplicateInCursorVector(data.getCursorColumn(), data.getRow());
}

bool Sudoku::isDuplicateInColumn() const {
	return isDuplicateInCursorVector(data.getCursorRow(), data.getColumn());
}

bool Sudoku::isDuplicateInSubSquare() const {
	return isDuplicateInCursorVector(data.getCursorSubSquarePositionInVector(), data.getSubSquare());
}

bool Sudoku::isDuplicateInRowOrColumnOrSubSquare() const {
	return isDuplicateInRow() || isDuplicateInColumn() || isDuplicateInSubSquare() ;	
}

void Sudoku::warnDuplicateMove() const {
	if(isDuplicateInRow()) {
		warnDuplicateInRow(cout);
	}
	if(isDuplicateInColumn()) {
		warnDuplicateInColumn(cout);
	}
	if(isDuplicateInSubSquare()) {
		warnDuplicateInSubSquare(cout);
	}
}

const Sudoku &Sudoku::printSudoku() const {
	announcePrintSudoku(cout);
	return doPrintSudoku();
}

Sudoku &Sudoku::printSudoku() {
	announcePrintSudoku(cout);
	return doPrintSudoku();
}

Sudoku &Sudoku::playOneMove() {
	readPositionAndElementFromCin();
	if(isDuplicateInRowOrColumnOrSubSquare()) {
		warnDuplicateMove();
		data.readElement(0);
	}
	return *this;
}

bool Sudoku::isGameOver() const {
	return !data.isElementInMatrix(0);
}
