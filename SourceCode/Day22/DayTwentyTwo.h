#pragma once

#include <string>
#include <queue>
#include <vector>

using std::string;
using std::queue;
using std::vector;

class DayTwentyTwoTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const queue<int> GetPlayerCards(string playerInput);
	static const void PlayToCompletion(queue<int>& p1Cards, queue<int>& p2Cards);
};