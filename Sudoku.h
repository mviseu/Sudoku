#pragma once

#include "Matrix.h"
#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::iostream;
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
	//for now as public for debug
	bool isDuplicateInRow() const;

private:
	Matrix data; 
	void printRow(const v_unsigned &row) const;
	Sudoku &doPrintSudoku() const;
	bool isDuplicate(const v_unsigned::const_iterator iter, const v_unsigned::const_iterator Beg) const;

	const short nrRows = 9;
};
