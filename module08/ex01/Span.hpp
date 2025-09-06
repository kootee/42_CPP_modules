#pragma once

#include <cstddef>
#include <vector>

class Span
{
	private:
		unsigned int _capacity;
		std::vector<int> _container;
		
		Span();

	public:
		Span(unsigned int capacity);
		~Span();

		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int number);
		void addNumberRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

		std::size_t shortestSpan();
		std::size_t longestSpan();
};