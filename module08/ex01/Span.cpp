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
    std::size_t range_size = std::distance(start, end);
    if (_container.size() + range_size > _capacity)
        throw std::out_of_range("Not enough capacity to add range.\n");
    
    _container.insert(_container.end(), start, end);
}

std::size_t Span::shortestSpan()
{
    if (_container.size() < 2)
        throw std::runtime_error("Can't calculate range in container.\n");

    std::vector<int> sorted_container = _container;
    std::sort(sorted_container.begin(), sorted_container.end());
    
    std::size_t min_span = std::numeric_limits<std::size_t>::max();
    for (std::size_t i = 1; i < sorted_container.size(); ++i)
    {
        std::size_t span = static_cast<std::size_t>(sorted_container[i] - sorted_container[i - 1]);
        min_span = std::min(min_span, span);
    }
    return min_span;
} 

std::size_t Span::longestSpan()
{
    if (_container.size() < 2)
        throw std::runtime_error("Can't calculate range in container.\n");

    auto min_it = std::min_element(_container.begin(), _container.end());
    auto max_it = std::max_element(_container.begin(), _container.end());
    
    return static_cast<std::size_t>(*max_it - *min_it);
}