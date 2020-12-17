#pragma once

#include <string>
#include <utility>
#include <vector>

using std::pair;
using std::string;
using std::vector;

// (Almost) Every method below is a "Get". The fact they're calculating and doing a lot of work makes that really bad naming.
// Also just as if I've forgot English and can't remember any other words which is also plausible 
class DaySixteenTask
{
public:
	static const int GetPartOneCode(vector<string> input);
	static const unsigned long long GetPartTwoCode(vector<string> input);
private:
	static const int GetTicketScanErrorRate(vector<vector<int>>& nearbyTickets, vector<pair<int, int>>& acceptableRanges);
	static const vector<pair<int, int>> GetAcceptableRanges(string acceptableRange);
	static const vector<int> GetMyTickets(string myTicket);
	static const vector<vector<int>> GetNearbyTickets(string nearbyTickets);
	static const vector<vector<int>> GetOnlyValidTickets(vector<vector<int>>& tickets, vector<pair<int, int>>& acceptableRanges);
	static const vector<int> GetViableTicketPositions(vector<vector<int>>& tickets, vector<pair<int, int>>& acceptableRanges);
	static const unsigned long long GetDepartureCode(vector<int>& ticket, string acceptableRanges, vector<int>& viableTicketPositions);
	static const void RemoveValueFromEveryVector(vector<vector<int>>& toRemoveFrom, int valueToRemove);
};