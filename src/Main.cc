#include "Matrix.h"
#include "Sudoku.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	vector<vector<int>> vec =/*
	{
		{0,0,0,2,6,0,7,0,1},
		{6,8,0,0,7,0,0,9,0},
		{1,9,0,0,0,4,5,0,0},
		{8,2,0,1,0,0,0,4,0},
		{0,0,4,6,0,2,9,0,0},
		{0,5,0,0,0,3,0,2,8},
		{0,0,9,3,0,0,0,7,4},
		{0,4,0,0,5,0,0,3,6},
		{7,0,3,0,1,8,0,0,0},
	};
*/
	{
		{0,2,3,4,5,6,7,8,9},
		{4,5,6,7,8,9,1,2,3},
		{7,8,9,1,2,3,4,5,6},
		{2,3,4,5,6,7,8,9,1},
		{5,6,7,8,9,1,2,3,4},
		{8,9,1,2,3,4,5,6,7},
		{3,4,5,6,7,8,9,1,2},
		{6,7,8,9,1,2,3,4,5},
		{9,1,2,3,4,5,6,7,8},
	}; 

	Sudoku S(vec);
	cout << "Welcome to Sudoku!\n";
	while(!S.isGameOver()) {
		S.printSudoku();
		S.playOneMove();
	}
	cout << "Congratulations! You are a genius!!" << endl; 
	return 0;
}