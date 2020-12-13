#include "DayTwelve.h"

#define PI 3.14159265f

#include <algorithm>
#include <cmath>
#include <iterator>

using std::abs;
using std::back_inserter;
using std::copy;
using std::cos;
using std::sin;


const int DayTwelveTask::GetPartOneCode(vector<string> input)
{
	vector<ShipInstruction> instructions = GetShipInstructions(input);
	const pair<int, int> position = GetShipLocationFromMisunderstoodInstructions(instructions);
	return GetManhattanDistanceFromOrigin(position);
}

const int DayTwelveTask::GetPartTwoCode(vector<string> input)
{
	vector<ShipInstruction> instructions = GetShipInstructions(input);
	const pair<int, int> position = GetShipLocationFromCorrectInstructions(instructions);
	return GetManhattanDistanceFromOrigin(position);
}

const pair<int, int> DayTwelveTask::GetShipLocationFromMisunderstoodInstructions(const vector<ShipInstruction>& instructions)
{
	pair<int, int> currentCoordinates(0, 0);
	FacingDirection currentDirection = EAST;
	int instructionSize = instructions.size();

	for (int i = 0; i < instructionSize; i++)
	{
		ShipInstruction instruction = instructions[i];
		switch (instruction.instructionType)
		{
			case ShipInstruction::NORTH:
			case ShipInstruction::SOUTH:
			case ShipInstruction::EAST:
			case ShipInstruction::WEST:
			{
				FacingDirection direction = (FacingDirection)(instruction.instructionType);	//Since both N, E, S, W are in the same order
				MovePosition(currentCoordinates, instruction.value, direction);
				break;
			}

			case ShipInstruction::LEFT:
			{
				int newPos = currentDirection - (instruction.value / 90);
				currentDirection = (FacingDirection)(newPos < 0 ? COUNT + newPos : newPos);
				break;
			}
			case ShipInstruction::RIGHT:
			{
				int newPos = currentDirection + (instruction.value / 90);
				currentDirection = (FacingDirection)(newPos % COUNT);
				break;
			}
			case ShipInstruction::FORWARD:
			{
				MovePosition(currentCoordinates, instruction.value, currentDirection);
				break;
			}
		}
	}

	return currentCoordinates;
}

const pair<int, int> DayTwelveTask::GetShipLocationFromCorrectInstructions(const vector<ShipInstruction>& instructions)
{
	FacingDirection waypointDirection = EAST;
	pair<int, int> wayPointOffset(10, 1);
	pair<int, int> shipsCoordinates(0, 0);
	int instructionSize = instructions.size();

	for (int i = 0; i < instructionSize; i++)
	{
		ShipInstruction instruction = instructions[i];
		switch (instruction.instructionType)
		{
			case ShipInstruction::NORTH:
			case ShipInstruction::SOUTH:
			case ShipInstruction::EAST:
			case ShipInstruction::WEST:
			{
				FacingDirection direction = (FacingDirection)(instruction.instructionType);	//Since both N, E, S, W are in the same order
				MovePosition(wayPointOffset, instruction.value, direction);
				break;
			}

			case ShipInstruction::LEFT:
			{
				RotateWayPointAroundShip(wayPointOffset, instruction.value);
				break;
			}

			case ShipInstruction::RIGHT:
			{
				RotateWayPointAroundShip(wayPointOffset, 360 - instruction.value);
				break;
			}

			case ShipInstruction::FORWARD:
			{
				MovePosition(shipsCoordinates, abs(wayPointOffset.first) * instruction.value, wayPointOffset.first > 0 ? EAST : WEST);
				MovePosition(shipsCoordinates, abs(wayPointOffset.second) * instruction.value, wayPointOffset.second > 0 ? NORTH : SOUTH);
				break;
			}
		}
	}

	return shipsCoordinates;
}

const vector<ShipInstruction> DayTwelveTask::GetShipInstructions(const vector<string>& input)
{
	vector<ShipInstruction> instructions;
	copy(input.begin(), input.end(), back_inserter(instructions));
	return instructions;
}

void DayTwelveTask::MovePosition(pair<int, int>& position, int valueToMove, FacingDirection direction)
{
	switch (direction)
	{
	case DayTwelveTask::NORTH:
		position.second += valueToMove;
		break;
	case DayTwelveTask::EAST:
		position.first += valueToMove;
		break;
	case DayTwelveTask::SOUTH:
		position.second -= valueToMove;
		break;
	case DayTwelveTask::WEST:
		position.first -= valueToMove;
		break;
	}
}

void DayTwelveTask::RotateWayPointAroundShip(pair<int, int>& waypointPos, int degrees)
{
	/*
	Since we're lucky enough to have only 90 degree rotations around an origin (since we use the pos as an offset from the ship),
	we can simply the maths to a few placement and sign flippings. Such that (x, y) rotated 90 degrees round the origin becomes (-y, x)
	*/
	for (int i = 1; i <= degrees / 90; i++)
	{
		int xBeforeSwap = waypointPos.first;
		waypointPos.first = -waypointPos.second;
		waypointPos.second = xBeforeSwap;
	}
}

const int DayTwelveTask::GetManhattanDistanceFromOrigin(const pair<int, int> position)
{
	return abs(position.first) + abs(position.second);
}
