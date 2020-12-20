#pragma once

#include <map>
#include <string>
#include <vector>

using std::map;
using std::stoi;
using std::string;
using std::vector;

struct MessageInstruction
{
public:
	MessageInstruction(string message = "")
	{
		if (message[0] == '"')
		{
			letter = message[1];
			letterInstruction = true;
		}
		else
		{
			letterInstruction = false;
			AssignVectorNumbers(message, firstInstruction);

			auto orPos = message.find('|');
			if (orPos != string::npos)
			{
				message = message.substr(orPos + 1);
				AssignVectorNumbers(message, secondInstruction);
			}
		}
	}

	bool letterInstruction;
	vector<int> firstInstruction;
	vector<int> secondInstruction;
	char letter;

private:
	void AssignVectorNumbers(string input, vector<int>& toAssignTo)
	{
		string line = "";

		for (int i = 0, len = input.length(); i < len; i++)
		{
			bool newInt = false;
			if (input[i] == '|')
			{
				break;
			}
			else if (input[i] != ' ')
			{
				line += input[i];
			}
			else
			{
				newInt = true;
			}

			if ((newInt || i == len - 1) && line != "")
			{
				toAssignTo.push_back(stoi(line));
				line.clear();
			}
		}
	}
};

class DayNineteenTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const map<int, MessageInstruction> GetMessageInstructions(string input);
	static const vector<string> GetValidEntries(int instructionNumber, map<int, MessageInstruction>& messageInstructions);
	static const vector<string> GetAllValidCombos(vector<vector<string>>& toCombine);
	static const int CountValidMsgs(vector<string>& validMessages, vector<string>& messagesToCheck);
	static const int CountAllValidEntriesAsWeGo(vector<string>& messages, vector<string>& fourtyTwoEval, vector<string>& thirtyOneEval);
	static const bool IsSectionPresent(string& msg, vector<string>& validSegments, bool atStart);
};