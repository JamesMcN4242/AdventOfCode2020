#include "InputGrabber/InputGrabber.h"
#include "DayOne/DayOne.h"
#include "DayTwo/DayTwo.h"
#include "DayThree/DayThree.h"
#include "DayFour/DayFour.h"
#include "DayFive/DayFive.h"
#include "DaySix/DaySix.h"
#include "DaySeven/DaySeven.h"
#include "DayEight/DayEight.h"
#include "DayNine/DayNine.h"
#include "DayTen/DayTen.h"
#include "DayEleven/DayEleven.h"
#include "DayTwelve/DayTwelve.h"
#include "DayThirteen/DayThirteen.h"
#include "Day14/DayFourteen.h"
#include "Day15/DayFifteen.h"
#include "Day16/DaySixteen.h"
#include "Day17/DaySeventeen.h"
#include "Day18/DayEighteen.h"
#include "Day19/DayNineteen.h"
#include "Day20/DayTwenty.h"
#include "Day21/DayTwentyOne.h"
#include "Day22/DayTwentyTwo.h"
#include "Day23/DayTwentyThree.h"
#include "Day24/DayTwentyFour.h"
#include "Day25/DayTwentyFive.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void RunAllDays();
void RunAppropriateDay(int dayToRun);
void RunDayOne();
void RunDayTwo();
void RunDayThree();
void RunDayFour();
void RunDayFive();
void RunDaySix();
void RunDaySeven();
void RunDayEight();
void RunDayNine();
void RunDayTen();
void RunDayEleven();
void RunDayTwelve();
void RunDayThirteen();
void RunDayFourteen();
void RunDayFifteen();
void RunDaySixteen();
void RunDaySeventeen();
void RunDayEighteen();
void RunDayNineteen();
void RunDayTwenty();
void RunDayTwentyOne();
void RunDayTwentyTwo();
void RunDayTwentyThree();
void RunDayTwentyFour();
void RunDayTwentyFive();

void main()
{
	cout << "Here you can run all of the puzzles for Advent of Code 2020! (Times vary significantly)" << endl << endl;
	
	while (true)
	{
		cout << "Please insert a number for the day to run, 'a' for all, or 'x' to exit the programme." << endl;
		string input;
		cin >> input;
		cout << endl;

		switch (input[0])
		{
		case 'a':
		case 'A':
			RunAllDays();
			break;

		case 'x':
		case 'X':
			return;

		default:
			try
			{
				int dayToRun = stoi(input);
				RunAppropriateDay(dayToRun);
			}
			catch (const std::exception&)
			{
				cout << "Sorry. That doesn't seem to be an expected value!" << endl<< endl;
			}
			break;
		}
	}
}

void RunAllDays()
{
	for (int i = 1; i <= 25; i++)
	{
		RunAppropriateDay(i);
	}
}

void RunAppropriateDay(int dayToRun)
{
	cout << "Day " << dayToRun << ": " << endl;

	switch (dayToRun)
	{
	case 1:	RunDayOne();				 break;
	case 2:	RunDayTwo();				 break;
	case 3:	RunDayThree();				 break;
	case 4:	RunDayFour();				 break;
	case 5:	RunDayFive();				 break;
	case 6:	RunDaySix();				 break;
	case 7:	RunDaySeven();				 break;
	case 8:	RunDayEight();				 break;
	case 9:	RunDayNine();				 break;
	case 10: RunDayTen();				 break;
	case 11: RunDayEleven();			 break;
	case 12: RunDayTwelve();			 break;
	case 13: RunDayThirteen();			 break;
	case 14: RunDayFourteen();			 break;
	case 15: RunDayFifteen();			 break;
	case 16: RunDaySixteen();			 break;
	case 17: RunDaySeventeen();			 break;
	case 18: RunDayEighteen();			 break;
	case 19: RunDayNineteen();			 break;
	case 20: RunDayTwenty();			 break;
	case 21: RunDayTwentyOne();			 break;
	case 22: RunDayTwentyTwo();			 break;
	case 23: RunDayTwentyThree();		 break;
	case 24: RunDayTwentyFour();		 break;
	case 25: RunDayTwentyFive();		 break;

	default:
		cout << "Sorry. That doesn't seem to be an expected day!" << endl << endl;
		break;
	}
}

void RunDayOne()
{
	string input = InputGrabber::GetTextInput("Resources/DayOneInput.txt");

	int outputCodeOne = DayOneTask::GetPartOneCode(input, 2020);
	int outputCodeTwo = DayOneTask::GetPartTwoCode(input, 2020);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwo()
{
	string input = InputGrabber::GetTextInput("Resources/DayTwoInput.txt");

	int outputCodeOne = DayTwoTask::GetPartOneCode(input);
	int outputCodeTwo = DayTwoTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayThree()
{
	string input = InputGrabber::GetTextInput("Resources/DayThreeInput.txt");

	int outputCodeOne = DayThreeTask::GetPartOneCode(input);
	unsigned long outputCodeTwo = DayThreeTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayFour()
{
	string input = InputGrabber::GetTextInput("Resources/DayFourInput.txt");

	int outputCodeOne = DayFourTask::GetPartOneCode(input);
	int outputCodeTwo = DayFourTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayFive()
{
	string input = InputGrabber::GetTextInput("Resources/DayFiveInput.txt");

	int outputCodeOne = DayFiveTask::GetPartOneCode(input);
	int outputCodeTwo = DayFiveTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDaySix()
{
	string input = InputGrabber::GetTextInput("Resources/DaySixInput.txt");

	int outputCodeOne = DaySixTask::GetPartOneCode(input);
	int outputCodeTwo = DaySixTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDaySeven()
{
	cout << "Wait times may be significant on this puzzle unless optimised" << endl << endl;
	string input = InputGrabber::GetTextInput("Resources/DaySevenInput.txt");

	int outputCodeOne = DaySevenTask::GetPartOneCode(input);
	int outputCodeTwo = DaySevenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayEight()
{
	string input = InputGrabber::GetTextInput("Resources/DayEightInput.txt");

	int outputCodeOne = DayEightTask::GetPartOneCode(input);
	int outputCodeTwo = DayEightTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayNine()
{
	string input = InputGrabber::GetTextInput("Resources/DayNineInput.txt");

	unsigned long long outputCodeOne = DayNineTask::GetPartOneCode(input);
	unsigned long long outputCodeTwo = DayNineTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTen()
{
	string input = InputGrabber::GetTextInput("Resources/DayTenInput.txt");

	int outputCodeOne = DayTenTask::GetPartOneCode(input);
	unsigned long long outputCodeTwo = DayTenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayEleven()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/DayElevenInput.txt");

	int outputCodeOne = DayElevenTask::GetPartOneCode(input);
	int outputCodeTwo = DayElevenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwelve()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/DayTwelveInput.txt");

	int outputCodeOne = DayTwelveTask::GetPartOneCode(input);
	int outputCodeTwo = DayTwelveTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayThirteen()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/DayThirteenInput.txt");

	int outputCodeOne = DayThirteenTask::GetPartOneCode(input);
	unsigned long long outputCodeTwo = DayThirteenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayFourteen()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/Day14Input.txt");

	unsigned long long outputCodeOne = DayFourteenTask::GetPartOneCode(input);
	unsigned long long outputCodeTwo = DayFourteenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayFifteen()
{
	cout << "Wait times may be significant on this puzzle unless optimised" << endl << endl;
	const vector<int> input = InputGrabber::GetCommaSeperatedIntLine("Resources/Day15Input.txt");

	const int outputCodeOne = DayFifteenTask::GetPartOneCode(input);
	const unsigned long outputCodeTwo = DayFifteenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDaySixteen()
{
	const vector<string> input = InputGrabber::GetStringsSeperatedByBlankLine("Resources/Day16Input.txt");

	const int outputCodeOne = DaySixteenTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DaySixteenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDaySeventeen()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/Day17Input.txt");

	const int outputCodeOne = DaySeventeenTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DaySeventeenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayEighteen()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/Day18Input.txt");

	const unsigned long long outputCodeOne = DayEighteenTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayEighteenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayNineteen()
{
	cout << "Wait times may be significant on this puzzle unless optimised" << endl << endl;
	const vector<string> input = InputGrabber::GetStringsSeperatedByBlankLine("Resources/Day19Input.txt");

	const unsigned long long outputCodeOne = DayNineteenTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayNineteenTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwenty()
{
	const vector<string> input = InputGrabber::GetStringsSeperatedByBlankLine("Resources/Day20Input.txt");

	const unsigned long long outputCodeOne = DayTwentyTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayTwentyTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwentyOne()
{
	const vector<string> input = InputGrabber::GetEachStringLine("Resources/Day21Input.txt");

	const unsigned long long outputCodeOne = DayTwentyOneTask::GetPartOneCode(input);
	const string outputCodeTwo = DayTwentyOneTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwentyTwo()
{
	cout << "Wait times may be significant on this puzzle unless optimised" << endl << endl;
	const vector<string> input = InputGrabber::GetStringsSeperatedByBlankLine("Resources/Day22Input.txt");

	const unsigned long long outputCodeOne = DayTwentyTwoTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayTwentyTwoTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwentyThree()
{
	cout << "Wait times may be significant on this puzzle unless optimised" << endl << endl;
	string input = InputGrabber::GetTextInput("Resources/Day23Input.txt");

	const string outputCodeOne = DayTwentyThreeTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayTwentyThreeTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwentyFour()
{
	vector<string> input = InputGrabber::GetEachStringLine("Resources/Day24Input.txt");

	const unsigned long long outputCodeOne = DayTwentyFourTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayTwentyFourTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwentyFive()
{
	vector<int> input = InputGrabber::GetEachIntLine("Resources/Day25Input.txt");

	const unsigned long long outputCode = DayTwentyFiveTask::GetFinalCode(input);

	cout << "Day 25's output (final code!): " << outputCode << endl << endl;
}