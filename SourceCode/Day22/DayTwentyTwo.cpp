#include "DayTwentyTwo.h"
#include "../InputGrabber/InputGrabber.h"

using std::stoi;

const unsigned long long DayTwentyTwoTask::GetPartOneCode(vector<string> input)
{
	queue<int> playerOneCards = GetPlayerCards(input[0]);
	queue<int> playerTwoCards = GetPlayerCards(input[1]);
	PlayToCompletion(playerOneCards, playerTwoCards);
	queue<int> winnerQueue = playerOneCards.size() > 0 ? playerOneCards : playerTwoCards;

	unsigned long long count = 0;

	for (int i = 0, len = winnerQueue.size(); i < len; i++)
	{
		unsigned long long value = winnerQueue.front();
		winnerQueue.pop();
		value *= (unsigned long long)((int)len - i);
		count += value;
	}

	return count;
}

const unsigned long long DayTwentyTwoTask::GetPartTwoCode(vector<string> input)
{
	return 0;
}

const queue<int> DayTwentyTwoTask::GetPlayerCards(string playerInput)
{
	queue<int> cards;
	vector<string> lines = InputGrabber::GetEachLine(playerInput, '\n');

	for (int i = 1, len = lines.size(); i < len; i++)
	{
		cards.push(stoi(lines[i]));
	}

	return cards;
}

const void DayTwentyTwoTask::PlayToCompletion(queue<int>& p1Cards, queue<int>& p2Cards)
{
	while (p1Cards.size() > 0 && p2Cards.size() > 0)
	{
		int p1 = p1Cards.front();
		p1Cards.pop();

		int p2 = p2Cards.front();
		p2Cards.pop();

		if (p1 > p2)
		{
			p1Cards.push(p1);
			p1Cards.push(p2);
		}
		else if (p1 < p2)
		{
			p2Cards.push(p2);
			p2Cards.push(p1);
		}
		else
		{
			//Oh bother
			break;
		}
	}
}
