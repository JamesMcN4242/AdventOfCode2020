#include "DayNine.h"
using std::stoull;

const unsigned long long DayNineTask::GetPartOneCode(const string inputToBreak)
{
	vector<unsigned long long> entries = GetPerLineArray(inputToBreak);
	return FindInvalidNumber(entries, 25);
}

const unsigned long long DayNineTask::GetPartTwoCode(const string inputToBreak)
{
	vector<unsigned long long> entries = GetPerLineArray(inputToBreak);
	const unsigned long long invalidNumber = FindInvalidNumber(entries, 25);

	const int entrySize = entries.size();
	for (int i = 0; i < entrySize; i++)
	{
		unsigned long long count = entries[i];
		for (int j = i + 1; j < entrySize; j++)
		{
			count += entries[j];
			if (count > invalidNumber)
			{
				break;
			}

			if (count == invalidNumber)
			{
				unsigned long long largest = 0;
				unsigned long long smallest = 18446744073709551615;
				
				for (int k = i; k <= j; k++)
				{
					unsigned long long entry = entries[k];
					if (entry > largest)
					{
						largest = entry;
					}
					if (entry < smallest)
					{
						smallest = entry;
					}
				}

				return smallest + largest;
			}
		}
	}
	
	return 0;
}

vector<unsigned long long> DayNineTask::GetPerLineArray(const string input)
{
	vector<unsigned long long> entries;
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
			entries.push_back(stoull(line));
			line.clear();
		}
	}

	return entries;
}

const unsigned long long DayNineTask::FindInvalidNumber(vector<unsigned long long> entries, int preambleValue)
{
	deque<unsigned long long> preambles;
	for (int i = 0; i < preambleValue; i++)
	{
		preambles.push_back(entries[i]);
	}

	for (int i = preambleValue, len = entries.size(); i < len; i++)
	{
		unsigned long long entry = entries[i];
		if (!IsValidEntry(entry, preambles))
		{
			return entry;
		}

		preambles.pop_front();
		preambles.push_back(entry);
	}

	return -1;
}

const bool DayNineTask::IsValidEntry(unsigned long long entry, deque<unsigned long long> preamble)
{
	int preambleSize = preamble.size();
	for (int i = 0; i < preambleSize; i++)
	{
		for (int j = i + 1; j < preambleSize; j++)
		{
			if (preamble[i] + preamble[j] == entry)
			{
				return true;
			}
		}
	}

	return false;
}
