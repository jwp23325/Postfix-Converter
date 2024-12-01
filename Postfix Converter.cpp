#include <iostream>
#include <fstream>
#include "InfixToPostfixConverter.h"

int main() {
    ifstream inputFile("InfixData.txt");
    string infixExpression;

    InfixToPostfixConverter converter;

    while (getline(inputFile, infixExpression)) {
        cout << "Infix Expression: " << infixExpression << ";" << endl;

        converter.Convert(infixExpression);
        cout << "Postfix Expression: " << converter.GetPostfix() << endl << endl;
    }

    inputFile.close();
    return 0;
}
