#include "DayOne.h"

using std::stoi;

const int DayOneTask::GetPartOneCode(const string inputToBreak, const int numberToHit)
{
	const int inputLen = inputToBreak.length();
	const int lineCount = GetLineCount(inputToBreak, inputLen);
	const valarray<int> arr = GetValueArray(inputToBreak, lineCount, inputLen);

	for (int i = 0; i < lineCount; i++)
	{
		for (int j = i; j < lineCount; j++)
		{
			if (arr[i] + arr[j] == numberToHit)
			{
				return arr[i] * arr[j];
			}
		}
	}

	return -1;
}

const int DayOneTask::GetPartTwoCode(const string inputToBreak, const int numberToHit)
{
	const int inputLen = inputToBreak.length();
	const int lineCount = GetLineCount(inputToBreak, inputLen);
	const valarray<int> arr = GetValueArray(inputToBreak, lineCount, inputLen);

	for (int i = 0; i < lineCount; i++)
	{
		for (int j = i + 1; j < lineCount; j++)
		{
			for (int k = j + 1; k < lineCount; k++)
			{
				if (arr[i] + arr[j] + arr[k] == numberToHit)
				{
					return arr[i] * arr[j] * arr[k];
				}
			}
		}
	}

	return -1;
}

const int DayOneTask::GetLineCount(const string inputToBreak, const int inputLen)
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

const valarray<int> DayOneTask::GetValueArray(const string inputToBreak, const int lineCount, const int inputLen)
{
	valarray<int> arr(lineCount);

	int index = 0;
	for (int i = 0; i < lineCount; i++, index++)
	{
		string entry = "";
		while (index < inputLen && inputToBreak[index] != '\n')
		{
			entry += inputToBreak[index];
			index++;
		}
		arr[i] = stoi(entry);
	}

	return arr;
}