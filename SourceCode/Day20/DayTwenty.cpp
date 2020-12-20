#include "DayTwenty.h"
#include <algorithm>
#include <iterator>

using std::back_inserter;
using std::copy;
using std::reverse;

const unsigned long long DayTwentyTask::GetPartOneCode(vector<string> input)
{
	vector<Tile> tiles = GetTiles(input);
	ConnectPieces(tiles);
	vector<Tile> corners = GetCornerPieces(tiles);

	unsigned long long cornerMulti = 1;
	for (int i = 0; i < 4; i++)
	{
		unsigned long long id = corners[i].tileNumber;
		cornerMulti *= id;
	}
	return cornerMulti;
}

const unsigned long long DayTwentyTask::GetPartTwoCode(vector<string> input)
{
	return 0;
}

const vector<Tile> DayTwentyTask::GetTiles(vector<string>& input)
{
	vector<Tile> tiles;
	copy(input.begin(), input.end(), back_inserter(tiles));
	return tiles;
}

const void DayTwentyTask::ConnectPieces(vector<Tile>& tiles)
{
	const int tileLength = tiles.size();
	for (int i = 0; i < tileLength - 1; i++)
	{
		Tile tileToUse = tiles[i];
		for (int j = 0; j < 4; j++)
		{
			bool matched = false;
			string side = tileToUse.sides[j];
			string flippedSide = tileToUse.sides[j];
			reverse(flippedSide.begin(), flippedSide.end());

			for (int k = i + 1; k < tileLength; k++)
			{
				Tile toCompare = tiles[k];
				for (int l = 0; l < 4; l++)
				{
					if (toCompare.connections[l] >= 0) continue;
					if (toCompare.sides[l] == side || toCompare.sides[l] == flippedSide)
					{
						matched = true;
						toCompare.connections[l] = tileToUse.tileNumber;
						tiles[k] = toCompare;
						break;
					}
				}

				if (matched)
				{
					tileToUse.connections[j] = toCompare.tileNumber;
					tiles[i] = tileToUse;
					break;
				}
			}
		}
	}
}

const vector<Tile> DayTwentyTask::GetCornerPieces(vector<Tile>& tiles)
{
	vector<Tile> corners;
	const int tilesSize = tiles.size();
	for (int i = 0; i < tilesSize; i++)
	{
		if (tiles[i].ConnectionsMade() == 2)
		{
			corners.push_back(tiles[i]);
		}
	}

	return corners;
}
