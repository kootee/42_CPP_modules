#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN() {}

RPN::~RPN() {}

static bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

static double performOperation(char op, double a, double b) 
{
    switch (op) 
	{
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) 
			{
                throw std::runtime_error("Error: Division by zero.");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: Invalid operator.");
    }
}

double RPN::evaluate(const std::string& expr) 
{
    std::stack<double> stack;

    for (size_t i = 0; i < expr.size(); ++i) 
	{
        char token = expr[i];

        if (std::isspace(token))
            continue;
        if (std::isdigit(token))
            stack.push(token - '0');
		else if (isOperator(token))
		{
            if (stack.size() < 2)
                throw std::runtime_error("Error: Invalid expression.");

            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();

            double result = performOperation(token, a, b);
            stack.push(result);
        } else
            throw std::runtime_error("Error: Invalid token in expression.");
    }

    if (stack.size() != 1) 
        throw std::runtime_error("Error: Invalid expression.");

    return stack.top();
}