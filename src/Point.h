#pragma once
struct Point {
	Point() = default;
	Point(const int r, const int c) : row(r), column(c) {}
	int row = 0;
	int column = 0;
};

