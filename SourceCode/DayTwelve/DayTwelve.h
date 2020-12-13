#pragma once

#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

struct ShipInstruction
{
public:

	enum InstructionType
	{
		NORTH, EAST, SOUTH, WEST, LEFT, RIGHT, FORWARD
	};

	ShipInstruction(const string instruction = "")
	{
		switch (instruction[0])
		{
		case 'N': instructionType = NORTH; break;
		case 'S': instructionType = SOUTH; break;
		case 'E': instructionType = EAST; break;
		case 'W': instructionType = WEST; break;
		case 'L': instructionType = LEFT; break;
		case 'R': instructionType = RIGHT; break;
		case 'F': instructionType = FORWARD; break;
		}

		value = std::stoi(instruction.substr(1));
	}

	InstructionType instructionType;
	int value;
};

class DayTwelveTask
{
public:

	enum FacingDirection
	{
		NORTH, EAST, SOUTH, WEST, COUNT
	};

	static const int GetPartOneCode(vector<string> input);
	static const int GetPartTwoCode(vector<string> input);
private:
	static const pair<int, int> GetShipLocationFromMisunderstoodInstructions(const vector<ShipInstruction>& instructions);
	static const pair<int, int> GetShipLocationFromCorrectInstructions(const vector<ShipInstruction>& instructions);
	static const vector<ShipInstruction> GetShipInstructions(const vector<string>& input);
	static void MovePosition(pair<int, int>& position, int valueToMove, FacingDirection direction);
	static void RotateWayPointAroundShip(pair<int, int>& waypointPos, int degrees);
	static const int GetManhattanDistanceFromOrigin(const pair<int, int> position);
};