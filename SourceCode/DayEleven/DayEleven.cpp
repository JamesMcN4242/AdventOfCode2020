#include "DayEleven.h"

const int DayElevenTask::GetPartOneCode(vector<string> input)
{
	const pair<int, int> dimensions(input[0].size(), input.size());
	bool changesMade = true;
	while (changesMade)
	{
		input = RunIterationOfRules(input, changesMade, dimensions, 4, CountAdjacentOccupiedSeats);
	}
	return CountAllOccupiedSeats(input, dimensions);
}

const int DayElevenTask::GetPartTwoCode(vector<string> input)
{
	const pair<int, int> dimensions(input[0].size(), input.size());
	bool changesMade = true;

	while (changesMade)
	{
		input = RunIterationOfRules(input, changesMade, dimensions, 5, CountAdjacentVisibleOccupiedSeats);
	}
	return CountAllOccupiedSeats(input, dimensions);
}

const vector<string> DayElevenTask::RunIterationOfRules(const vector<string>& currentArrangement, bool& changesOccurred, const pair<int, int> areaDimensions,
	const int moveNumber, function<int(const vector<string>&, const pair<int, int>, const pair<int, int>)> countMethod)
{
	changesOccurred = false;
	vector<string> newArrangements = currentArrangement;

	for (int i = 0; i < areaDimensions.second; i++)
	{
		for (int j = 0; j < areaDimensions.first; j++)
		{
			const char currentState = currentArrangement[i][j];
			if (currentState == '.') continue;

			int amountOccupied = countMethod(currentArrangement, areaDimensions, pair<int, int>(j, i));
			if (currentState == 'L' && amountOccupied == 0)
			{
				changesOccurred = true;
				newArrangements[i][j] = '#';
			}
			else if (currentState == '#' && amountOccupied >= moveNumber)
			{
				changesOccurred = true;
				newArrangements[i][j] = 'L';
			}
		}
	}

	return newArrangements;
}

const int DayElevenTask::CountAllOccupiedSeats(const vector<string>& arrangement, const pair<int, int> areaDimensions)
{
	int amountOccupied = 0;

	for (int i = 0; i < areaDimensions.second; i++)
	{
		for (int j = 0; j < areaDimensions.first; j++)
		{
			if (arrangement[i][j] == '#')
			{
				amountOccupied++;
			}
		}
	}

	return amountOccupied;
}

const int DayElevenTask::CountAdjacentOccupiedSeats(const vector<string>& currentArrangement, const pair<int, int> areaDimensions, const pair<int, int> chairPosition)
{
	int amountOccupied = 0;

	for (int height = -1; height < 2; height++)
	{
		for (int length = -1; length < 2; length++)
		{
			if (length == 0 && height == 0) continue;

			int xPos = chairPosition.first + length;
			int yPos = chairPosition.second + height;

			if (xPos < 0 || yPos < 0 || xPos >= areaDimensions.first || yPos >= areaDimensions.second) continue;
			
			if (currentArrangement[yPos][xPos] == '#') amountOccupied++;
		}
	}

	return amountOccupied;
}

const int DayElevenTask::CountAdjacentVisibleOccupiedSeats(const vector<string>& currentArrangement, const pair<int, int> areaDimensions, const pair<int, int> chairPosition)
{
	int amountOccupied = 0;

	for (int yVelocity = -1; yVelocity < 2; yVelocity++)
	{
		for (int xVelocity = -1; xVelocity < 2; xVelocity++)
		{
			if (xVelocity == 0 && yVelocity == 0) continue;

			if (IsFirstSeatInDirectionOccupied(currentArrangement, areaDimensions, chairPosition, pair<int, int>(xVelocity, yVelocity)))
			{
				amountOccupied++;
			}
		}
	}

	return amountOccupied;
}

const bool DayElevenTask::IsFirstSeatInDirectionOccupied(const vector<string>& currentArrangement, const pair<int, int> areaDimensions, const pair<int, int> chairPosition, const pair<int, int> direction)
{
	int xPos = chairPosition.first + direction.first;
	int yPos = chairPosition.second + direction.second;

	while (!(xPos < 0 || yPos < 0 || xPos >= areaDimensions.first || yPos >= areaDimensions.second))
	{
		const char currentState = currentArrangement[yPos][xPos];
		if (currentState != '.')
		{
			return currentState == '#';
		}

		xPos += direction.first;
		yPos += direction.second;
	}

	return false;
}
