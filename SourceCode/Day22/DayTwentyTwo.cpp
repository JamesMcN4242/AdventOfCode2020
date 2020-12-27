#include "DayTwentyTwo.h"
#include "../InputGrabber/InputGrabber.h"

using std::stoi;

const unsigned long long DayTwentyTwoTask::GetPartOneCode(vector<string> input)
{
	deque<int> playerOneCards = GetPlayerCards(input[0]);
	deque<int> playerTwoCards = GetPlayerCards(input[1]);
	PlayToCompletion(playerOneCards, playerTwoCards);

	deque<int> winnerQueue = playerOneCards.size() > 0 ? playerOneCards : playerTwoCards;
	return GetWinnerScore(winnerQueue);
}

const unsigned long long DayTwentyTwoTask::GetPartTwoCode(vector<string> input)
{
	deque<int> playerOneCards = GetPlayerCards(input[0]);
	deque<int> playerTwoCards = GetPlayerCards(input[1]);
	PlayRecursiveGames(playerOneCards, playerTwoCards);

	deque<int> winnerQueue = playerOneCards.size() > 0 ? playerOneCards : playerTwoCards;
	return GetWinnerScore(winnerQueue);
}

const deque<int> DayTwentyTwoTask::GetPlayerCards(string playerInput)
{
	deque<int> cards;
	vector<string> lines = InputGrabber::GetEachLine(playerInput, '\n');

	for (int i = 1, len = lines.size(); i < len; i++)
	{
		cards.push_back(stoi(lines[i]));
	}

	return cards;
}

const void DayTwentyTwoTask::PlayRecursiveGames(deque<int>& p1Cards, deque<int>& p2Cards)
{
	// It works.. But super slowly. I think I should have used an unordered_set in order to make this faster. 
	// As opposed to trucking through just a whole ton of data I've allocated for each deque used... Terrible idea in hindsight.
	// Assuming I remember later on when I'm less burnt out, then this is one I really would like to come back to and fix up.
	// Because frankly this solution shouldn't see the light of day for how unoptimal it is. Silly choices all round.
	vector<vector<deque<int>>> previousRounds;

	while (p1Cards.size() > 0 && p2Cards.size() > 0)
	{
		bool p1AutoWin = false;
		for (int i = 0, len = previousRounds.size(); i < len; i++)
		{
			if (previousRounds[i][0] == p1Cards && previousRounds[i][1] == p2Cards)
			{
				p1AutoWin = true;
				break;
			}
		}

		if (!p1AutoWin)
		{
			vector<deque<int>> round;
			round.push_back(p1Cards);
			round.push_back(p2Cards);
			previousRounds.push_back(round);
		}

		int p1 = p1Cards.front();
		p1Cards.pop_front();

		int p2 = p2Cards.front();
		p2Cards.pop_front();

		bool winnerIsP1 = p1AutoWin || p1 > p2;
		if (!p1AutoWin && p1Cards.size() >= p1 && p2Cards.size() >= p2)
		{
			deque<int> p1SubCards, p2SubCards;
			for (int i = 0; i < p1; i++)
			{
				p1SubCards.push_back(p1Cards[i]);
			}
			for (int i = 0; i < p2; i++)
			{
				p2SubCards.push_back(p2Cards[i]);
			}
			PlayRecursiveGames(p1SubCards, p2SubCards);

			winnerIsP1 = p1SubCards.size() > 0;
		}
		
		if (winnerIsP1)
		{
			p1Cards.push_back(p1);
			p1Cards.push_back(p2);
		}
		else
		{
			p2Cards.push_back(p2);
			p2Cards.push_back(p1);
		}
	}
}

const unsigned long long DayTwentyTwoTask::GetWinnerScore(deque<int>& winningHand)
{
	unsigned long long count = 0;

	for (int i = 0, len = winningHand.size(); i < len; i++)
	{
		unsigned long long value = winningHand.front();
		winningHand.pop_front();
		value *= (unsigned long long)((int)len - i);
		count += value;
	}

	return count;
}

const void DayTwentyTwoTask::PlayToCompletion(deque<int>& p1Cards, deque<int>& p2Cards)
{
	while (p1Cards.size() > 0 && p2Cards.size() > 0)
	{
		int p1 = p1Cards.front();
		p1Cards.pop_front();

		int p2 = p2Cards.front();
		p2Cards.pop_front();

		if (p1 > p2)
		{
			p1Cards.push_back(p1);
			p1Cards.push_back(p2);
		}
		else if (p1 < p2)
		{
			p2Cards.push_back(p2);
			p2Cards.push_back(p1);
		}
	}
}
