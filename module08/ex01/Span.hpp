#pragma once

#include <cstddef>

class Span
{
	private:
		std::size_t _capacity;

		Span() = default;
	public:
		Span(std::size_t capacity);
		~Span();

		Span& operator=(const Span& other);
		Span(const Span& other);

		void addNumber(typename T number);
		std::size_t shortestSpan();
		std::size_t longestSpan();

};