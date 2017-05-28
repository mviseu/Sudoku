#include "Sudoku.h"
#include <iostream>

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

void Sudoku::printSudoku() const {
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
}
