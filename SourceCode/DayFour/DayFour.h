#pragma once

#include <string>
#include <vector>
#include <valarray>

using std::stoi;
using std::string;
using std::vector;
using std::valarray;

struct PassportIdentifiers
{
public:
	PassportIdentifiers() : PassportIdentifiers("") {}

	PassportIdentifiers(string content)
	{
		byr = GetEntryOrEmpty("byr", content);
		iyr = GetEntryOrEmpty("iyr", content);
		eyr = GetEntryOrEmpty("eyr", content);
		hgt = GetEntryOrEmpty("hgt", content);
		hcl = GetEntryOrEmpty("hcl", content);
		ecl = GetEntryOrEmpty("ecl", content);
		pid = GetEntryOrEmpty("pid", content);
		cid = GetEntryOrEmpty("cid", content);
	}

	bool IsPartOneValid()
	{
		return byr != "" && iyr != "" && eyr != "" && hgt != "" && hcl != "" && ecl != "" && pid != "";
	}

	bool IsPartTwoValid()
	{
		if (!IsPartOneValid()) return false;

		bool byrValid = IsNumberValid(byr, 4, 1920, 2002);
		bool iyrValid = IsNumberValid(iyr, 4, 2010, 2020);
		bool eyrValid = IsNumberValid(eyr, 4, 2020, 2030);

		string heightChars = hgt.substr(hgt.length() - 2);
		string heightNum = hgt.substr(0, hgt.length() - 2);
		bool hgtValid = (heightChars == "cm" && IsNumberValid(heightNum, 3, 150, 193)) || (heightChars == "in" && IsNumberValid(heightNum, 2, 59, 76));

		bool hclValid = IsHairColourValid();

		bool eclValid = ecl == "amb" || ecl == "blu" || ecl == "brn" || ecl == "gry" || ecl == "grn" || ecl == "hzl" || ecl == "oth";
		bool pidValid = pid.length() == 9;

		return byrValid && iyrValid && eyrValid && hgtValid && hclValid && eclValid && pidValid;
	}

private:

	string GetEntryOrEmpty(string entryKey, string content)
	{
		string entry = "";
		int keyLen = entryKey.length();
		entryKey += ":";
		bool startedKey = false;

		for (int i = 0, len = content.length(); i < len; i++)
		{
			if (startedKey)
			{
				if (content[i] == ' ' || content[i] == '\n')
				{
					return entry;
				}

				entry += content[i];
			}
			else if (i + keyLen < len)
			{
				if (StringAtIndexMatches(content, entryKey, i))
				{
					startedKey = true;
					i += keyLen;
				}
			}
			else
			{
				break;
			}
		}

		return entry;
	}

	bool StringAtIndexMatches(string content, string key, int contentStartIndx)
	{
		for (int i = 0, len = key.length(); i < len; i++)
		{
			if (content[contentStartIndx + i] != key[i])
			{
				return false;
			}
		}

		return true;
	}

	bool IsNumberValid(string entry, const int entrySizeRequired, const int min, const int max)
	{
		if (entry.size() != entrySizeRequired) return false;

		int value = stoi(entry);
		return value >= min && value <= max;
	}

	bool IsHairColourValid()
	{
		if (hcl.length() != 7 || hcl[0] != '#') return false;
		for (int i = 1, len = hcl.length(); i < len; i++)
		{
			if (hcl[i] < 48 || hcl[i] > 102) return false;
			if (hcl[i] > 57 && hcl[i] < 97) return false;
		}
		return true;
	}

	string byr, iyr, eyr, hgt, hcl, ecl, pid, cid;
};

class DayFourTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const int GetPartTwoCode(const string inputToBeBroken);
private:
	static vector<string> GetValueArray(const string inputToBreak, const int inputLen);
	static valarray<PassportIdentifiers> GetPassportIdentifiersFromStrings(vector<string> entries);
};