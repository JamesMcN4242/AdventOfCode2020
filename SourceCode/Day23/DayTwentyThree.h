#pragma once

#include <list>
#include <map>
#include <string>

using std::list;
using std::map;
using std::string;

struct Cup
{
public:
	Cup(int value = -1, int nextCup = -1) : cupValue(value), nextCupValue(nextCup) {}

	int cupValue;
	int nextCupValue;
};

class DayTwentyThreeTask
{
public:
	static const string GetPartOneCode(string input);
	static const unsigned long long GetPartTwoCode(string input);
private:
	//Part One
	static const void RunGamePartOne(list<int>& startingList, int iterations);
	static const int GetNextDestination(list<int>& currentOrder, list<int>& pickedUp, const int highestValue);
	static const list<int> GetLinkinedList(string input);
	static const string GetOutPutFromList(list<int>& input);

	//Part Two
	static const void RunGamePartTwo(map<int,Cup>& startingMap, int iterations);
	static const map<int, Cup> GetMapOfCupsPartTwo(string input);
};