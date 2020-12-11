#include "DayThree.h"

const int DayThreeTask::GetPartOneCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	const int lineCount = GetLineCount(inputToBreak, inputLen);
	valarray<string> arr = GetValueArray(inputToBreak, lineCount, inputLen);
	return GetTreeHitCount(arr, arr[0].length(), lineCount, 3, 1);
}

const unsigned long DayThreeTask::GetPartTwoCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	const int lineCount = GetLineCount(inputToBreak, inputLen);
	valarray<string> arr = GetValueArray(inputToBreak, lineCount, inputLen);
	const int lineSize = arr[0].length();

	return GetTreeHitCount(arr, lineSize, lineCount, 1, 1)
		* GetTreeHitCount(arr, lineSize, lineCount, 3, 1)
		* GetTreeHitCount(arr, lineSize, lineCount, 5, 1)
		* GetTreeHitCount(arr, lineSize, lineCount, 7, 1)
		* GetTreeHitCount(arr, lineSize, lineCount, 1, 2);
}

const int DayThreeTask::GetLineCount(const string inputToBreak, const int inputLen)
{
	int lineCount = 0;

	for (int i = 0; i < inputLen; i++)
	{
		if (inputToBreak[i] == '\n')
		{
			lineCount++;
		}
	}

	return lineCount;
}

const unsigned long DayThreeTask::GetTreeHitCount(valarray<string> arr, const int lineSize, const int lineCount, const int stepRightSize, const int stepDownSize)
{
	int treesHit = 0;
	int indexHit = stepRightSize;

	for (int i = stepDownSize; i <= lineCount; i += stepDownSize, indexHit = (indexHit + stepRightSize) % lineSize)
	{
		if (arr[i][indexHit] == '#')
		{
			treesHit++;
		}
	}

	return treesHit;
}

valarray<string> DayThreeTask::GetValueArray(const string inputToBreak, const int lineCount, const int inputLen)
{
	valarray<string> arr(lineCount + 1);

	int index = 0;
	for (int i = 0; i <= lineCount; i++, index++)
	{
		string line = GetSubstringFromIndexToChar(inputToBreak, index, '\n', inputLen);
		index += line.length();
		arr[i] = line;
	}

	return arr;
}

string DayThreeTask::GetSubstringFromIndexToChar(const string input, int index, char toStopBefore, int inputLen)
{
	string entry = "";
	while (index < inputLen && input[index] != toStopBefore)
	{
		entry += input[index];
		index++;
	}
	return entry;
}