#include "InputGrabber.h"
#include <fstream>

using std::ifstream;
using std::getline;

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