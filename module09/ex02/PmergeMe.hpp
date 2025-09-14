#pragma once

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <iterator>

class PmergeMe 
{	
	private:
		std::vector<int>	_vContainer;
		std::deque<int>		_dContainer;

		std::chrono::duration<double, std::micro> _vTime;
		std::chrono::duration<double, std::micro> _lTime;
		
		PmergeMe() = delete;
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;
				
		int generateJacobsthal(int n);

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
	void insertPend(Container& main, Container& pend, bool odd)
	{
		if (pend.empty())
			return;
			
		// Insert first element of pend at the beginning
		auto firstPend = pend.begin();
		auto insertPos = std::upper_bound(main.begin(), main.begin() + 1, *firstPend);
		main.insert(insertPos, *firstPend);
		pend.erase(firstPend);
		
		// Use Jacobsthal sequence for remaining elements
		int jacobIndex = 2;
		int prevJacob = 1;
		
		while (!pend.empty())
		{
			int currJacob = generateJacobsthal(jacobIndex);
			int pendIndex = currJacob - prevJacob - 1;
			
			// If we exceed pend size, insert remaining elements in reverse order
			if (pendIndex >= static_cast<int>(pend.size()))
			{
				for (int i = pend.size() - 1; i >= 0; i--)
				{
					auto pendIt = std::next(pend.begin(), i);
					auto searchEnd = std::next(main.begin(), main.size() - pend.size() + i + (odd ? 1 : 0));
					auto insertPos = std::upper_bound(main.begin(), searchEnd, *pendIt);
					main.insert(insertPos, *pendIt);
				}
				break;
			}
			
			// Insert elements from currJacob position down to prevJacob position
			for (int i = std::min(pendIndex, static_cast<int>(pend.size()) - 1); 
				 i >= 0 && currJacob - prevJacob > 0; 
				 i--, currJacob--)
			{
				auto pendIt = std::next(pend.begin(), i);
				int pairedElementPos = prevJacob + i;
				int searchEndPos = std::min(pairedElementPos + 1, static_cast<int>(main.size()));
				auto searchEnd = std::next(main.begin(), searchEndPos);
				
				auto insertPos = std::upper_bound(main.begin(), searchEnd, *pendIt);
				main.insert(insertPos, *pendIt);
				pendIt = pend.erase(pendIt);
				
				if (i > 0 && pendIt != pend.begin())
					--pendIt;
			}
			
			prevJacob = generateJacobsthal(jacobIndex);
			jacobIndex++;
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

		insertPend(main, pend, odd);
		finaliseSortedContainer(c, main, recursionLvl);
	}
};
	
std::ostream& operator<<(std::ostream& os, const std::vector<int>& Container);