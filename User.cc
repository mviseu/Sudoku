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

int provideValidElementFromInputStream() {
    int i = 0;
    string s;
    getline(cin, s);
    vector<string> tokens = splitGetLineString(s);
    //incorrect number os inputs
    if(tokens.size() != 1) {
        cout << "Invalid number of arguments. Please repeat." << endl;
        provideValidElementFromInputStream();
    //iostream error (character arguments)
    //domain range error
    } else {
        try {
            i = stoi(tokens[0]);
            bool (*fp) (int) = isElementInvalid;
            if(isElementRangeInvalid(i, fp)) {
                //user provides out of range value
                cout << "The argument is out of range. Please repeat" << endl;
                provideValidElementFromInputStream();
            }
        } catch (invalid_argument err) {
            //user provides char
            cout << "Invalid argument. Please repeat." << endl;
            provideValidElementFromInputStream();
        }

    }
    return i;
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

bool isElementInvalid(int i) {
    if(i > 9 || i < 1) {
        return true;
    } 
    return false;
}

bool isElementRangeInvalid(int i, bool fp(int)) {
    return fp(i);
}

int main() {
    provideValidElementFromInputStream();
    return 0;
}