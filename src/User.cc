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

    int parseSingleInt(const string &s) {
        string::size_type positionAfterInt{0};
        auto i = stoi(s, &positionAfterInt);
        if(s.cbegin() + positionAfterInt != s.cend()) {
            throw invalid_argument(repromptString());
        }
        return i;        
    }

    int getValidElement(const string &s, bool isElementNotInRange(int)) {
        int i;
        try {
            i = parseSingleInt(s);
        } catch (invalid_argument err) {
            reprompt();
            return getElementFromCin(isElementNotInRange);
        }
        if(isElementNotInRange(i)) {
            reprompt();
            return getElementFromCin(isElementNotInRange);
        }
        return i;
    }

    int getElementFromCin(bool isElementNotInRange(int)) {
        cout << "Provide the new value" << endl;
        vector<string> tokens = getTokens(cin);
        if(tokens.size() != 1) {
            reprompt();
            return getElementFromCin(isElementNotInRange);
        } else {
            return getValidElement(tokens[0], isElementNotInRange);
        }
    }

    Point getValidPosition(const vector<string> &vs, bool isPositionNotInRange(Point)) {
        Point position;
        for(auto iter = vs.cbegin(); iter != vs.cend(); ++iter) {
            int i;
            try {
                i = parseSingleInt(*iter);
            } catch (invalid_argument err) {
                reprompt();
                return getPositionFromCin(isPositionNotInRange);
            }
            if(iter - vs.cbegin() == 0) {
                position.row = i;
            }
            if(iter - vs.cbegin() == 1) {
                position.column = i;
            }
        }
        if(isPositionNotInRange(position)) {
            reprompt();
            return getPositionFromCin(isPositionNotInRange);   
        }
        return position;
    }

    Point getPositionFromCin(bool isPositionNotInRange(Point)) {
        cout << "Provide the row and column positions (0 based)" << endl;
        auto firstLineTokens = getTokens(cin);
        if(firstLineTokens.size() == 1) {
            auto secondLineTokens = getTokens(cin);
            if(secondLineTokens.size() != 1) {
                reprompt();
                return getPositionFromCin(isPositionNotInRange);
            } else {
                firstLineTokens.push_back(secondLineTokens[0]);
                return getValidPosition(firstLineTokens, isPositionNotInRange);
            }
        } else if(firstLineTokens.size() == 2) {
            return getValidPosition(firstLineTokens, isPositionNotInRange);
        } else {
            reprompt();
            return getPositionFromCin(isPositionNotInRange);
        }
    } 
} 


