#include "InfixToPostfixConverter.h"

// Helper function to return precedence of operators
int InfixToPostfixConverter::GetPrecedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // for invalid operator
}

// Function to convert infix expression to postfix
void InfixToPostfixConverter::Convert(const string& infixExpression) {
    stack<char> operators;
    postfixExpression.clear();

    for (char ch : infixExpression) {
        if (isalpha(ch)) {
            postfixExpression += ch;  // Append operand to postfix
        }
        else if (ch == '(') {
            operators.push(ch);  // Push '(' to stack
        }
        else if (ch == ')') {
            // Pop operators until '(' is found
            while (!operators.empty() && operators.top() != '(') {
                postfixExpression += operators.top();
                operators.pop();
            }
            operators.pop();  // Discard '('
        }
        else if (ch == ' ') {
            continue;  // Skip spaces
        }
        else {  // For operators +, -, *, /
            while (!operators.empty() && GetPrecedence(ch) <= GetPrecedence(operators.top())) {
                postfixExpression += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        postfixExpression += operators.top();
        operators.pop();
    }
}

// Function to get the final postfix expression
string InfixToPostfixConverter::GetPostfix() const {
    return postfixExpression;
}
