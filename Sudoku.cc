#include "Sudoku.h"
#include <iostream>

using std::cout;
using std::endl;

void printOneElement(const unsigned &u) {
	if(u != 0) {
		cout << u;
	} else {
		cout << " ";
	}
}

bool remainder(const unsigned &i) {
	return (i % 3 == 0 && i != Sudoku::nrRows);
}

void printDivider() {
	for(auto i = 1; i != Sudoku::nrRows + 1; ++i) {
		cout << (remainder(i) ? "- + " : "- ");
	}
}

void printRow(const vector<unsigned> &row) {
	auto Beg = row.cbegin();
	const auto End = Beg + Sudoku::nrRows;
	auto iter = Beg;
	while(iter != End) {
		auto d = iter - Beg + 1;
		printOneElement(*iter);
		if(remainder(d)) {
			cout << " |";
		}
		cout << " ";
		++iter;
	}
}

void Sudoku::printSudoku() const {
	auto Beg = elements.cbegin();
	const auto End = Beg + nrRows;
	auto iter = Beg;
	while(iter != End) {
		auto d = iter - Beg + 1;
		printRow(*iter);
		if(remainder(d)) {
			cout << endl;
			printDivider();
		} 
		cout << endl;
		++iter;
	}
}
