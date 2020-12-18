#pragma once

#include <deque>
#include <string>
#include <vector>

using std::deque;
using std::string;
using std::vector;

class DayEighteenTask
{
	enum class OperationType {ADD, MULTIPLY, NONE};

public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const unsigned long long CalculateEquation(string equation);
	static const unsigned long long CalculateEquationPartTwo(string equation);
	static const unsigned long long PerformOperation(unsigned long long a, unsigned long long b, OperationType operationToRun);
	static const int FindAppropriateCloseBracketIndex(string input);
};