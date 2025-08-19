#include "Span.hpp"
#include <stdexcept>
#include <limits>
#include <algorithm>

Span::Span(unsigned int capacity) : _capacity(capacity) 
{
    _container.reserve(capacity);
}

Span::~Span() 
{
    _container.clear();
}

Span& Span::operator=(const Span& other) 
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _container = other._container;
    }
    return *this;
}

Span::Span(const Span& other) : _capacity(other._capacity), _container(other._container) {}

void Span::addNumber(int num)
{
    if (_capacity == _container.size())
        throw std::out_of_range("No more capacity in container.\n");
    else
        _container.emplace_back(num);
}

void Span::addNumberRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    std::size_t rangeSize = std::distance(start, end);
    if (_container.size() + rangeSize > _capacity)
        throw std::out_of_range("Not enough capacity to add range.\n");
    
    _container.insert(_container.end(), start, end);
}

std::size_t Span::shortestSpan()
{
    if (_container.size() < 2)
        throw std::runtime_error("Can't calculate range in container.\n");

    std::vector<int> sortedContainer = _container;
    std::sort(sortedContainer.begin(), sortedContainer.end());

    std::size_t minSpan = std::numeric_limits<std::size_t>::max();
    for (std::size_t i = 1; i < sortedContainer.size(); ++i)
    {
        std::size_t span = static_cast<std::size_t>(sortedContainer[i] - sortedContainer[i - 1]);
        minSpan = std::min(minSpan, span);
    }
    return minSpan;
} 

std::size_t Span::longestSpan()
{
    if (_container.size() < 2)
        throw std::runtime_error("Can't calculate range in container.\n");

    auto minIt = std::min_element(_container.begin(), _container.end());
    auto maxIt = std::max_element(_container.begin(), _container.end());

    return static_cast<std::size_t>(*maxIt - *minIt);
}