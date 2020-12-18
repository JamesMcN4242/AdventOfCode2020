#include "DaySeventeen.h"

const int DaySeventeenTask::GetPartOneCode(vector<string> input)
{
	deque < deque<string>> cubes = ConvertInputToMapSystem(input);
	for (int i = 0; i < 6; i++)
	{
		RunCycle(cubes);
	}

	return CountActiveCubes(cubes);
}

const unsigned long long DaySeventeenTask::GetPartTwoCode(vector<string> input)
{
	deque <deque<string>> partOneCubes = ConvertInputToMapSystem(input);
	deque<deque<deque<string>>> cubes;
	cubes.push_back(partOneCubes);
	for (int i = 0; i < 6; i++)
	{
		Run4DCycle(cubes);
	}

	unsigned long long result = 0;
	for (int i = 0, len = cubes.size(); i < len; i++)
	{
		unsigned long long count = CountActiveCubes(cubes[i]);
		result += count;
	}

	return result;
}

const int DaySeventeenTask::CountActiveCubes(deque<deque<string>>& cubes)
{
	int count = 0;

	for (int i = 0, outsideLen = cubes.size(); i < outsideLen; i++)
	{
		deque<string> twoDMap= cubes[i];
		for (int j = 0, twoDLen = twoDMap.size(); j < twoDLen; j++)
		{
			string inside = twoDMap[j];
			for (int k = 0, insideLen = inside.size(); k < insideLen; k++)
			{
				if (inside[k] == '#')
				{
					count++;
				}
			}
		}
	}

	return count;
}

const void DaySeventeenTask::RunCycle(deque<deque<string>>& cubes)
{
	int yPlanes = cubes[0].size();
	int xPlanes = cubes[0][0].size();
	AddExternal3DLayers(cubes, yPlanes, xPlanes);

	yPlanes += 2;
	xPlanes += 2;
	const int zPlanes = cubes.size();

	deque<deque<string>> originalState = cubes;
	for (int i = 0; i < zPlanes; i++)
	{
		for (int j = 0; j < yPlanes; j++)
		{
			for (int k = 0; k < xPlanes; k++)
			{
				int activeSurrounding = CountSurroundingActiveCubes(originalState, i, j, k, zPlanes, yPlanes, xPlanes);
				if (cubes[i][j][k] == '#' && !(activeSurrounding == 2 || activeSurrounding == 3))
				{
					cubes[i][j][k] = '.';
				}
				else if (cubes[i][j][k] == '.' && activeSurrounding == 3)
				{
					cubes[i][j][k] = '#';
				}
			}
		}
	}
}

const void DaySeventeenTask::Run4DCycle(deque<deque<deque<string>>>& cubes)
{
	int yPlanes = cubes[0][0].size();
	int xPlanes = cubes[0][0][0].size();
	AddExternal4DLayers(cubes, yPlanes, xPlanes);

	yPlanes += 2;
	xPlanes += 2;
	const int zPlanes = cubes[0].size();
	const int wPlanes = cubes.size();

	deque<deque<deque<string>>> originalState = cubes;

	for (int h = 0; h < wPlanes; h++)
	{
		for (int i = 0; i < zPlanes; i++)
		{
			for (int j = 0; j < yPlanes; j++)
			{
				for (int k = 0; k < xPlanes; k++)
				{
					int activeSurrounding = CountSurroundingActiveCubes(originalState, h, i, j, k, wPlanes, zPlanes, yPlanes, xPlanes);
					if (cubes[h][i][j][k] == '#' && !(activeSurrounding == 2 || activeSurrounding == 3))
					{
						cubes[h][i][j][k] = '.';
					}
					else if (cubes[h][i][j][k] == '.' && activeSurrounding == 3)
					{
						cubes[h][i][j][k] = '#';
					}
				}
			}
		}
	}
}

const void DaySeventeenTask::AddExternal3DLayers(deque<deque<string>>& cubes, const int contentSize, const int contentLength)
{
	deque<string> contentToAdd;
	string toAdd;
	for (int i = 0; i < contentLength + 2; i++)
	{
		toAdd += ".";
	}

	for (int i = 0; i < contentSize + 2; i++)
	{
		contentToAdd.push_back(toAdd);
	}

	for (int i = 0, len = cubes.size(); i < len; i++)
	{
		for (int j = 0; j < contentSize; j++)
		{
			cubes[i][j] = '.' + cubes[i][j] + '.';
		}

		cubes[i].push_front(toAdd);
		cubes[i].push_back(toAdd);
	}

	cubes.push_front(contentToAdd);
	cubes.push_back(contentToAdd);
}

const void DaySeventeenTask::AddExternal4DLayers(deque<deque<deque<string>>>& cubes, const int contentSize, const int contentLength)
{
	for (int i = 0, len = cubes.size(); i < len; i++)
	{
		AddExternal3DLayers(cubes[i], contentSize, contentLength);
	}

	deque<deque<string>> toAdd = cubes[0];
	for (int i = 0, len = toAdd.size(); i < len; i++)
	{
		for (int j = 0; j < contentSize + 2; j++)
		{
			for (int k = 0; k < contentLength + 2; k++)
			{
				toAdd[i][j][k] = '.';
			}
		}
	}

	cubes.push_front(toAdd);
	cubes.push_back(toAdd);
}

const deque<deque<string>> DaySeventeenTask::ConvertInputToMapSystem(vector<string>& input)
{
	deque<string> entries;
	for (int i = 0, len = input.size(); i < len; i++)
	{
		entries.push_back(input[i]);
	}

	deque<deque<string>> returnVal;
	returnVal.push_back(entries);
	return returnVal;
}

const int DaySeventeenTask::CountSurroundingActiveCubes(deque<deque<string>>& cubes, const int zPos, const int yPos, const int xPos, const int zSize, const int ySize, const int xSize)
{
	int count = 0;
	for (int i = zPos - 1; i < zPos + 2; i++)
	{
		if (i < 0 || i >= zSize) continue;
		for (int j = yPos - 1; j < yPos + 2; j++)
		{
			if (j < 0 || j >= ySize) continue;
			for (int k = xPos - 1; k < xPos + 2; k++)
			{
				if (k < 0 || k >= xSize || (i == zPos && j == yPos && k == xPos)) continue;
				if (cubes[i][j][k] == '#')
				{
					count++;
				}
			}
		}
	}
	return count;
}

const int DaySeventeenTask::CountSurroundingActiveCubes(deque<deque<deque<string>>>& cubes, const int wPos, const int zPos, const int yPos, const int xPos, const int wSize, const int zSize, const int ySize, const int xSize)
{
	int count = 0;

	for (int h = wPos - 1; h < wPos + 2; h++)
	{
		if (h < 0 || h >= wSize) continue;
		for (int i = zPos - 1; i < zPos + 2; i++)
		{
			if (i < 0 || i >= zSize) continue;
			for (int j = yPos - 1; j < yPos + 2; j++)
			{
				if (j < 0 || j >= ySize) continue;
				for (int k = xPos - 1; k < xPos + 2; k++)
				{
					if (k < 0 || k >= xSize || (i == zPos && j == yPos && k == xPos && h == wPos)) continue;
					if (cubes[h][i][j][k] == '#')
					{
						count++;
					}
				}
			}
		}
	}
	return count;
}
