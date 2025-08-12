#pragma once

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array 
{
	private:
		T*			_data;
		std::size_t	_size;

	public:
		Array() : _data(nullptr), _size(0) {}

		Array(unsigned int n) : _data(nullptr), _size(n)
		{
			_data = new T[n]();
		}

		Array(const Array& other) : _data(nullptr), _size(other._size) 
		{
			_data = new T[_size];
			for (std::size_t i = 0; i < _size; ++i) 
				_data[i] = other._data[i];
		}

		Array& operator=(const Array& other) 
		{
			if (this != &other) 
			{
				delete[] _data;
				_size = other._size;
				_data = new T[_size];
				for (std::size_t i = 0; i < _size; ++i)
					_data[i] = other._data[i];
			}
			return *this;
		}

		~Array() 
		{
			delete[] _data;
		}

		T& operator[](std::size_t index) 
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		const T& operator[](std::size_t index) const 
		{
			if (index >= _size)
				throw std::out_of_range("Index out of bounds");
			return _data[index];
		}

		std::size_t size() const 
		{
			return _size;
		}
};
