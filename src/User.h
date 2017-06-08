#pragma once
#include <string>
#include <vector>
#include "Point.h"

using std::string;
using std::vector;

namespace user {
    int getElementFromCin(bool isElementNotInRange(int));
    Point getPositionFromCin(bool isPositionNotInRange(Point), const vector<Point> &originalGrid = {}); 
}