#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class DaySixTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const int GetPartTwoCode(const string inputToBeBroken);
private:
	static vector<string> GetValueArray(const string inputToBreak, const int inputLen);
	static vector<string> GetPerLineArray(const string input);
	static const int CountUniqueCharacters(const string input);
	static const bool IsCharInLine(const string entry, const char toFind);
};