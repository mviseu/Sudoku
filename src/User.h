#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

int provideValidElementFromInputStream(bool fp(int));
int providValidElementFromArgument(const string &s, bool fp(int)); 
vector<string> splitGetLineString(const string &s);
bool isElementInvalid(int i);
void repeatReadIfArgumentInvalid(bool fp(int));