#pragma once

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    using std::stack<T>::stack; // Inherit constructors from std::stack

    // Define iterator types
    using iterator = typename std::stack<T>::container_type::iterator;
    using const_iterator = typename std::stack<T>::container_type::const_iterator;

    // Iterator functions
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};
    