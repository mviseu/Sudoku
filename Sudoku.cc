#include "Sudoku.h"
#include <iostream>
#include <vector>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

namespace {
	void printOneElement(const unsigned &u) {
		if(u != 0) {
			cout << u;
		} else {
			cout << " ";
		}
	}

	bool isSeparatorNeeded(const unsigned &i, const unsigned nrElements) {
		return (i % 3 == 2 && i != nrElements - 1);
	}

	void printDivider(const unsigned nrElements) {
		for(unsigned i = 0; i != nrElements; ++i) {
			cout << (isSeparatorNeeded(i, nrElements) ? "- + " : "- ");
		}
	}

	ostream &announcePrintSudoku(ostream &os) {
		os << "Here is your grid:" << endl;
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

void Sudoku::printRow(const v_unsigned &row) const {
	const auto Beg = row.cbegin();
	const auto End = Beg + nrRows;
	auto iter = Beg;
	while(iter != End) {
		auto d = iter - Beg; // unnecessary variable?
		printOneElement(*iter);
		if(isSeparatorNeeded(d, nrRows)) {
			cout << " |";
		}
		cout << " ";
		++iter;
	}
}

Sudoku &Sudoku::doPrintSudoku() const {
	const auto Beg = data.cbegin();
	const auto End = Beg + nrRows;
	auto iter = Beg;
	while(iter != End) {
		auto d = iter - Beg; 
		printRow(*iter);
		if(isSeparatorNeeded(d, nrRows)) {
			cout << endl;
			printDivider(nrRows);
		} 
		cout << endl;
		++iter;
	}
	return const_cast<Sudoku &>(*this);
}

bool Sudoku::isValueDuplicateOfCursorElement(unsigned cursorIndex, v_unsigned::const_iterator Beg, 
											 v_unsigned::const_iterator iter) const {
	return iter - Beg != cursorIndex && *iter == data.getElement();
}

bool Sudoku::isDuplicateInCursorVector(unsigned cursorIndex, const vector<unsigned> &v) const {
	const auto Beg = v.cbegin();
	const auto End = v.cend();
	auto iter = Beg;
	while(iter != End) { // Why not iterator based for loop ?
		if(isValueDuplicateOfCursorElement(cursorIndex, Beg, iter)) {
			return true;
		}
		++iter;
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
	data.setCursor().setElement();
	if(isDuplicateInRowOrColumnOrSubSquare()) {
		warnDuplicateMove();
		data.setElement(0);
	}
	return *this;
}

bool Sudoku::isGameOver() const {
	return !data.isElementInMatrix(0);
}
