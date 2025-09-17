#pragma once

#include <stdexcept>
#include <iostream>
#include <stack>

class RPN
{
	private:
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;

	public:
		RPN();
		~RPN();

		double evaluate(const std::string& expression);
};