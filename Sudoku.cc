#include "Sudoku.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

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
}

void Sudoku::printRow(const v_unsigned &row) const {
	const auto Beg = row.cbegin();
	const auto End = Beg + nrRows;
	auto iter = Beg;
	while(iter != End) {
		auto d = iter - Beg;
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

bool Sudoku::isDuplicate(const v_unsigned::const_iterator iter, const v_unsigned::const_iterator Beg) const {
	return iter - Beg != data.getCursorColumn() && *iter == data.getElement();
}

bool Sudoku::isDuplicateInRow() const {
	const auto Beg = data.getRow().cbegin();
	const auto End = data.getRow().cend();
	auto iter = Beg;
	while(iter != End) {
		if(isDuplicate(iter, Beg)) {
			return true;
		}
		++iter;
	}
	return false;
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
	return *this;
}
