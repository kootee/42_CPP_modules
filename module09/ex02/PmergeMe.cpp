#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<std::string>& elements) 
{
	processInput(elements);
}

PmergeMe::~PmergeMe() 
{
	_vContainer.clear();
	_dContainer.clear();
}

void PmergeMe::displayTimes()
{

    std::cout << "Time to process a range of " << _vContainer.size()
              << " elements with std::vector: " << _vTime.count() << " us\n";
    std::cout << "Time to process a range of " << _dContainer.size()
              << " elements with std::deque: " << _lTime.count() << " us\n";
}

std::vector<int> PmergeMe::getElements()
{
    return _vContainer;
}

static void checkInput(const std::vector<std::string>& args) 
{
	for (const std::string& arg : args) 
	{
		for (char c : arg) 
		{
			if (!std::isdigit(c)) 
				throw std::invalid_argument("Error: Invalid input.");
		}
		if (std::stol(arg) < 0)
			throw std::invalid_argument("Error: Negative numbers are not allowed.");
	}
}

void PmergeMe::processInput(const std::vector<std::string>& args) 
{
    checkInput(args);
    for (const std::string& arg : args) 
	{
        int num = std::stoi(arg);
        _vContainer.emplace_back(num);
        _dContainer.emplace_back(num);
    }
}

int PmergeMe::jacobstahl(int n) 
{
	return static_cast<int>(std::round((std::pow(2, n + 1) + std::pow(-1, n)) / 3));
}

void PmergeMe::fordJohnsonSort()
{
	auto startTime = std::chrono::high_resolution_clock::now();
	sortContainer(_vContainer);
	auto endTime = std::chrono::high_resolution_clock::now();
	_vTime = std::chrono::duration<double, std::micro>(endTime - startTime);
	
	startTime = std::chrono::high_resolution_clock::now();
	sortContainer(_dContainer);
	endTime = std::chrono::high_resolution_clock::now();
	_lTime = std::chrono::duration<double, std::micro>(endTime - startTime);
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& Container)
{
	for (int num : Container)
	{
		os << num << ' ';
	}
	return os;
}
