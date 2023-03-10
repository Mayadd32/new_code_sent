// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "divide.h"
#include "modulo.h"
#include "exponent.h"
#include "multiply.h"
#include "less_than.h"
#include "greater_than.h"
#include "average.h"
#include "unaryexpression.h"
#include "ternaryexpression.h"
#include "quaternaryexpression.h"

SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(stringstream& in) {
    char operation, paren;
    
    Expression* left = Operand::parse(in);
    in >> operation;

    // Unary expression
    if (operation == '~') {
        in >> paren;
        return new UnaryExpression(left, operation);
    }

    // Ternary expression
    if (operation == '?') {
        Expression* right1 = Operand::parse(in);
        Expression* right2 = Operand::parse(in);
        in >> paren;
        return new TernaryExpression(left, right1, right2);
    }

    // Quaternary expression
    if (operation == '#') {
        Expression* right1 = Operand::parse(in);
        Expression* right2 = Operand::parse(in);
        Expression* right3 = Operand::parse(in);
        in >> paren;
        return new QuaternaryExpression(left, right1, right2, right3);
    }

    // Binary expression
    Expression* right = Operand::parse(in);
    in >> paren;
    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Multiply(left, right);
        case '/':
            return new Divide(left, right);
        case '%':
            return new Modulo(left, right);
        case '^':
            return new Exponent(left, right);
        case '<':
            return new LessThan(left, right);
        case '>':
            return new GreaterThan(left, right);
        case '&':
            return new Average(left, right);
        default:
            throw "Invalid operator";
    }

    return 0;
}
