#pragma once

#include <string>
#include <valarray>

using std::string;
using std::valarray;

class DayOneTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken, const int numberToHit);
	static const int GetPartTwoCode(const string inputToBeBroken, const int numberToHit);
private:
	static const int GetLineCount(const string inputToBreak, const int inputLen);
	static const valarray<int> GetValueArray(const string inputToBreak, const int lineCount, const int inputLen);
};