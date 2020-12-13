#pragma once

#include <functional>
#include <string>
#include <utility>
#include <vector>

using std::function;
using std::pair;
using std::string;
using std::vector;

class DayElevenTask
{
public:
	static const int GetPartOneCode(vector<string> input);
	static const int GetPartTwoCode(vector<string> input);
private:
	static const vector<string> RunIterationOfRules(const vector<string>& currentArrangement, bool& changesOccurred, const pair<int, int> areaDimensions, const int moveNumber, 
		function<int(const vector<string>&, const pair<int, int>, const pair<int, int>)> countMethod);
	static const int CountAllOccupiedSeats(const vector<string>& arrangement, const pair<int, int> areaDimensions);
	static const int CountAdjacentOccupiedSeats(const vector<string>& currentArrangement, const pair<int, int> areaDimensions, const pair<int, int> chairPosition);
	static const int CountAdjacentVisibleOccupiedSeats(const vector<string>& currentArrangement, const pair<int, int> areaDimensions, const pair<int, int> chairPosition);
	static const bool IsFirstSeatInDirectionOccupied(const vector<string>& currentArrangement, const pair<int, int> areaDimensions, const pair<int, int> chairPosition, const pair<int, int> direction);
};