#include "DayFour.h"

const int DayFourTask::GetPartOneCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	vector<string> entries = GetValueArray(inputToBreak, inputLen);
	valarray<PassportIdentifiers> passportIdentifiers = GetPassportIdentifiersFromStrings(entries);

	int valid = 0;
	for (int i = 0, len = passportIdentifiers.size(); i < len; i++)
	{
		if (passportIdentifiers[i].IsPartOneValid())
		{
			valid++;
		}
	}

	return valid;
}

const int DayFourTask::GetPartTwoCode(const string inputToBreak)
{
	const int inputLen = inputToBreak.length();
	vector<string> entries = GetValueArray(inputToBreak, inputLen);
	valarray<PassportIdentifiers> passportIdentifiers = GetPassportIdentifiersFromStrings(entries);

	int valid = 0;
	for (int i = 0, len = passportIdentifiers.size(); i < len; i++)
	{
		if (passportIdentifiers[i].IsPartTwoValid())
		{
			valid++;
		}
	}

	return valid;
}


vector<string> DayFourTask::GetValueArray(const string inputToBreak, const int inputLen)
{
	vector<string> entries;

	string line = "";
	line += inputToBreak[0];

	for (int i = 1; i < inputLen; i++)
	{
		line += inputToBreak[i];
		if (i == inputLen - 1 || (inputToBreak[i] == '\n' && inputToBreak[i - 1] == '\n'))
		{
			entries.push_back(line);
			line.clear();
		}
	}

	return entries;
}

valarray<PassportIdentifiers> DayFourTask::GetPassportIdentifiersFromStrings(vector<string> entries)
{
	const int entryCount = entries.size();
	valarray<PassportIdentifiers> passportEntries(entryCount);

	for (int i = 0; i < entryCount; i++)
	{
		passportEntries[i] = PassportIdentifiers(entries[i]);
	}

	return passportEntries;
}