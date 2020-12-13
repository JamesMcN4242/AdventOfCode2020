#include "DayThirteen.h"
#include <utility>

using std::pair;
using std::stoi;

const int DayThirteenTask::GetPartOneCode(vector<string> input)
{
	int arrivalTime = stoi(input[0]);
	vector<int> busNumbers = GetBusNumbers(input[1]);
	const pair<int, int> closest = GetClosestBusAndOffset(arrivalTime, busNumbers);
	return closest.first * closest.second;
}

const unsigned long long DayThirteenTask::GetPartTwoCode(vector<string> input)
{
	vector<BusService> busServices = GetBusServices(input[1]);
	return GetCompetitionTimestamp(busServices);
}

const vector<int> DayThirteenTask::GetBusNumbers(string input)
{
	vector<int> busNumbers;
	bool hitEnd = false;

	while (!hitEnd)
	{
		int commaIndx = input.find(',');
		hitEnd = commaIndx == string::npos;
		string line = hitEnd ? input : input.substr(0, commaIndx);

		if (line.find('x') == string::npos)
		{
			busNumbers.push_back(stoi(line));
		}

		if (!hitEnd)
		{
			input = input.substr(line.size() + 1);
		}
	}

	return busNumbers;
}

const vector<BusService> DayThirteenTask::GetBusServices(string input)
{
	vector<BusService> busServices;
	bool hitEnd = false;

	while (!hitEnd)
	{
		int commaIndx = input.find(',');
		hitEnd = commaIndx == string::npos;
		string line = hitEnd ? input : input.substr(0, commaIndx);
		busServices.push_back(line);

		if (!hitEnd)
		{
			input = input.substr(line.size() + 1);
		}
	}

	return busServices;
}

const pair<int, int> DayThirteenTask::GetClosestBusAndOffset(int arriveTime, vector<int>& busNumbers)
{
	pair<int, int> closest(-1, -1);

	for (int i = 0, len = busNumbers.size(); i < len; i++)
	{
		int closestTime = busNumbers[i] - (arriveTime % busNumbers[i]);

		if (closest.first == -1 || closestTime < closest.first)
		{
			closest.first = closestTime;
			closest.second = busNumbers[i];
		}
	}

	return closest;
}

const unsigned long long DayThirteenTask::GetCompetitionTimestamp(vector<BusService>& busServices)
{
	vector<pair<int, int>> busOffsets;
	int offset = 0;
	for (int i = 0, len = busServices.size(); i < len; i++)
	{
		if (busServices[i].isValid)
		{
			busOffsets.push_back(pair<int, int>(busServices[i].value, offset));			
		}
		offset++;
	}

	//Since my input and all test input starts with a numbered first slot I will assume the first one shall always be the start point with an offset of 0
	unsigned long long timestamp = 0;
	const int offsetLengths = busOffsets.size();
	unsigned long long jumpValue = busOffsets[0].first;
	int busToCheck = 1;

	while (busToCheck < offsetLengths)
	{
		if ((timestamp + busOffsets[busToCheck].second) % busOffsets[busToCheck].first == 0)
		{
			//This is the step size we would need for all of the bus numbers covered to be in sync again
			jumpValue *= busOffsets[busToCheck].first;
			busToCheck++;
			continue;
		}

		timestamp += jumpValue;
	}

	return timestamp;
}
