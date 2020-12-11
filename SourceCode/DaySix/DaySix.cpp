#include "DaySix.h"

const int DaySixTask::GetPartOneCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	vector<string> entries = GetValueArray(inputToBreak, inputLen);

	int count = 0;
	for (int i = 0, len = entries.size(); i < len; i++)
	{
		count += CountUniqueCharacters(entries[i]);
	}

	return count;
}

const int DaySixTask::GetPartTwoCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	vector<string> entries = GetValueArray(inputToBreak, inputLen);

	int count = 0;

	for (int i = 0, len = entries.size(); i < len; i++)
	{
		vector<string> lines = GetPerLineArray(entries[i]);
		for (int j = 0, lineLen = lines[0].length(); j < lineLen; j++)
		{
			bool inEveryLine = true;

			for (int k = 1, linesSize = lines.size(); k < linesSize; k++)
			{
				if (!IsCharInLine(lines[k], lines[0][j]))
				{
					inEveryLine = false;
					break;
				}
			}

			if (inEveryLine)
			{
				count++;
			}
		}
	}

	return count;
}

vector<string> DaySixTask::GetValueArray(const string inputToBreak, const int inputLen)
{
	vector<string> entries;

	string line = "";
	line += inputToBreak[0];

	for (int i = 1; i < inputLen; i++)
	{
		line += inputToBreak[i];
		if (i == inputLen - 1 || (inputToBreak[i] == '\n' && inputToBreak[i - 1] == '\n'))
		{
			entries.push_back(line);
			line.clear();
		}
	}

	return entries;
}

vector<string> DaySixTask::GetPerLineArray(const string input)
{
	vector<string> entries;
	string line = "";

	for (int i = 0, len = input.length(); i < len; i++)
	{
		bool newLine = false;
		if (input[i] != '\n')
		{
			line += input[i];
		}
		else
		{
			newLine = true;
		}

		if ((newLine || i == len - 1) && line != "")
		{
			entries.push_back(line);
			line.clear();
		}
	}

	return entries;
}

const int DaySixTask::CountUniqueCharacters(const string input)
{
	int uniqueCount = 0;

	for (int i = 0, len = input.length(); i < len; i++)
	{
		if (input[i] != '\n')
		{
			bool alreadyCounted = false;
			for (int j = i - 1; j >= 0; j--)
			{
				if (input[i] == input[j])
				{
					alreadyCounted = true;
					break;
				}
			}

			if (!alreadyCounted)
			{
				uniqueCount++;
			}
		}
	}

	return uniqueCount;
}

const bool DaySixTask::IsCharInLine(const string entry, const char toFind)
{
	for (int i = 0, len = entry.length(); i < len; i++)
	{
		if (entry[i] == toFind)
		{
			return true;
		}
	}

	return false;
}
