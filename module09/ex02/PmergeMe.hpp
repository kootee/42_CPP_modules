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

		template<typename Container>
		void binaryInsert(Container& container, int value)
		{
			typename Container::iterator pos = std::upper_bound(container.begin(), container.end(), value);
			container.insert(pos, value);
		}

		template <typename Container>
		void sortContainer(Container& container) 
		{
			using T = typename Container::value_type;

			auto n = container.size();
			if (n < 2) return;

			std::vector<std::pair<T, T>> pairs;
			pairs.reserve(n / 2);

			bool odd = (n % 2) != 0;
			int oddValue;
			if (odd) 
				oddValue = container.back();

			auto it = container.begin();
			while (std::distance(it, container.end()) >= 2) 
			{
				int a = *it;
				int b = *std::next(it);
				if (a > b) std::swap(a, b);
				pairs.push_back(std::make_pair(a, b));
				std::advance(it, 2);
			}

			Container aChain;
			reserveIfVector(aChain, pairs.size());
			for (auto &p : pairs) 
				aChain.push_back(p.second);
			sortContainer(aChain);

			Container main = aChain;

			Container pend;
			reserveIfVector(pend, pairs.size());
			for (auto &p : pairs)
				pend.push_back(p.first);

			std::vector<bool> inserted(pend.size(), false);
			size_t insertedCount = 0;

			if (!pend.empty())
			{
				binaryInsert(main, pend[0]);
				inserted[0] = true;
				insertedCount++;
			}

			for (int k = 2; insertedCount < pend.size(); ++k)
			{
				size_t Jk = jacobstahl(k);
				size_t Jkprev = jacobstahl(k - 1);
				if (Jk == 0) 
					continue;
				if (Jk > pend.size()) Jk = pend.size();
				size_t start = (Jkprev >= 1) ? (Jkprev) : 1;
				if (start >= Jk) 
					continue;
				for (size_t idx = Jk - 1; idx >= start; --idx) 
				{
					if (!inserted[idx]) 
					{
						binaryInsert(main, pend[idx]);
						inserted[idx] = true;
						insertedCount++;
					}
					if (idx == start) 
						break;
				}
			}

			if (odd)
				binaryInsert(main, oddValue);

			container = main;
		}
};
	
std::ostream& operator<<(std::ostream& os, const std::vector<int>& Container);