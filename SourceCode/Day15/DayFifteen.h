#pragma once

#include <vector>
using std::vector;

class DayFifteenTask
{
public:
	static const int GetPartOneCode(vector<int> input);
	static const unsigned long GetPartTwoCode(vector<int> input);
private:
	static const unsigned long GetNthSpokenNumber(vector<int>& input, const int nthPosition);
};