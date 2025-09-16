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

	template <typename Iterator, typename T>
	Iterator upperBoundBinarySearch(Iterator first, Iterator last, const T& value)
	{
		using difference_type = typename std::iterator_traits<Iterator>::difference_type;
    	difference_type count = std::distance(first, last);

		while (count > 0) 
		{
			difference_type step = count / 2;
			Iterator mid = first;
			std::advance(mid, step);

			if (!(value < *mid)) 
			{ 
				first = ++mid;
				count -= step + 1;
			} 
			else
				count = step;
    	}
    	return first;
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

	template <typename Iterator>
	void fordJohnson(Iterator first, Iterator last) {
    auto n = std::distance(first, last);
    if (n < 2) return;

    using T = typename std::iterator_traits<Iterator>::value_type;

    // 1. Form pairs
    std::vector<std::pair<T,T>> pairs;
    pairs.reserve(n / 2);
    bool hasOdd = (n % 2) != 0;
    T oddValue{};
    if (hasOdd) oddValue = *(std::prev(last));

    for (auto it = first; std::distance(it, last) >= 2; std::advance(it, 2)) {
        T a = *it;
        T b = *std::next(it);
        if (a > b) std::swap(a, b); // (small, large)
        pairs.push_back(std::make_pair(a, b));
    }

    // 2. Collect and recursively sort larges
    std::vector<T> larges;
    larges.reserve(pairs.size());
    for (auto &p : pairs) larges.push_back(p.second);
    fordJohnson(larges.begin(), larges.end());

    // 3. Build initial main chain (sorted larges)
    std::vector<T> chain = larges;

    // 4. Collect smalls in the order of their associated larges
    // Map each large value back to its small(s). For duplicates, handle all matches.
    std::vector<T> smalls;
    smalls.reserve(pairs.size());
    for (auto &p : pairs) {
        // p.second is large, p.first its partner
        smalls.push_back(p.first);
    }

    // 5. Jacobsthal insertion order
    auto jacob = [&](int k)->size_t {
        // J(0)=0, J(1)=1
        if (k == 0) return 0;
        if (k == 1) return 1;
        size_t a = 0, b = 1;
        for (int i = 2; i <= k; ++i) {
            size_t c = b + 2 * a;
            a = b;
            b = c;
        }
        return b;
    };

    std::vector<bool> inserted(smalls.size(), false);
    size_t insertedCount = 0;

    auto binaryInsert = [&](const T &val) {
        auto pos = std::upper_bound(chain.begin(), chain.end(), val);
        chain.insert(pos, val);
    };

    // Always insert the first small associated with the first large
    if (!smalls.empty()) {
        binaryInsert(smalls[0]);
        inserted[0] = true;
        insertedCount++;
    }

    // Use Jacobsthal indices to decide how many new smalls to insert each phase
    for (int k = 2; insertedCount < smalls.size(); ++k) {
        size_t Jk = jacob(k);
        size_t Jk_1 = jacob(k - 1);
        // Indices to insert: (Jk - 1) down to (Jk_1)
        if (Jk == 0) continue;
        if (Jk > smalls.size()) Jk = smalls.size();
        size_t start = (Jk_1 >= 1) ? (Jk_1) : 1;
        if (start >= Jk) continue;
        for (size_t idx = Jk - 1; idx >= start; --idx) {
            if (!inserted[idx]) {
                binaryInsert(smalls[idx]);
                inserted[idx] = true;
                insertedCount++;
            }
            if (idx == start) break;
        }
    }

    // 6. Insert odd leftover if present
    if (hasOdd) {
        auto pos = std::upper_bound(chain.begin(), chain.end(), oddValue);
        chain.insert(pos, oddValue);
    }

    // 7. Copy back
    std::copy(chain.begin(), chain.end(), first);
}
};
	
std::ostream& operator<<(std::ostream& os, const std::vector<int>& Container);