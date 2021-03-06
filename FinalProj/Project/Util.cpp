#include "Util.h"
#include <cstddef>
#include <limits>

const std::streamsize max = std::numeric_limits<std::streamsize>::max();
void removeSpaces(std::string &string)
{
	if (string.length() > 0) {
		for (size_t i = 0; i < string.length() - 1; i++)
		{
			if (((string.at(i) == ' ') || (string.at(i) == '\t') || (string.at(i) == '\n')) && ((string.at(i+1) == ' ') || (string.at(i+1) == '\t') || (string.at(i+1) == '\n')))
			{
				string.erase(i, 1); //erases the current space if it's followed by another space
				i = i - 1;
			}
		}
	}
	if (string.length() >= 1) {

		if ((string.at(0) == ' ' )|| (string.at(0) == '\t') || (string.at(0) == '\n'))
		{
			string.erase(0, 1);
		}
	}
	if (string.length() >= 1) {

		if (((string.at(string.length() - 1)) == ' ') || ((string.at(string.length() - 1)) == '\n') || ((string.at(string.length() - 1)) == '\t'))
		{
			string.erase(string.length() - 1, 1);
		}
	}
}
