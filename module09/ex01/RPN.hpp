#pragma once

#include <string>
#include <stack>
#include <stdexcept>

class RPN 
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;

		double evaluate(const std::string& expression);
};