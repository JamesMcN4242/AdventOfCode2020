#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

static class InputGrabber
{
public:
	static const string GetTextInput(string fileAddress);
	static const vector<string> GetEachStringLine(string fileAddress);
	static const vector<int> GetEachIntLine(string fileAddress);
	static const vector<int> GetCommaSeperatedIntLine(string fileAddress);	
};