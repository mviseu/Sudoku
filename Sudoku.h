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
	using v_unsigned = vector<unsigned>;
	using vv_unsigned = vector<vector<unsigned>>;

public:
	Sudoku() = default; 
	Sudoku(const vv_unsigned &vv) : data(vv) {} 

	const Sudoku &printSudoku() const;
	Sudoku &printSudoku(); 
	Sudoku &playOneMove();
	bool isGameOver() const;

private:
	Matrix data; 
	void printRow(const v_unsigned &row) const;
	Sudoku &doPrintSudoku() const;

	bool isDuplicateInRow() const;
	bool isDuplicateInColumn() const; 
	bool isDuplicateInSubSquare() const;
	bool isDuplicateInRowOrColumnOrSubSquare() const; 

	bool isValueDuplicateOfCursorElement(unsigned cursorIndex, v_unsigned::const_iterator Beg, v_unsigned::const_iterator iter) const;
	bool isDuplicateInCursorVector(unsigned cursorIndex, const vector<unsigned> &v) const;

	void warnDuplicateMove() const;

	const short nrRows = 9;
};
