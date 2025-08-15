#pragma once

#include <cstddef>
#include <vector>

class Span
{
	private:
		std::size_t _capacity;
		std::vector<int> _container;
		
		Span() = default;

	public:
		Span(unsigned int capacity);
		~Span();

		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int number);
		std::size_t shortestSpan();
		std::size_t longestSpan();
};