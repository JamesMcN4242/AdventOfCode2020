#pragma once

#include <string>
#include <deque>
#include <vector>

using std::deque;
using std::string;
using std::vector;

class DayTwentyTwoTask
{
public:
	static const unsigned long long GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const deque<int> GetPlayerCards(string playerInput);
	static const void PlayToCompletion(deque<int>& p1Cards, deque<int>& p2Cards);
	static const void PlayRecursiveGames(deque<int>& p1Cards, deque<int>& p2Cards);
	static const unsigned long long GetWinnerScore(deque<int>& winningHand);
};