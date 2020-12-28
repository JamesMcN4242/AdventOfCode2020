#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class DayTwentyFiveTask
{
public:
	static const unsigned long long GetFinalCode(vector<int> input);
private:
	static const unsigned long long GetLoopSize(unsigned long long publicKey, unsigned long long subjectNumber);
	static const unsigned long long GetEncryptionKey(unsigned long long publicKey, unsigned long long loopCount);
};