#pragma once

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Matrix {
public:
	Matrix() = default;
	Matrix(const vector<vector<unsigned>> &v) : elements(v) {}

	const vector<vector<unsigned>> &returnElements() const {
		return elements; 		
	}
	vector<vector<unsigned>> &returnElements() {
		return elements;
	}

	void printElements() const {
		for(const auto &row : elements) {
			for(const auto &e : row) {
				cout << e << " ";
			}
		cout << endl;
		}
	}

private:
	vector<vector<unsigned>> elements;
	vector<unsigned> cursor{1, 1};

};