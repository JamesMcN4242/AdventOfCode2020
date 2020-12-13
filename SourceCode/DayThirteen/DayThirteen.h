#pragma once

#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

struct BusService
{
public:
	BusService(string entry = "")
	{
		isValid = entry.size() > 0 && entry[0] != 'x';
		value = isValid ? stoi(entry) : -1;
	}

	bool isValid;
	int value;
};

class DayThirteenTask
{
public:
	static const int GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const vector<int> GetBusNumbers(string input);
	static const vector<BusService> GetBusServices(string input);
	static const pair<int, int> GetClosestBusAndOffset(int arriveTime, vector<int>& busNumbers);
	static const unsigned long long GetCompetitionTimestamp(vector<BusService>& busServices);
};