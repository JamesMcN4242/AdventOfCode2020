#include "DayFive.h"
#include <algorithm>

using std::sort;

const int DayFiveTask::GetPartOneCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	vector<string> entries = GetValueArray(inputToBreak, inputLen);

	int largestSeatID = -1;
	for (int i = 0, len = entries.size(); i < len; i++)
	{
		int currentSeatID = GetSeatID(entries[i], 127);
		if (currentSeatID > largestSeatID)
		{
			largestSeatID = currentSeatID;
		}
	}

	return largestSeatID;
}

const int DayFiveTask::GetPartTwoCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	vector<string> entries = GetValueArray(inputToBreak, inputLen);

	vector<int> seatIds;
	for (int i = 0, len = entries.size(); i < len; i++)
	{
		seatIds.push_back(GetSeatID(entries[i], 127));
	}

	sort(seatIds.begin(), seatIds.end());

	for (int i = 1, len = seatIds.size(); i < len; i++)
	{
		if (seatIds[i] == seatIds[i - 1] + 2)
		{
			return seatIds[i] - 1;
		}
	}

	//Our seat id wasn't present?
	return -1;
}

vector<string> DayFiveTask::GetValueArray(const string inputToBreak, const int inputLen)
{
	vector<string> entries;

	string line = "";

	for (int i = 0; i < inputLen; i++)
	{
		if (i == inputLen - 1 || inputToBreak[i] == '\n')
		{
			if (i == inputLen - 1)
			{
				line += inputToBreak[i];
			}

			entries.push_back(line);
			line.clear();
			continue;
		}

		line += inputToBreak[i];
	}

	return entries;
}

const int DayFiveTask::GetSeatID(const string input, const int rowCount)
{
	int min = 0;
	int max = rowCount;

	for (int i = 0; i < 6; i++)
	{
		int differenceToJump = (max - min + 1) / 2;
		if (input[i] == 'F')
		{
			max -= differenceToJump;
		}
		else if (input[i] == 'B')
		{
			min += differenceToJump;
		}
	}

	int row = input[6] == 'F' ? min : max;

	min = 0;
	max = 7;
	for (int i = 7; i < 9; i++)
	{
		int differenceToJump = (max - min + 1) / 2;
		if (input[i] == 'L')
		{
			max -= differenceToJump;
		}
		else if (input[i] == 'R')
		{
			min += differenceToJump;
		}
	}

	int column = input[9] == 'L' ? min : max;

	return row * 8 + column;
}