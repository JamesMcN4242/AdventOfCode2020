#pragma once

#include <string>
#include <valarray>

using std::string;
using std::valarray;

struct PasswordVerifier
{
public:
	PasswordVerifier() :PasswordVerifier(0, 0, ' ', "") {}

	PasswordVerifier(int minimum, int maximum, char entry, string password)
		: m_minimum(minimum), m_maximum(maximum), m_entryToCount(entry), m_password(password) {}

	bool IsSledPassValid()
	{
		int count = 0;
		for (int i = 0, len = m_password.length(); i < len; i++)
		{
			if (m_password[i] == m_entryToCount)
			{
				count++;
			}
		}

		return count >= m_minimum && count <= m_maximum;
	}

	bool IsTobogganPassValid()
	{
		return (m_password[m_minimum - 1] == m_entryToCount) ^ (m_password[m_maximum - 1] == m_entryToCount);
	}

private:
	int m_minimum;
	int m_maximum;
	char m_entryToCount;
	string m_password;
};

class DayTwoTask
{
public:
	static const int GetPartOneCode(const string inputToBeBroken);
	static const int GetPartTwoCode(const string inputToBeBroken);
private:
	static const int GetLineCount(const string inputToBreak, const int inputLen);
	static string GetSubstringFromIndexToChar(const string input, int indexToStart, char toStopBefore, int fullInputLength);
	static valarray<PasswordVerifier> GetValueArray(const string inputToBreak, const int lineCount, const int inputLen);
};