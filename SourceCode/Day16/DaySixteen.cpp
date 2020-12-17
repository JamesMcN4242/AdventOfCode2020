#include "DaySixteen.h"
#include "../InputGrabber/InputGrabber.h"

using std::stoi;

const int DaySixteenTask::GetPartOneCode(vector<string> input)
{
	vector<pair<int, int>> acceptableRanges = GetAcceptableRanges(input[0]);
	vector<vector<int>> nearbyTickets = GetNearbyTickets(input[2]);
	return GetTicketScanErrorRate(nearbyTickets, acceptableRanges);
}

const unsigned long long DaySixteenTask::GetPartTwoCode(vector<string> input)
{
	vector<pair<int, int>> acceptableRanges = GetAcceptableRanges(input[0]);
	vector<int> myTicket = GetMyTickets(input[1]);
	vector<vector<int>> nearbyTickets = GetNearbyTickets(input[2]);

	vector<vector<int>> validTickets = GetOnlyValidTickets(nearbyTickets, acceptableRanges);
	validTickets.push_back(myTicket);

	vector<int> viableTicketPositions = GetViableTicketPositions(validTickets, acceptableRanges);
	return GetDepartureCode(myTicket, input[0], viableTicketPositions);
}

const int DaySixteenTask::GetTicketScanErrorRate(vector<vector<int>>& nearbyTickets, vector<pair<int, int>>& acceptableRanges)
{
	const int ticketCount = nearbyTickets.size();
	const int rangeCount = acceptableRanges.size();

	int scanningErrorRate = 0;

	for (int i = 0; i < ticketCount; i++)
	{
		vector<int> ticketValues = nearbyTickets[i];
		for (int j = 0, len = ticketValues.size(); j < len; j++)
		{
			const int ticketVal = ticketValues[j];
			bool valid = false;
			for (int k = 0; k < rangeCount; k++)
			{
				if (acceptableRanges[k].first <= ticketVal && acceptableRanges[k].second >= ticketVal)
				{
					valid = true;
					break;
				}
			}

			if (!valid)
			{
				scanningErrorRate += ticketVal;
			}
		}
	}

	return scanningErrorRate;
}

const vector<pair<int, int>> DaySixteenTask::GetAcceptableRanges(string acceptableRange)
{
	vector<string> lines = InputGrabber::GetEachLine(acceptableRange, '\n');
	vector<pair<int, int>> ranges;

	for (int i = 0, len = lines.size(); i < len; i++)
	{
		string currentLine = lines[i].substr(lines[i].find(':') + 2);

		auto dashPos = currentLine.find('-');
		auto spacePos = currentLine.find(' ');
		int componentOne = stoi(currentLine.substr(0, dashPos));
		int componentTwo = stoi(currentLine.substr(dashPos + 1, spacePos - dashPos));
		ranges.push_back(pair<int,int>(componentOne, componentTwo));

		currentLine = currentLine.substr(spacePos + 4);
		dashPos = currentLine.find('-');
		componentOne = stoi(currentLine.substr(0, dashPos));
		componentTwo = stoi(currentLine.substr(dashPos + 1));
		ranges.push_back(pair<int, int>(componentOne, componentTwo));
	}

	return ranges;
}

const vector<int> DaySixteenTask::GetMyTickets(string myTicket)
{
	myTicket = myTicket.substr(myTicket.find('\n') + 1);
	return InputGrabber::GetEachInt(myTicket, ',');
}

const vector<vector<int>> DaySixteenTask::GetNearbyTickets(string nearbyTickets)
{
	nearbyTickets = nearbyTickets.substr(nearbyTickets.find('\n') + 1);
	vector<string> lines = InputGrabber::GetEachLine(nearbyTickets, '\n');
	vector<vector<int>> ticketValues;

	for (int i = 0, len = lines.size(); i < len; i++)
	{
		vector<int> values = InputGrabber::GetEachInt(lines[i], ',');
		ticketValues.push_back(values);
	}

	return ticketValues;
}

const vector<vector<int>> DaySixteenTask::GetOnlyValidTickets(vector<vector<int>>& tickets, vector<pair<int, int>>& acceptableRanges)
{
	const int ticketCount = tickets.size();
	const int rangeCount = acceptableRanges.size();

	vector<vector<int>> validTickets;

	for (int i = 0; i < ticketCount; i++)
	{
		bool valid = false;
		vector<int> ticketValues = tickets[i];
		for (int j = 0, len = ticketValues.size(); j < len; j++)
		{
			valid = false;
			const int ticketVal = ticketValues[j];
			for (int k = 0; k < rangeCount; k++)
			{
				if (acceptableRanges[k].first <= ticketVal && acceptableRanges[k].second >= ticketVal)
				{
					valid = true;
					break;
				}
			}

			if (!valid)
			{
				break;
			}
		}

		if (valid)
		{
			validTickets.push_back(ticketValues);
		}
	}

	return validTickets;
}

const vector<int> DaySixteenTask::GetViableTicketPositions(vector<vector<int>>& tickets, vector<pair<int, int>>& acceptableRanges)
{
	vector<int> ticketValPositions;
	const int ticketCount = tickets.size();
	const int ticketColumnCount = tickets[0].size();
	const int rangeSize = acceptableRanges.size();

	//My mind is hitting the point of emptyiness, so for anyone that reads this I can only apologise in advance.
	vector<vector<int>> allHitColumns;

	for (int i = 0; i < rangeSize; i += 2)
	{
		vector<int> acceptableColumns;
		pair<int, int> rangeOne = acceptableRanges[i];
		pair<int, int> rangeTwo = acceptableRanges[i + 1];

		for (int j = 0; j < ticketColumnCount; j++)
		{
			bool allValid = true;
			for (int k = 0; k < ticketCount; k++)
			{
				const int ticketVal = tickets[k][j];
				if (!((ticketVal >= rangeOne.first && ticketVal <= rangeOne.second)
					|| (ticketVal >= rangeTwo.first && ticketVal <= rangeTwo.second)))
				{
					allValid = false;
					break;
				}
			}

			if (allValid)
			{
				acceptableColumns.push_back(j);
			}
		}

		allHitColumns.push_back(acceptableColumns);
		ticketValPositions.push_back(-1);
	}

	bool changeOccurred = true;
	while (changeOccurred)
	{
		changeOccurred = false;
		for (int i = 0; i < ticketColumnCount; i++)
		{
			if (ticketValPositions[i] == -1 && allHitColumns[i].size() == 1)
			{
				changeOccurred = true;
				ticketValPositions[i] = allHitColumns[i][0];
				RemoveValueFromEveryVector(allHitColumns, ticketValPositions[i]);
			}
		}
	}

	return ticketValPositions;
}

const unsigned long long DaySixteenTask::GetDepartureCode(vector<int>& ticket, string acceptableRanges, vector<int>& viableTicketPositions)
{
	vector<string> rangeStrs = InputGrabber::GetEachLine(acceptableRanges, '\n');
	const int vectorSize = rangeStrs.size();

	unsigned long long answer = 1;
	const int maxDepartureCount = 6;
	int departuresHit = 0;
	for (int i = 0; i < vectorSize; i++)
	{
		//Why this check? Because our test data only has one other 'd' starter in the ranges which is duration
		//Plus I've left this late in the day so it's 11pm and I need to finish this quickly
		if (rangeStrs[i][0] == 'd' && rangeStrs[i][1] == 'e')
		{
			departuresHit++;
			unsigned long long ticketValue = ticket[viableTicketPositions[i]];
			answer *= ticketValue;
		}
	}

	return answer;
}

const void DaySixteenTask::RemoveValueFromEveryVector(vector<vector<int>>& toRemoveFrom, int valueToRemove)
{
	const int outsideSize = toRemoveFrom.size();

	for (int i = 0; i < outsideSize; i++)
	{
		for (int j = 0, insideSize = toRemoveFrom[i].size(); j < insideSize; j++)
		{
			if (toRemoveFrom[i][j] == valueToRemove)
			{
				toRemoveFrom[i].erase(toRemoveFrom[i].begin() + j);
				break;
			}
		}
	}
}
