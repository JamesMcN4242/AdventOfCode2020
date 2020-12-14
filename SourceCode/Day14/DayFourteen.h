#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::pair;
using std::string;
using std::vector;

class DayFourteenTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const int GetPartTwoCode(vector<string> input);
private:
	static const map<int, unsigned long long> GetAlteredMap(vector<string>& input);
	static const pair<int, unsigned long long> GetPosAndValue(string memVal);
	static const string GetBitMask(string maskVal);
	static const unsigned long long GetAdditionValue(const unsigned long long newVal, const string bitMask);
};