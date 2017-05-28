#pragma once

#include "Matrix.h"
#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;


class Sudoku {
private:
	using v_unsigned = vector<unsigned>;
	using vv_unsigned = vector<vector<unsigned>>;

public:
	Sudoku() = default;
	Sudoku(const vv_unsigned &vv) : data(vv) {} 

	void printSudoku() const;

private:
	Matrix data; 
	void printRow(const v_unsigned &row) const;
	const short nrRows = 9;
};
