#pragma once

#include <iostream>
#include <vector>
#include "Matrix.h"

using std::cout;
using std::endl;
using std::vector;


class Sudoku {

friend bool remainder(const unsigned &i); 
friend void printDivider();
friend void printRow(const vector<unsigned> &row);

private:
	using vv_unsigned = vector<vector<unsigned>>;

public:
	Sudoku() = default;
	Sudoku(const Matrix &M) : elements(M.returnElements()) {}  
	void printSudoku() const;

private:
	vv_unsigned elements;
	static constexpr short nrRows = 9;
};