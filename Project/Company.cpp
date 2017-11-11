#include <fstream>
#include <algorithm>
#include "Company.h"
#include "Contestant.h"
#include "Judge.h"
#include "ExceptionHand.h"

/* ------------------------------------ CONTESTANT -----------------------------------*/
bool Company::addContestant(Contestant * contestant) {
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
	if (*contestants[i] == *contestant)
		throw RepeatedContestant(contestant->getId()); 
	}

	contestants.push_back(contestant);
	sort(contestants.begin(), contestants.end(), comparePointedValues<Contestant>);

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
	for (unsigned int i = 0; i < judges.size(); i++)
	{
		if (*judges[i] == *judge)
			throw RepeatedJudge(judge->getId());
	}

	judges.push_back(judge);
	sort(judges.begin(), judges.end(), comparePointedValues<Judge>);

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
