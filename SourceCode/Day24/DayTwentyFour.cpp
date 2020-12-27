#include "DayTwentyFour.h"
#include <algorithm>
#include <iterator>

using std::back_inserter;
using std::copy;

const unsigned long long DayTwentyFourTask::GetPartOneCode(vector<string> input)
{
	vector<Instructions> instructions = GetInstructions(input);
	map<pair<int, int>, bool> hexagonMap = GetHexagonMap(instructions);
	return CountBlackTiles(hexagonMap);
}

const unsigned long long DayTwentyFourTask::GetPartTwoCode(vector<string> input)
{
	vector<Instructions> instructions = GetInstructions(input);
	map<pair<int, int>, bool> hexagonMap = GetHexagonMap(instructions);
	RunFlipOperations(hexagonMap, 100);
	return CountBlackTiles(hexagonMap);
}

const vector<Instructions> DayTwentyFourTask::GetInstructions(vector<string>& input)
{
	vector<Instructions> instructions;
	copy(input.begin(), input.end(), back_inserter(instructions));
	return instructions;
}

const map<pair<int, int>, bool> DayTwentyFourTask::GetHexagonMap(vector<Instructions>& instructions)
{
	map<pair<int,int>, bool> hexaMap;

	for (int i = 0, len = instructions.size(); i < len; i++)
	{
		Instructions task = instructions[i];
		pair<int, int> currentPos(0, 0);
		for (int j = 0, jLen = task.list.size(); j < jLen; j++)
		{
			switch (task.list[j])
			{
			case Instructions::Direction::EAST:
				currentPos.first++;
				break;

			case Instructions::Direction::WEST:
				currentPos.first--;
				break;

			case Instructions::Direction::NORTH_EAST:
				if (currentPos.second % 2 == 0)
				{
					currentPos.first++;
				}
				currentPos.second++;
				break;

			case Instructions::Direction::NORTH_WEST:
				if (currentPos.second % 2 != 0)
				{
					currentPos.first--;
				}
				currentPos.second++;
				break;

			case Instructions::Direction::SOUTH_EAST:
				if (currentPos.second % 2 == 0)
				{
					currentPos.first++;
				}
				currentPos.second--;
				break;

			case Instructions::Direction::SOUTH_WEST:
				if (currentPos.second % 2 != 0)
				{
					currentPos.first--;
				}
				currentPos.second--;
				break;
			}
		}

		bool currentState = hexaMap[currentPos];
		hexaMap[currentPos] = !currentState;
	}

	return hexaMap;
}

const unsigned long long DayTwentyFourTask::CountBlackTiles(map<pair<int, int>, bool>& tiles)
{
	unsigned long long blackSquares = 0;
	for (auto it = tiles.begin(); it != tiles.end(); it++)
	{
		if (it->second)
		{
			blackSquares++;
		}
	}
	return blackSquares;
}

const void DayTwentyFourTask::RunFlipOperations(map<pair<int, int>, bool>& tiles, const int daysToRun)
{
	for (int i = 0; i < daysToRun; i++)
	{
		map<pair<int, int>, bool> copyTiles = tiles;
		for (auto it = tiles.begin(); it != tiles.end(); it++)
		{
			int surroundingBlackTiles = CountSurroundingBlackTiles(it->first, copyTiles, true);
			if (it->second)
			{
				it->second = !(surroundingBlackTiles == 0 || surroundingBlackTiles > 2);
				continue;
			}

			it->second = surroundingBlackTiles == 2;
		}

		for (auto copyIt = copyTiles.begin(); copyIt != copyTiles.end(); copyIt++)
		{
			if (tiles.find(copyIt->first) == tiles.end())
			{
				int surroundingBlackTiles = CountSurroundingBlackTiles(copyIt->first, copyTiles, false);
				tiles[copyIt->first] = surroundingBlackTiles == 2;
			}
		}
	}
}

const int DayTwentyFourTask::CountSurroundingBlackTiles(pair<int, int> position, map<pair<int, int>, bool>& tiles, bool createNewEntries)
{
	int countedSides = 0;

	if (createNewEntries)
	{
		countedSides += tiles[pair<int, int>(position.first - 1, position.second)];
		countedSides += tiles[pair<int, int>(position.first + 1, position.second)];
		countedSides += tiles[pair<int, int>(position.first, position.second + 1)];
		countedSides += tiles[pair<int, int>(position.first, position.second - 1)];

		int leftAdd = position.second % 2 == 0 ? 1 : -1;
		countedSides += tiles[pair<int, int>(position.first + leftAdd, position.second + 1)];
		countedSides += tiles[pair<int, int>(position.first + leftAdd, position.second - 1)];
	}
	else
	{
		auto tileEnd = tiles.end();
		countedSides += tiles.find(pair<int, int>(position.first - 1, position.second)) != tileEnd && tiles[pair<int, int>(position.first - 1, position.second)];
		countedSides += tiles.find(pair<int, int>(position.first + 1, position.second)) != tileEnd && tiles[pair<int, int>(position.first + 1, position.second)];
		countedSides += tiles.find(pair<int, int>(position.first, position.second + 1)) != tileEnd && tiles[pair<int, int>(position.first, position.second + 1)];
		countedSides += tiles.find(pair<int, int>(position.first, position.second - 1)) != tileEnd && tiles[pair<int, int>(position.first, position.second - 1)];

		int leftAdd = position.second % 2 == 0 ? 1 : -1;
		countedSides += tiles.find(pair<int, int>(position.first + leftAdd, position.second + 1)) != tileEnd && tiles[pair<int, int>(position.first + leftAdd, position.second + 1)];
		countedSides += tiles.find(pair<int, int>(position.first + leftAdd, position.second - 1)) != tileEnd && tiles[pair<int, int>(position.first + leftAdd, position.second - 1)];
	}

	return countedSides;
}
