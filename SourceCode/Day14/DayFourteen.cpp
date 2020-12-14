#include "DayFourteen.h"
#include <numeric>

using std::accumulate;
using std::stoi;
using std::stoull;

const unsigned long long DayFourteenTask::GetPartOneCode(vector<string> input)
{
	map<int, unsigned long long> maskedMap = GetAlteredMap(input);

	unsigned long long finalValue = 0;
	for (auto iter = maskedMap.begin(); iter != maskedMap.end(); iter++)
	{
		finalValue += iter->second;
	}

	return finalValue;
}

const int DayFourteenTask::GetPartTwoCode(vector<string> input)
{
	return -1;
}

const map<int, unsigned long long> DayFourteenTask::GetAlteredMap(vector<string>& input)
{
	string currentMask = GetBitMask(input[0]);
	map<int, unsigned long long> maskedValues;

	for (int i = 1, len = input.size(); i < len; i++)
	{
		if (input[i][1] == 'a')
		{
			currentMask = GetBitMask(input[i]);
			continue;
		}

		pair<int, unsigned long long> memoryInfo = GetPosAndValue(input[i]);
		maskedValues[memoryInfo.first] = GetAdditionValue(memoryInfo.second, currentMask);
	}

	return maskedValues;
}

const pair<int, unsigned long long> DayFourteenTask::GetPosAndValue(string memVal)
{
	//4 is the size of "mem["
	int storageSlot = stoi(memVal.substr(4, memVal.find(']') - 4));
	unsigned long long memoryVal = stoull(memVal.substr(memVal.find_last_of(' ') + 1));
	return pair<int, int>(storageSlot, memoryVal);
}

const string DayFourteenTask::GetBitMask(string maskVal)
{
	//7 is the size of "mask = "
	return maskVal.substr(7);
}

const unsigned long long DayFourteenTask::GetAdditionValue(const unsigned long long assignedVal, const string bitMask)
{
	unsigned long long returnVal = 0;
	for (int i = 0; i < 36; i++)
	{
		switch (bitMask[i])
		{
		case '0': continue;
		case '1': returnVal += 1llu << (35 - i); break;
		case 'X': returnVal += assignedVal & (1llu << (35 - i)); break;
		}
	}
	return returnVal;
}
