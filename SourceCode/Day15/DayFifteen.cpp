#include "DayFifteen.h"
#include <map>

using std::map;

const int DayFifteenTask::GetPartOneCode(vector<int> input)
{
	return GetNthSpokenNumber(input, 2020);
}

const unsigned long DayFifteenTask::GetPartTwoCode(vector<int> input)
{
	// Don't have much time today, so the fact this is still brute forceable works for me
	// In a release build this calculates in around 10 seconds (-/+ 2ish seconds). 
	// Pretty slow in computing terms. If I find time I'd like to come back to it.
	return GetNthSpokenNumber(input, 30000000);
}

const unsigned long DayFifteenTask::GetNthSpokenNumber(vector<int>& input, const int nthPosition)
{
	const int inputSize = input.size();
	map<unsigned long, int> valuesSaid;

	for (int i = 0; i < inputSize - 1; i++)
	{
		valuesSaid[input[i]] = i + 1;
	}

	unsigned long nextValue = input[inputSize -1];
	for (int i = inputSize; i < nthPosition; i++)
	{
		auto foundPos = valuesSaid.find(nextValue);
		bool positionFound = foundPos != valuesSaid.end();
		int tmp = positionFound ? i - foundPos->second : 0;

		valuesSaid[nextValue] = i;
		nextValue = tmp;
	}

	return nextValue;
}
