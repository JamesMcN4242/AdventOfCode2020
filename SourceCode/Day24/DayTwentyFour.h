#pragma once

#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map;
using std::string;
using std::pair;
using std::vector;

struct Instructions
{
public:
	enum class Direction {EAST, SOUTH_EAST, SOUTH_WEST, WEST, NORTH_WEST, NORTH_EAST};

	Instructions(string input = "")
	{
		//Setup all directions
		const int inputSize = input.size();
		bool northComponent = false;
		bool verticalComponent = false;
		for (int i = 0; i < inputSize; i++)
		{
			switch (input[i])
			{
			case 'e':
				if (verticalComponent)
				{
					list.push_back(northComponent ? Direction::NORTH_EAST : Direction::SOUTH_EAST);
					verticalComponent = false;
				}
				else
				{
					list.push_back(Direction::EAST);
				}
				break;

			case 'w':
				if (verticalComponent)
				{
					list.push_back(northComponent ? Direction::NORTH_WEST : Direction::SOUTH_WEST);
					verticalComponent = false;
				}
				else
				{
					list.push_back(Direction::WEST);
				}
				break;

			case 'n':
			case 's':
				verticalComponent = true;
				northComponent = input[i] == 'n';
				break;
			}
		}
	}

	vector<Direction> list;
};

class DayTwentyFourTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const vector<Instructions> GetInstructions(vector<string>& input);
	static const map<pair<int, int>, bool> GetHexagonMap(vector<Instructions>& instructions);
	static const unsigned long long CountBlackTiles(map<pair<int, int>, bool>& tiles);
	static const void RunFlipOperations(map<pair<int, int>, bool>& tiles, const int daysToRun);
	static const int CountSurroundingBlackTiles(pair<int, int> position, map<pair<int, int>, bool>& tiles, bool createNewEntries);
};