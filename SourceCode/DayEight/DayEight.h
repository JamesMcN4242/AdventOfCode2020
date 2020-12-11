#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Operation
{
	enum OperationType {NO_OPERTATION, ACCUMULATE, JUMP_INSTRUCTION};

public:	
	Operation(string typeTxt = "", int val = 0) : value(val)
	{
		if (typeTxt == "acc")
		{
			type = ACCUMULATE;
		}
		else if (typeTxt == "jmp")
		{
			type = JUMP_INSTRUCTION;
		}
		else
		{
			type = NO_OPERTATION;
		}
	}

	int GetAccumulation()
	{
		return type == ACCUMULATE ? value : 0;
	}

	int GetIndexJumps()
	{
		return type == JUMP_INSTRUCTION ? value : 1;
	}

	bool IsJumpOrNoOp()
	{
		return type != ACCUMULATE;
	}

	void FlipJumpOrNoOp()
	{
		type = type == NO_OPERTATION ? JUMP_INSTRUCTION : NO_OPERTATION;
	}

private:
	int value;
	OperationType type;
};

class DayEightTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const int GetPartTwoCode(const string inputToBeBroken);
private:
	static const int RunOperationsTillLoop(vector<Operation> operations);
	static const int RunOperationsWithFixedLoop(vector<Operation> operations);
	static vector<string> GetPerLineArray(const string input);
	static vector<Operation> GetOperations(const string input);
};