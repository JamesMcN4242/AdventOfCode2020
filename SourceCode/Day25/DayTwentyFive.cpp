#include "DayTwentyFive.h"

const unsigned long long DayTwentyFiveTask::GetFinalCode(vector<int> input)
{
	auto firstLoopSize = GetLoopSize(input[0], 7);
	auto encryptionKey = GetEncryptionKey(input[1], firstLoopSize);

	return encryptionKey;
}

const unsigned long long DayTwentyFiveTask::GetLoopSize(unsigned long long publicKey, unsigned long long subjectNumber)
{
	unsigned long long loopSize = 0;
	unsigned long long value = 1;

	while (value != publicKey)
	{
		loopSize++;
		value *= subjectNumber;
		value %= 20201227;
	}

	return loopSize;
}

const unsigned long long DayTwentyFiveTask::GetEncryptionKey(unsigned long long publicKey, unsigned long long loopCount)
{
	unsigned long long loopSize = 0;
	unsigned long long value = 1;

	for (unsigned long long i = 0; i < loopCount; i++)
	{
		value *= publicKey;
		value %= 20201227;
	}

	return value;
}
