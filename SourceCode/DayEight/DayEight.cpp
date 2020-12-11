#include "DayEight.h"
#include <algorithm>

using std::find;
using std::stoi;

const int DayEightTask::GetPartOneCode(const string inputToBreak)
{
	vector<Operation> operations = GetOperations(inputToBreak);
	return RunOperationsTillLoop(operations);
}

const int DayEightTask::GetPartTwoCode(const string inputToBreak)
{
	vector<Operation> operations = GetOperations(inputToBreak);
	return RunOperationsWithFixedLoop(operations);
}

const int DayEightTask::RunOperationsTillLoop(vector<Operation> operations)
{
	int accumulator = 0;
	int instructionIndex = 0;
	int instructionSize = operations.size();
	vector<int> instructionsUsed;

	while (instructionIndex < instructionSize)
	{
		if (find(instructionsUsed.begin(), instructionsUsed.end(), instructionIndex) != instructionsUsed.end())
		{
			break;
		}

		Operation op = operations[instructionIndex];
		instructionsUsed.push_back(instructionIndex);
		accumulator += op.GetAccumulation();
		instructionIndex += op.GetIndexJumps();
	}

	return accumulator;
}

const int DayEightTask::RunOperationsWithFixedLoop(vector<Operation> operations)
{
	int instructionSize = operations.size();
	int occurrenceToChange = 1;

	while (true)
	{
		int accumulator = 0;
		int instructionIndex = 0;
		int jumpsOrNoOpsHit = 0;
		vector<int> instructionsUsed;
		bool finishedNaturally = true;

		while (instructionIndex < instructionSize)
		{
			if (find(instructionsUsed.begin(), instructionsUsed.end(), instructionIndex) != instructionsUsed.end())
			{
				finishedNaturally = false;
				break;
			}

			Operation op = operations[instructionIndex];

			if (op.IsJumpOrNoOp())
			{
				jumpsOrNoOpsHit++;
				if (jumpsOrNoOpsHit == occurrenceToChange)
				{
					op.FlipJumpOrNoOp();
				}
			}

			instructionsUsed.push_back(instructionIndex);
			accumulator += op.GetAccumulation();
			instructionIndex += op.GetIndexJumps();
		}

		if (finishedNaturally)
		{
			return accumulator;
		}
		occurrenceToChange++;
	}

	return -1;
}

vector<string> DayEightTask::GetPerLineArray(const string input)
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

vector<Operation> DayEightTask::GetOperations(const string input)
{
	vector<string> lines = GetPerLineArray(input);
	vector<Operation> operations;

	for (int i = 0, len = lines.size(); i < len; i++)
	{
		string type = lines[i].substr(0, 3);
		int value = stoi(lines[i].substr(3));
		Operation operation(type, value);
		operations.push_back(operation);
	}

	return operations;
}
