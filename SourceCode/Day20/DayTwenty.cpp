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
	vector<Tile> tiles = GetTiles(input);
	Tile map = MakeIntoOneMap(tiles);
	return GetWaterRoughness(map);
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

const Tile DayTwentyTask::MakeIntoOneMap(vector<Tile>& tiles)
{
	ConnectPieces(tiles);
	vector<Tile> corners = GetCornerPieces(tiles);
	Tile tileToWorkWith;

	//Get the first top left corner. Defined as a tile with (-1, x, y, -1) connections 
	for (auto it = corners.begin(); it != corners.end(); it++)
	{
		if (it->connections[0] == -1 && it->connections[3] == -1)
		{
			tileToWorkWith = *it;
			break;
		}
	}

	vector<vector<Tile>> tileMap;
	while (tileToWorkWith.ConnectionsMade() > 0)
	{
		vector<Tile> tileLine;

		while (tileToWorkWith.ConnectionsMade() > 0)
		{
			tileLine.push_back(tileToWorkWith);
			tileToWorkWith = GetNextOrDefaultTile(tileToWorkWith, tiles);
		}

		tileMap.push_back(tileLine);
		tileToWorkWith = GetLowerOrDefaultTile(tileMap[tileMap.size() - 1][0], tiles);
	}

	const int tileLineCount = tileMap[0].size();
	const int charactersInLine = tileLineCount * tileMap[0][0].internals.size();

	string externalLines;
	for (int i = 0; i < charactersInLine + 2; i++)
	{
		externalLines += "E";
	}

	string mapTile = "Tile 0:\n" + externalLines + "\n";
	for (int i = 0, outsideLen = tileMap.size(); i < outsideLen; i++)
	{
		vector<Tile> tilesInLine = tileMap[i];
		for (int j = 0, jLen = tilesInLine[0].internals.size(); j < jLen; j++)
		{
			mapTile += "E";
			for (int k = 0; k < tileLineCount; k++)
			{
				mapTile += tilesInLine[k].internals[j];
			}

			mapTile += "E";

			if (j < jLen - 1)
			{
				mapTile += "\n";
			}
		}

		mapTile += "\n";
	}

	mapTile += externalLines;
	return Tile(mapTile);
}

const Tile DayTwentyTask::GetNextOrDefaultTile(Tile startTile, vector<Tile>& nonOrientedTiles)
{
	int connectionNum = startTile.connections[1];
	if (connectionNum == -1) return Tile();

	for (auto it = nonOrientedTiles.begin(); it != nonOrientedTiles.end(); it++)
	{
		if (it->tileNumber == connectionNum)
		{
			OrientTile(startTile, *it);
			return *it;
		}
	}
}

const Tile DayTwentyTask::GetLowerOrDefaultTile(Tile startTile, vector<Tile>& nonOrientedTiles)
{
	int connectionNum = startTile.connections[2];
	if(connectionNum == -1) return Tile();

	for (auto it = nonOrientedTiles.begin(); it != nonOrientedTiles.end(); it++)
	{
		if (it->tileNumber == connectionNum)
		{
			OrientTile(startTile, *it);
			return *it;
		}
	}
}

const void DayTwentyTask::OrientTile(Tile& correctTile, Tile& toOrientAccordingly)
{
	//We only care to be connecting right or down at current
	int correctTileId = correctTile.tileNumber;
	int connectionPos = correctTile.connections[1] == toOrientAccordingly.tileNumber ? 1 : 2;
	int shouldConnectTo = (connectionPos + 2) % 4;

	for (int i = 0; i < 4; i++)
	{
		if (toOrientAccordingly.connections[shouldConnectTo] == correctTileId)
		{
			if (correctTile.sides[connectionPos] == toOrientAccordingly.sides[shouldConnectTo])
			{
				//Now oriented successfully!
				return;
			}
			
			//Going to have to flip it to get this done
			break;
		}

		toOrientAccordingly.RotateClockwise();
	}

	toOrientAccordingly.RotateClockwise();
	toOrientAccordingly.FlipTile();
	OrientTile(correctTile, toOrientAccordingly);
}

const unsigned long long DayTwentyTask::GetWaterRoughness(Tile& map)
{
	const string seaMonster = "                  # \n#    ##    ##    ###\n #  #  #  #  #  #   ";
	vector<string> seaMonsterVec = InputGrabber::GetEachLine(seaMonster, '\n');

	bool spotted = false;
	for (int i = 0; i < 4; i++)
	{
		if (SpottedSeaMonsters(map, seaMonsterVec))
		{
			spotted = true;
			break;
		}
		map.RotateClockwise();
	}

	if (!spotted)
	{
		map.RotateClockwise();
		map.FlipTile();
		return GetWaterRoughness(map);
	}

	unsigned long long roughness = 0;
	const int lineSize = map.internals[0].size();
	for (int i = 0, lineCount = map.internals.size(); i < lineCount; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			if (map.internals[i][j] == '#')
			{
				roughness++;
			}
		}
	}
	return roughness;
}

const bool DayTwentyTask::SpottedSeaMonsters(Tile& mapTile, vector<string>& seaMonster)
{
	int seaMonstersFound = 0;

	vector<string>& internals = mapTile.internals;
	const int lineCountToCheck = internals.size() - seaMonster.size();
	const int lineSizeToCheck = internals[0].size() - seaMonster[0].size();

	for (int i = 0; i <= lineCountToCheck; i++)
	{
		for (int j = 0; j <= lineSizeToCheck; j++)
		{
			if (IsSeaMonsterPresent(internals, i, j, seaMonster))
			{
				WriteSeaMonsterAtLocation(internals, i, j, seaMonster);
				seaMonstersFound++;
			}
		}
	}

	return seaMonstersFound > 0;
}

const bool DayTwentyTask::IsSeaMonsterPresent(vector<string>& internals, int startLine, int startCharIndex, vector<string>& seaMonster)
{
	const int lineSize = seaMonster[0].size();

	for (int i = 0, lineCount = seaMonster.size(); i < lineCount; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			if (seaMonster[i][j] == '#')
			{
				if (internals[startLine + i][startCharIndex + j] != '#')
				{
					return false;
				}
			}
		}
	}

	return true;
}

const void DayTwentyTask::WriteSeaMonsterAtLocation(vector<string>& internals, int startLine, int startCharIndex, vector<string>& seaMonster)
{
	const int lineSize = seaMonster[0].size();

	for (int i = 0, lineCount = seaMonster.size(); i < lineCount; i++)
	{
		for (int j = 0; j < lineSize; j++)
		{
			if (seaMonster[i][j] == '#')
			{
				internals[startLine + i][startCharIndex + j] = 'O';
			}
		}
	}
}
