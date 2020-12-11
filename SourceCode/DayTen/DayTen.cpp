#include "DayTen.h"

#include <algorithm>
#include <deque>
#include <iterator>

using std::back_inserter;
using std::copy;
using std::deque;
using std::sort;
using std::stoi;

const int DayTenTask::GetPartOneCode(const string inputToBreak)
{
	vector<int> entries = GetPerLineArray(inputToBreak);
	sort(entries.begin(), entries.end());

	int one{ 0 }, two{ 0 }, three{ 1 };		//three is one due to the device always being a joltage of 3 higher than highest adapter.
	int previous = 0;
	for (int i = 0, len = entries.size(); i < len; i++)
	{
		int newVal = entries[i];

		switch (newVal - previous)
		{
		case 1: one++; break;
		case 2: two++; break;
		case 3: three++; break;
		}

		previous = newVal;
	}

	return one * three;
}

const unsigned long long DayTenTask::GetPartTwoCode(const string inputToBreak)
{
	vector<int> entries = GetPerLineArray(inputToBreak);
	entries.push_back(0);					// Add the wall adapter before sorting
	sort(entries.begin(), entries.end());
	entries.push_back(entries.back() + 3);	// Add the last node (your phone) since it would be sorted to end anyway

	vector<Adapter> adapters;
	copy(entries.begin(), entries.end(), back_inserter(adapters));
	adapters[0].pathways = 1;
	int adapterSize = adapters.size();

	for (int i = 0; i < adapterSize; i++)
	{
		const unsigned long long currentNodePaths = adapters[i].pathways;
		for (int j = i + 1; j < i + 4 && j < adapterSize; j++)
		{
			if (adapters[j].value - adapters[i].value <= 3)
			{
				adapters[j].pathways += currentNodePaths;
			}
		}
	}

	return adapters.back().pathways;
}

vector<int> DayTenTask::GetPerLineArray(const string input)
{
	vector<int> entries;
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
			entries.push_back(stoi(line));
			line.clear();
		}
	}

	return entries;
}