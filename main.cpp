/**
	ComboCounter

	@brief	A simple tool to determine the number of combinations that can be made with a given set of values and a total value (and optionally a maximum number of values).
	@author	dennistreysa
	@date	2019-09-11

	@note	Will not check if values are unique.
	@note	Will not count permuted combinations.

	@usage	Set TOTAL_VALUE, VALUES (and array size), MAX_VALUES (no limit = 0) and compile ;)
*/


#include <iostream>
#include <inttypes.h>
#include <array>
#include <algorithm>
#include <chrono>


using namespace std;


/** Config */
const uint64_t TOTAL_VALUE = 666;
std::array<uint64_t, 8> VALUES = {1, 2, 5, 10, 20, 50, 100, 200};
const uint64_t MAX_VALUES = 0;


/** Constants */
const size_t NUMBER_OF_VALUES = VALUES.size();


uint64_t possibilities(uint64_t need, size_t currentIndex, uint64_t numberOfValues)
{
	uint64_t tPossibilities = 0;
	size_t tStartIndex = currentIndex;

	if ((0 == MAX_VALUES) || (numberOfValues < MAX_VALUES))
	{
		if (VALUES[currentIndex] == need)
		{
			/** Current value fits completely */
			tStartIndex = currentIndex + 1;
			tPossibilities += 1;
		}
		else
		{
			/** Does not fit completely */
		}

		for (size_t tIndex = tStartIndex; tIndex < NUMBER_OF_VALUES; tIndex++)
		{
			if (need > VALUES[tIndex])
			{
				tPossibilities += possibilities((need - VALUES[tIndex]), tIndex, (numberOfValues + 1));
			}
			else if (need == VALUES[tIndex])
			{
				tPossibilities += 1;
			}
			else
			{
				/** Does not fit */
			}
		}
	}
	else
	{
		/** Number of values exhausted */
	}


	return tPossibilities;
}


int main(void)
{
	auto tStart = chrono::steady_clock::now();

	std::cout << "Total value: " << TOTAL_VALUE << std::endl;
	std::cout << "Number of fractals: " << VALUES.size() << std::endl;
	std::cout << "Maximum number of values: " << MAX_VALUES << std::endl;

	/** Sort values by descending order */
	std::sort(VALUES.begin(), VALUES.end(), std::greater<uint64_t>());

	uint64_t tPossibilities = possibilities(TOTAL_VALUE, 0, 0);

	auto tEnd = chrono::steady_clock::now();

	std::cout << "Number of possibilities: " << tPossibilities << std::endl;
	std::cout << "Time needed: " << chrono::duration_cast<chrono::milliseconds>(tEnd - tStart).count() << " ms" << endl;

	return 0;
}
