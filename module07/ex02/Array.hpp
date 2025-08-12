#pragma once

#include <iostream>
#include <exception>

/* Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (al-
locating memory in advance) is forbidden. Your program must never access non-
allocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance. */

template <class T>
class Array {
public:
    Array() : _size(0), _data(nullptr) {}

    Array(unsigned int n) : _size(n), _data(new T[n]()) {}

    Array(const Array &other) : _size(other._size), _data(new T[other._size]) {
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _data = new T[_size];
            for (size_t i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] _data;
    }

    T &operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    size_t size() const {
        return _size;
    }

private:
    size_t _size;
    T *_data;
};
