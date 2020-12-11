#pragma once

#include <string>
#include <vector>
#include <deque>

using std::deque;
using std::string;
using std::vector;

class DayNineTask
{
public:
	static const unsigned long long GetPartOneCode(const string inputToBeBroken);
	static const unsigned long long GetPartTwoCode(const string inputToBeBroken);
private:
	static vector<unsigned long long> GetPerLineArray(const string input);
	static const unsigned long long FindInvalidNumber(vector<unsigned long long> entries, int preambleValue);
	static const bool IsValidEntry(unsigned long long entry, deque<unsigned long long> preamble);
};