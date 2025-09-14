#pragma once

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>

class PmergeMe 
{	
	private:
		std::vector<int>	_vContainer;
		std::deque<int>		_lContainer;

		size_t _comparisons;

		std::chrono::duration<double, std::micro> _vTime;
		std::chrono::duration<double, std::micro> _lTime;
		
		PmergeMe();
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;
				
		double generateJacobsthal(int n);
	public:
		PmergeMe(const std::vector<std::string>& elements);
		~PmergeMe();

		std::vector<int> getElements();

		void processInput(const std::vector<std::string>& args);
		void displayTimes();
		
		void performSorting();
		

	template <typename Iterator>
	void swapPairs(Iterator start, Iterator end, int lvl)
	{
		int skip = 2 * lvl;
		for (Iterator it = start; it != end; std::advance(it, skip))
		{
			Iterator currPair = std::next(it, lvl - 1);
			Iterator nextPair = std::next(it, lvl * 2 - 1);
			if (*currPair > *nextPair)
			{
				Iterator start = std::next(it, - lvl + 1);
				Iterator end = std::next(start, lvl);
				while (start != end)
				{
					std::iter_swap(start, std::next(start, lvl));
					start++;
				}
			}
		}
	}

	// Insert pend into main according to Jacobstahl
	template <typename Container>
	void insertPend(Container& main, Container& pend)
	{
		int prevJt = generateJacobsthal(1);
		int insertions = 0;

		for (int elemPos = 2; ; elemPos++)
		{
			int currJt = generateJacobsthal(elemPos);
			int diffJt = currJt - prevJt;
			if (diffJt > pend.size())
				break;
			auto pendIt = std::next(pend.begin(), diffJt - 1);
			auto bound = std::next(main.begin(), (currJt + insertions));
			int offset = 0;
			while (0 < diffJt--)
			{
				auto id = std::upper_bound(main.begin(), bound, *pendIt);
				auto elemToInsert = main.insert(id, *pendIt);
				pendIt = pend.erase(pendIt);
				std::advance(pendIt, - 1);
				
				if ((elemToInsert - main.begin()) == currJt + insertions)
					offset += 1;
				bound = main.begin();
				std::advance(currJt + insertions - offset);
			}
			insertions += currJt - prevJt;
			offset = 0;
			prevJt = currJt;
		}
		// Insert remaining from pend
		for (int i = pend.size() - 1; i >= 0; i--)
		{
			auto currPend = std::next(pend.begin(), i);
			auto currBound = std::next(main.begin(), main.size() - pend.size() + i + odd);
			auto id = std::upper_bound(main.begin(), currBound, *currPend);
			main.insert(id, *currPend);	
		}
	}

	template <typename Container, typename IteratorContainer>
	void finaliseSortedContainer(Container& c, IteratorContainer& mainVec, int recLvl)
	{
		std::vector<int> temp;
		temp.reserve(c.size());
		for (auto it = mainVec.begin(); it != mainVec.end(); it++)
		{
			for (int i = 0; i < recLvl; i++)
			{
				auto start = *it;
				std::advance(start, - recLvl + i + 1);
				temp.insert(temp.end(), *start);
			}
		}
		auto cIt = c.begin();
		auto copyIt = temp.begin();
		while (copyIt != temp.end())
		{
			*cIt = *copyIt;
			cIt++, copyIt++;
		}
	}

	template <typename Container>
	void sortContainer(Container& c, int recursionLvl)
	{	
		int pairs = c.size() / recursionLvl;
		if (pairs < 2) 
			return;
		
		bool odd = (pairs % 2 != 0) ? 1 : 0;

		auto start = c.begin();
		auto lastPair = c.begin();
		std::advance(lastPair, recursionLvl * pairs);
		auto end = lastPair;
		int stepsToLastPair = (odd) ? recursionLvl : 0;
		std::advance(end, -stepsToLastPair);

		swapPairs(start, end, recursionLvl);
		
		// Sort pairs recursively until not possible anymore
		if (c.size() / (recursionLvl * 2) >= 2)
			sortContainer(c, recursionLvl * 2);

		std::vector<typename Container::iterator> main;
		std::vector<typename Container::iterator> pend;

		// Init main and pend
		int b1Index = recursionLvl - 1; 
		int a1Index = (recursionLvl * 2) - 1;;
		main.insert(main.end(), std::next(c.begin(), b1Index)); // insert b1
		main.insert(main.end(), std::next(c.begin(), a1Index)); // insert a1

		for (int i = 4; i < pairs; i += 2)
		{
			int bIndex = recursionLvl * (i - 1) - 1;
			int aIndex = recursionLvl * (i - 1);

			auto insertPend = c.begin();
			std::advance(insertPend, bIndex);
			pend.insert(pend.end(), insertPend);

			auto insertMain = c.begin();
			std::advance(insertMain, aIndex);
			main.insert(main.end(), insertMain);
		}

		if (odd)
		{
			auto oddPosition = end;
			std::advance(oddPosition, recursionLvl - 1);
			pend.insert(pend.end(), oddPosition);
		}

		insertPend(main, pend);
		finaliseSortedContainer(c, main, recursionLvl);
	}
};
	
std::ostream& operator<<(std::ostream& os, const std::vector<int>& Container);