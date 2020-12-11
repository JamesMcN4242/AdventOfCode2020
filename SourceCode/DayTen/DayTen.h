#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Adapter
{
public:
	Adapter(const int val = 0, const int paths = 0) : value(val), pathways(paths) {}
	int value;
	unsigned long long pathways;
};

class DayTenTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const unsigned long long GetPartTwoCode(const string inputToBeBroken);
private:
	static vector<int> GetPerLineArray(const string input);
};