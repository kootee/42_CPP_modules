#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        using std::stack<T>::stack;

        using iterator = typename std::stack<T>::container_type::iterator;
        using const_iterator = typename std::stack<T>::container_type::const_iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        const_iterator begin() const { return this->c.begin(); }
        const_iterator end() const { return this->c.end(); }
};
    