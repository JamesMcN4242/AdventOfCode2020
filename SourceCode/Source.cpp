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
#include <iostream>

using std::cout;
using std::endl;

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

void main()
{
	RunDayTwentyFour();
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
	const vector<string> input = InputGrabber::GetStringsSeperatedByBlankLine("Resources/Day22Input.txt");

	const unsigned long long outputCodeOne = DayTwentyTwoTask::GetPartOneCode(input);
	const unsigned long long outputCodeTwo = DayTwentyTwoTask::GetPartTwoCode(input);

	cout << "Part One outcome: " << outputCodeOne << endl << endl;
	cout << "Part Two outcome: " << outputCodeTwo << endl << endl;
}

void RunDayTwentyThree()
{
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