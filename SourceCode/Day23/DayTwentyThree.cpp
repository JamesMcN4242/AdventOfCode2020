#include "DayTwentyThree.h"

using std::advance;

const string DayTwentyThreeTask::GetPartOneCode(string input)
{
	list<int> startList = GetLinkinedList(input);
	RunGamePartOne(startList, 100);
	return GetOutPutFromList(startList);
}

const unsigned long long DayTwentyThreeTask::GetPartTwoCode(string input)
{
	map<int, Cup> cupMap = GetMapOfCupsPartTwo(input);
	RunGamePartTwo(cupMap, 10000000);

	Cup nextCup = cupMap[cupMap[1].nextCupValue];
	unsigned long long a = nextCup.cupValue;
	unsigned long long b = nextCup.nextCupValue;

	return a * b;
}

//Sufficient for part one, but the sheer size of part two calls for another implementation
const void DayTwentyThreeTask::RunGamePartOne(list<int>& currentOrder, int iterations)
{
	const int highestValue = currentOrder.size();
	list<int> pickedUp;

	for (int i = 0; i < iterations; i++)
	{
		auto pickUpStart = currentOrder.begin();
		advance(pickUpStart, 1);

		auto pickUpEnd = pickUpStart;
		advance(pickUpEnd, 3);

		pickedUp.splice(pickedUp.begin(), currentOrder, pickUpStart, pickUpEnd);
		int destinationNumber = GetNextDestination(currentOrder, pickedUp, highestValue);

		//Move the current cup to the back of our line since it's not actually in a ring like originally planned
		currentOrder.push_back(currentOrder.front());
		currentOrder.pop_front();

		for (auto it = currentOrder.begin(); it != currentOrder.end(); it++)
		{
			if (*it == destinationNumber)
			{
				it++;
				currentOrder.splice(it, pickedUp);
				break;
			}
		}
	}
}

const int DayTwentyThreeTask::GetNextDestination(list<int>& currentOrder, list<int>& pickedUp, const int highestValue)
{
	int valueToHit = *(currentOrder.begin()) - 1;
	while (true)
	{
		if (valueToHit <= 0) valueToHit = highestValue;
		bool inHand = false;

		for (auto heldIt = pickedUp.begin(); heldIt != pickedUp.end(); heldIt++)
		{
			if (valueToHit == *heldIt)
			{
				inHand = true;
				break;
			}
		}

		if (!inHand) break;
		valueToHit--;
	}
	return valueToHit;
}

const list<int> DayTwentyThreeTask::GetLinkinedList(string input)
{
	list<int> startList;

	for (int i = 0, len = input.size(); i < len; i++)
	{
		startList.push_back(input[i] - 48);
	}

	return startList;
}

const string DayTwentyThreeTask::GetOutPutFromList(list<int>& input)
{
	string result;
	auto iterator = input.begin();

	//find start and end node
	while (iterator != input.end() && *iterator != 1)
	{
		iterator++;
	}

	auto it = iterator;
	it++;
	for (; it != input.end(); it++)
	{
		result += (*it + 48);
	}
	for (it = input.begin(); it != iterator; it++)
	{
		result += (*it + 48);
	}
	
	return result;
}

const void DayTwentyThreeTask::RunGamePartTwo(map<int, Cup>& cupMap, int iterations)
{
	const int highestValue = cupMap.size();
	Cup currentCup = cupMap[cupMap[highestValue].nextCupValue];

	for (int i = 0; i < iterations; i++)
	{
		int destinationCup = currentCup.cupValue;
		while (true)
		{
			destinationCup--;
			if (destinationCup <= 0) destinationCup = highestValue;

			bool inHand = false;
			Cup toFollow = currentCup;
			for (int i = 0; i < 3; i++)
			{
				toFollow = cupMap[toFollow.nextCupValue];
				if (toFollow.cupValue == destinationCup)
				{
					inHand = true;
					break;
				}
			}

			if (!inHand) break;
		}

		Cup destination = cupMap[destinationCup];
		int endDest = destination.nextCupValue;
		destination.nextCupValue = currentCup.nextCupValue;
		cupMap[destinationCup] = destination;

		Cup lastPickUp = cupMap[currentCup.nextCupValue];
		for (int i = 0; i < 2; i++)
		{
			lastPickUp = cupMap[lastPickUp.nextCupValue];
		}

		currentCup.nextCupValue = lastPickUp.nextCupValue;
		cupMap[currentCup.cupValue] = currentCup;

		lastPickUp.nextCupValue = endDest;
		cupMap[lastPickUp.cupValue] = lastPickUp;

		currentCup = cupMap[currentCup.nextCupValue];
	}
}

const map<int, Cup> DayTwentyThreeTask::GetMapOfCupsPartTwo(string input)
{
	map<int, Cup> cupMap;

	const int inputSize = input.size();
	int nextCupVal = inputSize + 1;

	for (int i = inputSize - 1; i >= 0; i--)
	{
		int cupVal = input[i] - 48;
		cupMap[cupVal] = Cup(cupVal, nextCupVal);
		nextCupVal = cupVal;
	}

	for (int i = 1000000; i > inputSize; i--)
	{
		cupMap[i] = Cup(i, nextCupVal);
		nextCupVal = i;
	}

	return cupMap;
}