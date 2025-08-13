#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &cont, int i)
{
	typename T::iterator it;
	it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw std::runtime_error("Value not found");
	else 
		return it;
}