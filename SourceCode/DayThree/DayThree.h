#pragma once

#include <string>
#include <valarray>

using std::string;
using std::valarray;

class DayThreeTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const unsigned long GetPartTwoCode(const string inputToBeBroken);
private:
	static const int GetLineCount(const string inputToBreak, const int inputLen);
	static const unsigned long GetTreeHitCount(valarray<string> arr, const int lineSize, const int lineCount, const int stepRightSize, const int stepDownSize);
	static valarray<string> GetValueArray(const string inputToBreak, const int lineCount, const int inputLen);
	static string GetSubstringFromIndexToChar(const string input, int indexToStart, char toStopBefore, int fullInputLength);
};