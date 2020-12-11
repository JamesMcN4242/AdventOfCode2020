#include "DaySeven.h"
using std::stoi;

const int DaySevenTask::GetPartOneCode(const string inputToBreak)
{
	vector<string> lines = GetPerLineArray(inputToBreak);
	unordered_map<string, BagContents> map = GetMapOfBagContent(lines);

	const string bagKeyToFind = "shiny gold bags";
	int countOfBags = 0;
	for (const auto& keyValPair : map)
	{
		if (keyValPair.first == bagKeyToFind) continue;
		if (BagCanContainBagKey(keyValPair.first, map, bagKeyToFind))
		{
			countOfBags++;
		}
	}

	return countOfBags;
}

const int DaySevenTask::GetPartTwoCode(const string inputToBreak)
{
	vector<string> lines = GetPerLineArray(inputToBreak);
	unordered_map<string, BagContents> map = GetMapOfBagContent(lines);
	return CountBagsInsideBagKey("shiny gold bags", map);
}

vector<string> DaySevenTask::GetPerLineArray(const string input)
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

unordered_map<string, BagContents> DaySevenTask::GetMapOfBagContent(vector<string> bagStrings)
{
	unordered_map<string, BagContents> map;

	for (int i = 0, len = bagStrings.size(); i < len; i++)
	{
		int containsIndx = bagStrings[i].find(" contain");
		string bagType = bagStrings[i].substr(0, containsIndx);
		string bagTypesContained = bagStrings[i].substr(containsIndx + 9);
		map.emplace(bagType, BagContents(bagTypesContained));
	}

	return map;
}

const bool DaySevenTask::BagCanContainBagKey(string bagToCheck, unordered_map<string, BagContents> map, string bagKey)
{
	if (bagToCheck == "no other bags") return false;

	BagContents contents = map[bagToCheck];
	if (contents.ContainsBagKey(bagKey)) return true;

	for (int i = 0, len = contents.contents.size(); i < len; i++)
	{
		if (BagCanContainBagKey(contents.contents[i].bagKey, map, bagKey))
		{
			return true;
		}
	}

	return false;
}

const int DaySevenTask::CountBagsInsideBagKey(string bagToCheck, unordered_map<string, BagContents> map)
{
	if (bagToCheck == "no other bags") return 0;
	int valToReturn = 0;

	BagContents contents = map[bagToCheck];
	for (int i = 0, len = contents.contents.size(); i < len; i++)
	{
		int contentSize = contents.contents[i].value;
		valToReturn += contentSize + (contentSize * CountBagsInsideBagKey(contents.contents[i].bagKey, map));
	}

	return valToReturn;
}

BagContents::BagContents(string bagContent)
{
	bool endHit = false;

	while (!endHit)
	{
		int indexFound = bagContent.find(",");
		endHit = indexFound == string::npos;

		string line;
		if (!endHit)
		{
			line = bagContent.substr(0, indexFound);
			bagContent = bagContent.substr(indexFound + 2);
		}
		else
		{
			bagContent = bagContent.substr(0, bagContent.length() - 1);
			line = bagContent;
		}

		if (line == "no other bags")
		{
			BagKeyValPair keyValPair(line, 0);
			contents.push_back(keyValPair);
		}
		else
		{
			string bagType = line.substr(2);
			if (bagType[bagType.length() - 1] != 's')
			{
				bagType += 's';
			}

			BagKeyValPair keyValPair(bagType, stoi(line.substr(0, 1)));
			contents.push_back(keyValPair);
		}
	}
}
