#!/bin/bash

# Test cases
echo "Running tests for RPN program..."

# Test 1
echo "Test 1:"
echo "Argument: 8 9 * 9 - 9 - 9 - 4 - 1 +"
echo "Output: $(./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +")"
echo "Expected: 42"
echo

# Test 2
echo "Test 2:"
echo "Argument: 7 7 * 7 -"
echo "Output: $(./RPN "7 7 * 7 -")"
echo "Expected: 42"
echo

# Test 3
echo "Test 3:"
echo "Argument: 1 2 * 2 / 2 * 2 4 - +"
echo "Output: $(./RPN "1 2 * 2 / 2 * 2 4 - +")"
echo "Expected: 0"
echo

# Test 4
echo "Test 4:"
echo "Argument: (1 + 1)"
echo "Output: $(./RPN "(1 + 1)" 2>&1)" # Redirect stderr to stdout
echo "Expected: Error"
echo

# Test 5: Division by zero
echo "Test 5:"
echo "Argument: 4 0 /"
echo "Output: $(./RPN "4 0 /" 2>&1)" # Redirect stderr to stdout
echo "Expected: Error: Division by zero."
echo

# Test 6: Complex expression
echo "Test 6:"
echo "Argument: 5 1 2 + 4 * + 3 -"
echo "Output: $(./RPN "5 1 2 + 4 * + 3 -")"
echo "Expected: 14"
echo

# Test 7: Single number
echo "Test 7:"
echo "Argument: 9"
echo "Output: $(./RPN "9")"
echo "Expected: 9"
echo

# Test 8: Invalid token
echo "Test 8:"
echo "Argument: 2 3 &"
echo "Output: $(./RPN "2 3 &" 2>&1)" # Redirect stderr to stdout
echo "Expected: Error: Invalid token in expression."
echo

# Test 9: Empty input
echo "Test 9:"
echo "Argument: (empty)"
echo "Output: $(./RPN "" 2>&1)" # Redirect stderr to stdout
echo "Expected: Error: Invalid expression."
echo

echo "All tests completed."