#include "DayNineteen.h"
#include "../InputGrabber/InputGrabber.h"

const unsigned long long DayNineteenTask::GetPartOneCode(vector<string> input)
{
	map<int, MessageInstruction> instructions = GetMessageInstructions(input[0]);
	vector<string> messages = InputGrabber::GetEachLine(input[1], '\n');
	vector<string> validEntries = GetValidEntries(0, instructions);
	return CountValidMsgs(validEntries, messages);
}

const unsigned long long DayNineteenTask::GetPartTwoCode(vector<string> input)
{
	return 0;
}

const map<int, MessageInstruction> DayNineteenTask::GetMessageInstructions(string input)
{
	vector<string> instructions = InputGrabber::GetEachLine(input, '\n');
	map<int, MessageInstruction> messageInstructions;

	for (int i = 0, len = instructions.size(); i < len; i++)
	{
		string instr = instructions[i];
		auto colonPos = instr.find(':');

		int instructionNumber = stoi(instr.substr(0, colonPos));
		MessageInstruction msg(instr.substr(colonPos + 2));
		messageInstructions[instructionNumber] = msg;
	}

	return messageInstructions;
}

const vector<string> DayNineteenTask::GetValidEntries(int instructionNumber, map<int, MessageInstruction>& messageInstructions)
{
	MessageInstruction instruction = messageInstructions[instructionNumber];

	if (instruction.letterInstruction)
	{
		vector <string> returnVal;
		string toPush;
		toPush += instruction.letter;
		returnVal.push_back(toPush);
		return returnVal;
	}

	vector<vector<string>> firstPartOutcomes;
	for (int i = 0, len = instruction.firstInstruction.size(); i < len; i++)
	{
		int nextInstruction = instruction.firstInstruction[i];
		firstPartOutcomes.push_back(GetValidEntries(nextInstruction, messageInstructions));
	}
	vector<string> partOneCombos = GetAllValidCombos(firstPartOutcomes);

	const int partTwoSize = instruction.secondInstruction.size();
	if (partTwoSize == 0) return partOneCombos;

	vector<vector<string>> secondPartOutcomes;
	for (int i = 0; i < partTwoSize; i++)
	{
		int nextInstruction = instruction.secondInstruction[i];
		secondPartOutcomes.push_back(GetValidEntries(nextInstruction, messageInstructions));
	}
	vector<string> partTwoCombos = GetAllValidCombos(secondPartOutcomes);
	
	vector<string> allOutcomes;
	allOutcomes.reserve(partOneCombos.size() + partTwoCombos.size());
	allOutcomes.insert(allOutcomes.end(), partOneCombos.begin(), partOneCombos.end());
	allOutcomes.insert(allOutcomes.end(), partTwoCombos.begin(), partTwoCombos.end());
	return allOutcomes;
}

const vector<string> DayNineteenTask::GetAllValidCombos(vector<vector<string>>& toCombine)
{
	vector<string> combos;

	const int timesToAdd = toCombine.size() >= 2 ? toCombine[1].size() : 1;
	const int firstLayerSize = toCombine[0].size();
	for (int i = 0; i < firstLayerSize; i++)
	{
		for (int j = 0; j < timesToAdd; j++)
		{
			combos.push_back(toCombine[0][i]);
		}
	}

	if (toCombine.size() == 1) return combos;

	for (int i = 0; i < timesToAdd; i++)
	{
		for (int j = 0; j < firstLayerSize; j++)
		{
			combos[(j * timesToAdd) + i] += toCombine[1][i];
		}
	}

	if (toCombine.size() == 3)
	{
		vector<vector<string>> nextCombination;
		nextCombination.push_back(combos);
		nextCombination.push_back(toCombine[2]);
		return GetAllValidCombos(nextCombination);
	}

	return combos;
}

const int DayNineteenTask::CountValidMsgs(vector<string>& validMessages, vector<string>& messagesToCheck)
{
	int count = 0;

	for (int i = 0, len = messagesToCheck.size(); i < len; i++)
	{
		string message = messagesToCheck[i];
		for (int j = 0, jLen = validMessages.size(); j < jLen; j++)
		{
			if (message == validMessages[j])
			{
				count++;
				break;
			}
		}
	}

	return count;
}
