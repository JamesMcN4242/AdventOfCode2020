#include "InputGrabber.h"
#include <fstream>

using std::getline;
using std::ifstream;
using std::stoi;

const string InputGrabber::GetTextInput(string fileLocation)
{
	ifstream file(fileLocation);
	std::string str;

	file.seekg(0, std::ios::end);
	str.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());

	return str;
}

const vector<string> InputGrabber::GetEachStringLine(string fileAddress)
{
	string input = GetTextInput(fileAddress);
	vector<string> entries;
	string line = "";

	for (int i = 0, len = input.length(); i < len; i++)
	{
		bool newLine = false;
		if (input[i] != '\n')
		{
			line += input[i];
		}
		else
		{
			newLine = true;
		}

		if ((newLine || i == len - 1) && line != "")
		{
			entries.push_back(line);
			line.clear();
		}
	}

	return entries;
}

const vector<int> InputGrabber::GetEachIntLine(string fileAddress)
{
	string input = GetTextInput(fileAddress);
	vector<int> entries;
	string line = "";

	for (int i = 0, len = input.length(); i < len; i++)
	{
		bool newLine = false;
		if (input[i] != '\n')
		{
			line += input[i];
		}
		else
		{
			newLine = true;
		}

		if ((newLine || i == len - 1) && line != "")
		{
			entries.push_back(stoi(line));
			line.clear();
		}
	}

	return entries;
}
