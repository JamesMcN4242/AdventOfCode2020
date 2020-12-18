#pragma once

#include <deque>
#include <string>
#include <vector>

using std::deque;
using std::string;
using std::vector;

class DaySeventeenTask
{
public:
	static const int GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const int CountActiveCubes(deque<deque<string>>& cubes);
	static const void RunCycle(deque<deque<string>>& cubes);
	static const void Run4DCycle(deque<deque<deque<string>>>& cubes);
	static const void AddExternal3DLayers(deque<deque<string>>& cubes, const int contentSize, const int contentLength);
	static const void AddExternal4DLayers(deque<deque<deque<string>>>& cubes, const int contentSize, const int contentLength);
	static const deque<deque<string>> ConvertInputToMapSystem(vector<string>& input);
	static const int CountSurroundingActiveCubes(deque<deque<string>>& cubes, const int zPos, const int yPos, const int xPos, const int zSize, const int ySize, const int xSize);
	static const int CountSurroundingActiveCubes(deque<deque<deque<string>>>& cubes, const int wPos, const int zPos, const int yPos, const int xPos, const int wSize, const int zSize, const int ySize, const int xSize);
};