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

const unsigned long long DayFourteenTask::GetPartTwoCode(vector<string> input)
{
	map<unsigned long long, unsigned long long> maskedMap = GetPartTwoAlteredMap(input);

	unsigned long long finalValue = 0;
	for (auto iter = maskedMap.begin(); iter != maskedMap.end(); iter++)
	{
		finalValue += iter->second;
	}

	return finalValue;
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

const map<unsigned long long, unsigned long long> DayFourteenTask::GetPartTwoAlteredMap(vector<string>& input)
{
	string currentMask = GetBitMask(input[0]);
	map<unsigned long long, unsigned long long> maskedValues;

	for (int i = 1, len = input.size(); i < len; i++)
	{
		if (input[i][1] == 'a')
		{
			currentMask = GetBitMask(input[i]);
			continue;
		}

		const pair<int, unsigned long long> memoryInfo = GetPosAndValue(input[i]);
		const string binaryAddresses = GetBinaryAddressForPartTwo(memoryInfo.first, currentMask);
		WriteToAllAddresses(maskedValues, memoryInfo.second, binaryAddresses);
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
		case '0': break;
		case '1': returnVal += 1llu << (35 - i); break;
		case 'X': returnVal += assignedVal & (1llu << (35 - i)); break;
		}
	}
	return returnVal;
}

const string DayFourteenTask::GetBinaryAddressForPartTwo(const unsigned long long memoryAddress, const string bitMask)
{
	string binaryMemory = "";
	for (int i = 0; i < 36; i++)
	{
		switch (bitMask[i])
		{
		case '0': binaryMemory += ((memoryAddress & (1llu << (35 - i))) > 0 ? '1' : '0'); break;
		case '1': binaryMemory += '1'; break;
		case 'X': binaryMemory += 'X'; break;
		}		
	}
	return binaryMemory;
}

const void DayFourteenTask::WriteToAllAddresses(map<unsigned long long, unsigned long long>& addressMap, const unsigned long long valueToWrite, string memoryBinaryToAddTo)
{
	size_t indexFound = memoryBinaryToAddTo.find("X");
	if (indexFound == string::npos)
	{
		//We have no values to change, so can write our value
		unsigned long long address = GetDecimalValue(memoryBinaryToAddTo);
		addressMap[address] = valueToWrite;
		return;
	}

	//Otherwise we have an X to change. 
	//So we can use this same function recursively to put it down every possible path
	memoryBinaryToAddTo[indexFound] = '0';
	WriteToAllAddresses(addressMap, valueToWrite, memoryBinaryToAddTo);

	memoryBinaryToAddTo[indexFound] = '1';
	WriteToAllAddresses(addressMap, valueToWrite, memoryBinaryToAddTo);
}

const unsigned long long DayFourteenTask::GetDecimalValue(const string binaryRepresentation)
{
	return stoull(binaryRepresentation, 0, 2);
}
