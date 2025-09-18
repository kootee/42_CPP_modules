#pragma once

#include <vector>
#include <deque>
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
				
	public:
		PmergeMe(const std::vector<std::string>& elements);
		~PmergeMe();
		
		std::vector<int> getElements();
		
		void processInput(const std::vector<std::string>& args);
		void displayTimes();

		void fordJohnsonSort();
		int jacobstahl(int n);

		template<typename T>
		void reserveIfVector(std::vector<T>& container, size_t size) 
		{
			container.reserve(size);
		}
		
		template<typename T>
		void reserveIfVector(std::deque<T>& container, size_t size) 
		{
			(void)container;
			(void)size;
		}

		template <typename Container>
		void binaryInsert(Container& container, const typename Container::value_type& value) 
		{
			auto pos = std::upper_bound(container.begin(), container.end(), value);
			container.insert(pos, value);
		}


		template<typename T>
		void addPairs(std::vector<T>& pairs, T& first, T& second, size_t pairSize)
		{
			for (size_t i = pairSize; i > 0; --i)
			{
				pairs.emplace_back(first);
				first++;
			}
			for (size_t i = pairSize; i > 0; --i)
			{
				pairs.emplace_back(second);
				second++;
			}
		}

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
					Iterator startPos = std::next(currPair, - lvl + 1);
					Iterator endPos = std::next(startPos, lvl);
					while (startPos != endPos)
					{
						std::iter_swap(startPos, std::next(startPos, lvl));
						startPos++;
					}
				}
			}
		}

		template <typename srcContainer, typename destContainer, typename T>
		void copyContainer(const srcContainer& src, destContainer& dest)
		{
			dest.clear();
			for (const T& elem : src) 
			{
				dest.push_back(elem);
			}
		}

		template <typename Container>
		void sortContainer(Container& container, int pairSize) 
		{
			int pairs = container.size() / pairSize;
			if (pairs < 2) 
				return;
			
			bool odd = (pairs % 2 != 0) ? 1 : 0;

			auto start = container.begin();
			auto lastPair = container.begin();
			std::advance(lastPair, pairSize * pairs);
			auto end = lastPair;
			int stepsToLastPair = (odd) ? pairSize : 0;
			std::advance(end, -stepsToLastPair);

			swapPairs(start, end, pairSize);
			
			// Sort pairs recursively until not possible anymore
			if (container.size() / (pairSize * 2) >= 2)
				sortContainer(container, pairSize * 2);

			// Create main and pend containers
			std::vector<typename Container::iterator> main;
			std::vector<typename Container::iterator> pend;

			// Init main and pend
			int b1Index = pairSize - 1; 
			int a1Index = (pairSize * 2) - 1;;
			main.insert(main.end(), std::next(container.begin(), b1Index));
			main.insert(main.end(), std::next(container.begin(), a1Index));

			for (int i = 4; i < pairs; i += 2)
			{
				int bIndex = pairSize * (i - 1) - 1;
				int aIndex = pairSize * (i - 1);

				auto insertPend = container.begin();
				std::advance(insertPend, bIndex);
				pend.insert(pend.end(), insertPend);

				auto insertMain = container.begin();
				std::advance(insertMain, aIndex);
				main.insert(main.end(), insertMain);
			}
			if (odd)
			{
				auto oddPosition = end;
				std::advance(oddPosition, pairSize - 1);
				pend.insert(pend.end(), oddPosition);
			}


			std::vector<int> mainVec;
			for (size_t i = 0; i < main.size(); ++i)
				mainVec.push_back(*main[i]);
			std::vector<int> pendVec;
			for (size_t i = 0; i < pend.size(); ++i)
				pendVec.push_back(*pend[i]);

			std::vector<bool> inserted(pend.size(), false);
			size_t insertedCount = 0;

			if (!pend.empty())
			{
				binaryInsert(mainVec, pendVec[0]);
				inserted[0] = true;
				insertedCount++;
			}

			for (int k = 2; insertedCount < pendVec.size(); ++k)
			{
				size_t Jk = jacobstahl(k);
				size_t Jkprev = jacobstahl(k - 1);

				if (Jk > pendVec.size())
					Jk = pendVec.size();

				size_t firstIdx = (Jkprev >= 1) ? (Jkprev) : 1;
				for (size_t idx = Jk - 1; idx >= firstIdx; --idx) 
				{
					if (!inserted[idx])
					{
						binaryInsert(mainVec, pendVec[idx]);
						inserted[idx] = true;
						insertedCount++;
					}
				}
			}
		}
};
	
std::ostream& operator<<(std::ostream& os, const std::vector<int>& Container);