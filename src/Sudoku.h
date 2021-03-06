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
	Sudoku(const vv_int &vv) : data(vv) {originalGrid = getOriginalPositions();} 

	const Sudoku &printSudoku() const;
	Sudoku &printSudoku(); 
	Sudoku &playOneMove();
	bool isGameOver() const;

private:
	Matrix data; 
	vector<Point> originalGrid;
	vector<Point> getOriginalPositions() const;
	
	void printRow(const v_int &row) const;
	Sudoku &doPrintSudoku() const;

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
