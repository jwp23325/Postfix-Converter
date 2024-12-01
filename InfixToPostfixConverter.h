#pragma once
#include <stack>
#include <string>
using namespace std;

class InfixToPostfixConverter {
private:
    string postfixExpression;

    int GetPrecedence(char op);

public:
    void Convert(const string& infixExpression);
    string GetPostfix() const;
};


