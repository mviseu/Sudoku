#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

int provideValidElementFromInputStream();
vector<string> splitGetLineString(const string &s);
bool isElementInvalid(int i);
bool isElementRangeInvalid(int i, bool fp(int));