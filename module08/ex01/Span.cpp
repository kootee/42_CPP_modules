#include "Span.hpp"
#include <stdexcept>
#include <limits>

Span::Span(unsigned int capacity) : _capacity(capacity) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {}

Span::Span(const Span& other) {}

void Span::addNumber(int num)
{
    if (_capacity == _container.size())
        throw std::out_of_range("No more capacity in container\n");
    else
        _container.emplace_back(num);
}

std::size_t Span::shortestSpan()
{
    int minVal = std::numeric_limits<int>::lowest();
    int minVal = std::numeric_limits<int>::lowest();

} 

std::size_t Span::longestSpan()
{

}