#include <fstream>
#include "Company.h"
#include "Contestant.h"
#include "Judge.h"


/* ------------------------------------ CONTESTANT -----------------------------------*/
bool Company::addContestant(Contestant * contestant) {
	for (auto it = contestants.begin(); it < contestants.end(); it++)
	{
		if (*(*it) == *contestant) return false;
		if (!(*(*it) < *contestant)) {
			contestants.insert(it, contestant);
			return true;
		}
	}
	contestants.push_back(contestant);
	return true;
}
bool Company::readContestantsFile(string fileName) {
	ifstream contestantsFile(fileName + ".dat");

	string textLine;

	//in case of failure during the opening
	if (contestantsFile.fail())
	{
		return false;
	}

	while (!contestantsFile.eof()) /* adds elements to the driver std::vector until the whole file is read */
	{
		getline(contestantsFile, textLine);
		Contestant * contestant = new Contestant(textLine);
		addContestant(contestant);
	}

	contestantsFile.close();
	return true;
}
void Company::writeContestantsFile(string fileName) {
	ofstream contestantsFile(fileName + ".dat");
	unsigned int i = 0;
	for (; i < contestants.size() - 1; i++) {
		contestantsFile << contestants[i] << "\n";
	}
	contestantsFile << contestants[i];

	contestantsFile.close();
}

/* --------------------------------------- JUDGE --------------------------------------*/
bool Company::addJudge(Judge * judge) {
	for (auto it = judges.begin(); it < judges.end(); it++)
	{
		if (*(*it) == *judge) return false;
		if (!(*(*it) < *judge)) {
			judges.insert(it, judge);
			return true;
		}
	}
	judges.push_back(judge);
	return true;

}
bool Company::readJudgesFile(string fileName) {
	ifstream judgesFile(fileName + ".dat");

	string textLine;

	//in case of failure during the opening
	if (judgesFile.fail())
	{
		return false;
	}

	while (!judgesFile.eof()) /* adds elements to the driver std::vector until the whole file is read */
	{
		getline(judgesFile, textLine);
		Judge * judge = new Judge(textLine);
		addJudge(judge);
	}

	judgesFile.close();
	return true;
}
void Company::writeJudgesFile(string fileName) {
	ofstream judgesFile(fileName + ".dat");
	unsigned int i = 0;
	for (; i < judges.size() - 1; i++) {
		judgesFile << judges[i] << "\n";
	}
	judgesFile << judges[i];

	judgesFile.close();
}
