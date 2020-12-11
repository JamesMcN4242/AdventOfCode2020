#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

struct BagKeyValPair
{
public:	
	BagKeyValPair(string key = "", int val = -1) : bagKey(key), value(val) {}
	string bagKey;
	int value;
};

struct BagContents
{
public:
	BagContents() : BagContents("") {}
	BagContents(string bagContent);

	bool ContainsBagKey(string contentKey)
	{
		for (int i = 0, len = contents.size(); i < len; i++)
		{
			if (contents[i].bagKey == contentKey)
			{
				return true;
			}
		}
		return false;
	}
	vector<BagKeyValPair> contents;
};

class DaySevenTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const int GetPartTwoCode(const string inputToBeBroken);
private:
	static vector<string> GetPerLineArray(const string input);
	static unordered_map<string, BagContents> GetMapOfBagContent(vector<string> bagStrings);
	static const bool BagCanContainBagKey(string bagToCheck, unordered_map<string, BagContents> map, string bagKey);
	static const int CountBagsInsideBagKey(string bagToCheck, unordered_map<string, BagContents> map);
};