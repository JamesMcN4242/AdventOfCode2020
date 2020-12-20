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
		auto colonIndex = input.find(':');
		auto spaceIndex = input.find(' ');
		tileNumber = stoi(input.substr(spaceIndex + 1, colonIndex - spaceIndex));
		fill_n(connections, 4, -1);

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

	int tileNumber;
	string sides[4];
	int connections[4];
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
};