#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &c, int i)
{
	typename T::iterator it;
	it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw std::runtime_error("Value not found");
	else 
		return it;
}