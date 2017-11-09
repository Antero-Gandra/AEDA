#include "Util.h"

void stringPrep(std::string &string)
{
	for (size_t i = 0; i < string.length() - 1; i++)
	{
		if ((string.at(i) == ' ') && (string.at(i + 1) == ' '))
		{
			string.erase(i, 1); //erases the current space if it's followed by another space
			i = i - 1;
		}
	}

	if (string.at(0) == ' ')
	{
		string.erase(0, 1);
	}

	if ((string.at(string.length() - 1)) == ' ')
	{
		string.erase(string.length() - 1, 1);
	}

}