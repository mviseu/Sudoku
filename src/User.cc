#include "User.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include "Point.h"

using std::invalid_argument;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::begin;
using std::stoi;
using std::istream;

namespace {

    void reprompt() {
        cout << "Invalid argument. Please repeat!" << endl;    
    }

    string repromptString() {
        return "Invalid argument. Please repeat!\n";        
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

    vector<string> getTokens(istream &is) {
        string line;
        getline(is, line);
        return splitGetLineString(line);
    }
}

namespace user {
    int providValidElementFromScalarArgument(const string &s, bool isElementRangeInvalidPr(int)) {
        try {
            string::size_type positionAfterInt;
            int i = stoi(s, &positionAfterInt);
            if(s.cbegin() + positionAfterInt != s.cend()) {
                throw invalid_argument(repromptString());
            }
            if(!isElementRangeInvalidPr(i)) {
                return i;
            }
        } catch (invalid_argument err) {
            // error case handled below
        }
        reprompt();
        return provideValidElementFromInputStream(isElementRangeInvalidPr);
    }
    int provideValidElementFromInputStream(bool isElementRangeInvalidPr(int)) {
        cout << "Provide the new value" << endl;
        vector<string> tokens = getTokens(cin);
        if(tokens.size() != 1) {
            reprompt();
            return provideValidElementFromInputStream(isElementRangeInvalidPr);
        } else {
            return providValidElementFromScalarArgument(tokens[0], isElementRangeInvalidPr);
        }
    }


    // Point provideValidPositionFromInputStream(/*bool (*isPositionInvalidPr)(Point)*/) {
    //     cout << "Provide the row and column positions (0 based)" << endl;
    //     auto firstLineTokens = getTokens(cin);
    //     if(firstLineTokens.size() == 1) {
    //         auto secondLineTokens = getTokens(cin);
    //         if(secondLineTokens.size() != 1) {
    //             repromt();
    //             return provideValidPositionFromInputStream();
    //         }
    //     } else if(firstLineTokens.size() == 2) {

    //     } else {
    //         repromt();
    //         return provideValidPositionFromInputStream();
    //     }
        
    //     return {'0', '1'};
    // } 
 
} 


