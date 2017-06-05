#include "User.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>

using std::invalid_argument;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::stoi;

int provideValidElementFromInputStream(bool fp(int)) {
	cout << "Provide the new value" << endl;
    string s;
    std::getline(std::cin, s);
    vector<string> tokens = splitGetLineString(s);
    if(tokens.size() != 1) {
        repeatReadIfArgumentInvalid(fp);
    } else {
        return providValidElementFromArgument(tokens[0], fp);
    }
    return 0;
}

int providValidElementFromArgument(const string &s, bool fp(int)) {
    try {
        int i = stoi(s);
        bool b = fp(i);
        if(b) {
            repeatReadIfArgumentInvalid(fp);
        }
        return i;
    } catch (invalid_argument err) {
        repeatReadIfArgumentInvalid(fp);
    }
    return 0;
}

void repeatReadIfArgumentInvalid(bool fp(int)) {
    cout << "Invalid argument. Please repeat." << endl;
    provideValidElementFromInputStream(fp);
}

vector<string> splitGetLineString(const string &s) {
    vector<string> tokens;
    tokens.push_back("");
    for(const auto &c : s) {
        if(isspace(c)) {
            if (!tokens.back().empty()) {
                tokens.push_back("");
            }
        } else {
            tokens.back() += c;
        }
    }
    if (tokens.back().empty()) {
        tokens.pop_back();
    }
    return tokens;
}