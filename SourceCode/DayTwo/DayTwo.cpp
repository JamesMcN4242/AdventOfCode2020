#include "DayTwo.h"

using std::stoi;

const int DayTwoTask::GetPartOneCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	const int lineCount = GetLineCount(inputToBreak, inputLen);
	valarray<PasswordVerifier> arr = GetValueArray(inputToBreak, lineCount, inputLen);

	int validCount = 0;
	for (int i = 0; i < lineCount; i++)
	{
		if (arr[i].IsSledPassValid())
		{
			validCount++;
		}
	}

	return validCount;
}

const int DayTwoTask::GetPartTwoCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	const int lineCount = GetLineCount(inputToBreak, inputLen);
	valarray<PasswordVerifier> arr = GetValueArray(inputToBreak, lineCount, inputLen);
	int validCount = 0;
	for (int i = 0; i < lineCount; i++)
	{
		if (arr[i].IsTobogganPassValid())
		{
			validCount++;
		}
	}

	return validCount;
}

const int DayTwoTask::GetLineCount(const string inputToBreak, const int inputLen)
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

valarray<PasswordVerifier> DayTwoTask::GetValueArray(const string inputToBreak, const int lineCount, const int inputLen)
{
	valarray<PasswordVerifier> arr(lineCount + 1);

	int index = 0;
	for (int i = 0; i <= lineCount; i++, index++)
	{
		string min = GetSubstringFromIndexToChar(inputToBreak, index, '-', inputLen);
		index += min.length() + 1;

		string max = GetSubstringFromIndexToChar(inputToBreak, index, ' ', inputLen);
		index += max.length() + 1;

		string charToCheck = GetSubstringFromIndexToChar(inputToBreak, index, ':', inputLen);
		index += charToCheck.length() + 2;

		string password = GetSubstringFromIndexToChar(inputToBreak, index, '\n', inputLen);
		index += password.length();

		arr[i] = PasswordVerifier(stoi(min), stoi(max), charToCheck[0], password);
	}

	return arr;
}

string DayTwoTask::GetSubstringFromIndexToChar(const string input, int index, char toStopBefore, int inputLen)
{
	string entry = "";
	while (index < inputLen && input[index] != toStopBefore)
	{
		entry += input[index];
		index++;
	}
	return entry;
}