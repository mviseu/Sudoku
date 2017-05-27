#include "Matrix.h"
#include "Sudoku.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<vector<unsigned>> vec =
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
	Matrix M(vec);

	//M.printElements();
	Sudoku S(M);

	S.printSudoku();

	/*to do
	1) Move static "rows" to sudoku.cc
	2) Remove friend functions
	3) Consider replacing iterators with a simple approach (indexed?)*/

	return 0;
}