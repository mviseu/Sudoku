#pragma once

#include "Matrix.h"
#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::ostream;
using std::vector;


class Sudoku {
private:
	using v_int = vector<int>;
	using vv_int = vector<vector<int>>;

public:
	Sudoku() = default; 
	Sudoku(const vv_int &vv) : data(vv) {} 

	const Sudoku &printSudoku() const;
	Sudoku &printSudoku(); 
	Sudoku &playOneMove();
	bool isGameOver() const;

private:
	Matrix data; 
	void printRow(const v_int &row) const;
	Sudoku &doPrintSudoku() const;

	bool isPositionInvalid() const;
	void readValidElementFromCin();
	void readValidPositionFromCin();
	Sudoku &readPositionAndElementFromCin();

	bool isDuplicateInRow() const;
	bool isDuplicateInColumn() const; 
	bool isDuplicateInSubSquare() const;
	bool isDuplicateInRowOrColumnOrSubSquare() const; 

	bool isValueDuplicateOfCursorElement(int cursorIndex, v_int::const_iterator Beg, v_int::const_iterator iter) const;
	bool isDuplicateInCursorVector(int cursorIndex, const vector<int> &v) const;

	void warnDuplicateMove() const;
	const short nrRows = 9;
};
