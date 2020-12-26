#pragma once

#include "../InputGrabber/InputGrabber.h"
#include <string>
#include <vector>

using std::fill_n;
using std::stoi;
using std::string;
using std::vector;

struct Tile
{
public:
	Tile(string input = "")
	{
		fill_n(connections, 4, -1);
		if (input == "") return;

		auto colonIndex = input.find(':');
		auto spaceIndex = input.find(' ');
		tileNumber = stoi(input.substr(spaceIndex + 1, colonIndex - spaceIndex));

		input = input.substr(colonIndex + 1, input.size() - colonIndex - 1);
		vector<string> lines = InputGrabber::GetEachLine(input, '\n');
		const int lineCount = lines.size();
		sides[0] = lines[0];
		sides[2] = lines[lineCount - 1];

		const int lineSize = sides[0].size();
		for (int i = 0; i < lineCount; i++)
		{
			if (lines[i] != "")
			{
				sides[1] += lines[i][lineSize - 1];
				sides[3] += lines[i][0];

				if (i > 0 && i < lineCount - 1)
				{
					internals.push_back(lines[i].substr(1, lineSize - 2));
				}
			}
		}
	}

	int ConnectionsMade()
	{
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			if (connections[i] != -1)
			{
				count++;
			}
		}
		return count;
	}

	void RotateClockwise()
	{
		int temp = connections[0];
		connections[0] = connections[3];
		connections[3] = connections[2];
		connections[2] = connections[1];
		connections[1] = temp;

		string strTemp = sides[0];
		sides[0] = sides[3];
		sides[3] = sides[2];
		sides[2] = sides[1];
		sides[1] = strTemp;

		reverse(sides[0].begin(), sides[0].end());
		reverse(sides[2].begin(), sides[2].end());

		vector<string> newInternals;
		newInternals.resize(internals.size());
		for (int i = internals.size() - 1; i >= 0; i--)
		{
			for (int j = 0, jLen = internals[i].size(); j < jLen; j++)
			{
				newInternals[j] += internals[i][j];
			}
		}

		internals = newInternals;
	}

	void FlipTile()
	{
		int temp = connections[1];
		connections[1] = connections[3];
		connections[3] = temp;

		string strTemp = sides[1];
		sides[1] = sides[3];
		sides[3] = strTemp;
		reverse(sides[0].begin(), sides[0].end());
		reverse(sides[2].begin(), sides[2].end());

		for (int i = 0, len = internals.size(); i < len; i++)
		{
			reverse(internals[i].begin(), internals[i].end());
		}
	}

	int tileNumber;
	string sides[4];
	int connections[4];
	vector<string> internals;
};

class DayTwentyTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const vector<Tile> GetTiles(vector<string>& input);
	static const void ConnectPieces(vector<Tile>& tiles);
	static const vector<Tile> GetCornerPieces(vector<Tile>& tiles);
	static const Tile MakeIntoOneMap(vector<Tile>& tiles);
	static const Tile GetLowerOrDefaultTile(Tile startTile, vector<Tile>& nonOrientedTiles);
	static const Tile GetNextOrDefaultTile(Tile startTile, vector<Tile>& nonOrientedTiles);
	static const void OrientTile(Tile& correctTile, Tile& toOrientAccordingly);
	static const unsigned long long GetWaterRoughness(Tile& mapTile);
	static const bool SpottedSeaMonsters(Tile& mapTile, vector<string>& seaMonster);
	static const bool IsSeaMonsterPresent(vector<string>& internals, int startLine, int startCharIndex, vector<string>& seaMonster);
	static const void WriteSeaMonsterAtLocation(vector<string>& internals, int startLine, int startCharIndex, vector<string>& seaMonster);
};