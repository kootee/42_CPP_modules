#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include "MutantStack.hpp"

void test_basic_functionality()
{
    std::cout << "=== Basic Functionality Test (subject) ===\n";
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << "\n";
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << "\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Iterating through stack: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n";
    
    std::stack<int> s(mstack);
    std::cout << "Copied to std::stack, size: " << s.size() << "\n";
    std::cout << "\n";
}

void test_empty_stack()
{
    std::cout << "=== Empty Stack Test ===\n";
    MutantStack<int> emptyStack;

    std::cout << "Empty stack size: " << emptyStack.size() << "\n";
    std::cout << "Empty stack is empty: " << (emptyStack.empty() ? "true" : "false") << "\n";
    std::cout << "Begin == End for empty stack: " << (emptyStack.begin() == emptyStack.end() ? "true" : "false") << "\n";
    std::cout << "\n";
}

void test_const_iterators()
{
    std::cout << "=== Const Iterator Test ===\n";
    MutantStack<std::string> mstack;
    mstack.push("one");
    mstack.push("two");
    mstack.push("three");
    mstack.push("four");

    const MutantStack<std::string>& constMstack = mstack;
    std::cout << "Using const iterators: ";
    for (MutantStack<std::string>::const_iterator it = constMstack.begin(); it != constMstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
}

void test_copy_and_assignment()
{
    std::cout << "=== Copy and Assignment Test ===\n";
    MutantStack<int> original;
    original.push(10);
    original.push(20);
    original.push(30);
    
    // Copy constructor
    MutantStack<int> copied(original);
    std::cout << "Original size: " << original.size() << ", Copied size: " << copied.size() << "\n";
    
    // Assignment operator
    MutantStack<int> assigned;
    assigned.push(999);
    assigned = original;
    std::cout << "Assigned size: " << assigned.size() << "\n";
    
    // Verify deep copy
    original.push(40);
    std::cout << "After pushing to original - Original: " << original.size() << ", Copied: " << copied.size() << "\n";
    std::cout << "\n";
}

void test_string_stack()
{
    std::cout << "=== String Stack Test ===\n";
    MutantStack<std::string> string_stack;
    string_stack.push("Hello");
    string_stack.push("World");
    string_stack.push("MutantStack");
    
    std::cout << "String stack contents: ";
    for (MutantStack<std::string>::iterator it = string_stack.begin(); it != string_stack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
}

void test_algorithm_compatibility()
{
    std::cout << "=== Algorithm Compatibility Test ===\n";
    MutantStack<int> mstack;
    mstack.push(4);
    mstack.push(3);
    mstack.push(1);
    mstack.push(18);
    mstack.push(1);
    mstack.push(45);
    mstack.push(43);
    mstack.push(25);
    mstack.size();

    std::cout << "Before sorting: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    
    // Test std::sort
    std::cout << "Sorting using std::sort...\n";
    std::sort(mstack.begin(), mstack.end());
    
    std::cout << "After sorting: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Test std::count
    std::cout << "Counting using std::count:\n";
    int count = std::count(mstack.begin(), mstack.end(), 1);
    std::cout << "Count of 1s: " << count << "\n";
}

void test_iterator_operations()
{
    std::cout << "=== Iterator Operations Test ===\n";
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
        mstack.push(i);
    
    MutantStack<int>::iterator it = mstack.begin();
    
    std::cout << "First element: " << *it << "\n";
    
    // Pre-increment
    ++it;
    std::cout << "After pre-increment: " << *it << "\n";
    
    // Post-increment
    it++;
    std::cout << "After post-increment: " << *it << "\n";
    
    // Pre-decrement
    --it;
    std::cout << "After pre-decrement: " << *it << "\n";
    
    // Post-decrement
    it--;
    std::cout << "After post-decrement: " << *it << "\n";
    
    // Iterator arithmetic
    std::cout << "Distance from begin to end using std::distance: " << std::distance(mstack.begin(), mstack.end()) << "\n";
    std::cout << "\n";
}

void default_test()
{
    std::cout << "=== Default Test with MutantStack ===\n";

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << "\n";
    std::cout << "Popping top element\n";
    mstack.pop();
    std::cout << "New top element: " << mstack.top() << "\n";
    std::cout << "Stack size: " << mstack.size() << "\n";
    std::cout << "Pushing more elements into MutantStack...\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(498);
    mstack.push(789);
    mstack.push(85);
    mstack.push(58774);

    std::cout << "Iterating through MutantStack: \n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << "\n";
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "\n";

}

void default_test_w_list()
{
    std::cout << "=== Default Test with List ===\n";

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Top element: " << lst.back() << "\n";
    std::cout << "Popping top element\n";
    lst.pop_back();
    std::cout << "New top element: " << lst.back() << "\n";
    std::cout << "Stack size: " << lst.size() << "\n";
    std::cout << "Pushing more elements into list...\n";
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(498);
    lst.push_back(789);
    lst.push_back(85);
    lst.push_back(58774);

    std::cout << "Iterating through List: \n";
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << "\n";
        ++it;
    }
    std::cout << "\n";
}

int main()
{
    default_test();
    default_test_w_list();
    test_basic_functionality();
    test_empty_stack();
    test_const_iterators();
    test_copy_and_assignment();
    test_string_stack();
    test_algorithm_compatibility();
}