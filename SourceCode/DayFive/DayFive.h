#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class DayFiveTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const int GetPartTwoCode(const string inputToBeBroken);
private:
	static vector<string> GetValueArray(const string inputToBreak, const int inputLen);
	static const int GetSeatID(const string inputCode, const int rows);
};