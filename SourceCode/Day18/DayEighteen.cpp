#include "DayEighteen.h"

using std::stoull;

const unsigned long long DayEighteenTask::GetPartOneCode(vector<string> input)
{
	unsigned long long result = 0;
	for (int i = 0, len = input.size(); i < len; i++)
	{
		unsigned long long calculated = CalculateEquation(input[i]);
		result += calculated;
	}
	return result;
}

const unsigned long long DayEighteenTask::GetPartTwoCode(vector<string> input)
{
	return 0;
}

const unsigned long long DayEighteenTask::CalculateEquation(string equation)
{
	OperationType operationToRun = OperationType::NONE;
	auto foundSpaceIndex = equation.find(' ');
	unsigned long long result = 0;

	while (equation.size() > 0)
	{
		switch (equation[0])
		{
		case '+':
			operationToRun = OperationType::ADD;
			break;

		case '*':
			operationToRun = OperationType::MULTIPLY;
			break;

		case '(':
		{
			int closeBracketIndex = FindAppropriateCloseBracketIndex(equation);
			string internalEquation = equation.substr(1, closeBracketIndex - 1);
			unsigned long long internalVal = CalculateEquation(internalEquation);
			result = PerformOperation(result, internalVal, operationToRun);
			operationToRun = OperationType::NONE;
			foundSpaceIndex = closeBracketIndex + 1;
			break;
		}

		default:
			unsigned long long operationNum = stoull(equation.substr(0, foundSpaceIndex));
			result = PerformOperation(result, operationNum, operationToRun);
			operationToRun = OperationType::NONE;
			break;
		}

		if (foundSpaceIndex < equation.size())
		{
			equation = equation.substr(foundSpaceIndex + 1);
			foundSpaceIndex = equation.find(' ');
		}
		else
		{
			break;
		}
	}

	return result;
}

const unsigned long long DayEighteenTask::PerformOperation(unsigned long long a, unsigned long long b, OperationType operationToRun)
{
	switch (operationToRun)
	{
	case DayEighteenTask::OperationType::ADD:
		return a + b;
	case DayEighteenTask::OperationType::MULTIPLY:
		return a * b;

	//Means we are seeing our first number
	case DayEighteenTask::OperationType::NONE:
	default:
		return b;
	}
}

const int DayEighteenTask::FindAppropriateCloseBracketIndex(string input)
{
	int bracketsOpen = 1;
	for (int i = 1, len = input.size(); i < len; i++)
	{
		if (input[i] == '(')
		{
			bracketsOpen++;
		}
		else if (input[i] == ')')
		{
			bracketsOpen--;
			if (bracketsOpen == 0)
			{
				return i;
			}
		}
	}

	return -1;
}
