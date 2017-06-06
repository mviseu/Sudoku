#pragma once
#include <string>
#include <vector>
#include "Point.h"

using std::string;
using std::vector;

namespace user {
    int provideValidElementFromInputStream(bool isElementRangeInvalidPr(int));
    Point provideValidPositionFromInputStream(/*bool (*isPositionInvalidPr)(Point)*/);
}