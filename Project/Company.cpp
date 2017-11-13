#include <fstream>
#include <iostream>
#include <algorithm>
#include "Company.h"
#include "Contestant.h"
#include "Judge.h"
#include "ExceptionHand.h"


unsigned int Company::lastContestantId = 0;
unsigned int Company::lastJudgeId = 0;

// getMethods
vector<Contestant*> Company::getContestants() const {
	return contestants;
}
vector<Judge*> Company::getJudges() const {
	return judges;
}

/* ------------------------------------ CONTESTANT -----------------------------------*/
void Company::addContestant(Contestant * contestant) {
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		if (*contestants[i] == *contestant)
			return;
	}
	lastContestantId++;
	contestant->setId(lastContestantId);
	contestants.push_back(contestant);
	sort(contestants.begin(), contestants.end(), comparePointedValues<Contestant>);
}
void Company::removeContestant(Contestant * contestant) {
	for (auto it = contestants.begin(); it < contestants.end(); it++)
	{
		if ((*it)->getId() == contestant->getId())
			contestants.erase(it);
	}
}
bool Company::readContestantsFile(string fileName) {
	ifstream contestantsFile(fileName + ".dat");

	string textLine;

	//in case of failure during the opening
	if (contestantsFile.fail())
	{
		return false;
	}

	while (!contestantsFile.eof()) /* adds elements to the Contestant* std::vector until the whole file is read */
	{
		getline(contestantsFile, textLine);
		Contestant * contestant = new Contestant(textLine);
		addContestant(contestant);
	}

	contestantsFile.close();
	return true;
}
bool Company::writeContestantsFile(string fileName) {
	ofstream contestantsFile(fileName + ".dat");
	unsigned int i = 0;
	for (; i < contestants.size() - 1; i++) {
		contestantsFile << (*contestants[i]) << "\n";
	}
	contestantsFile << *contestants[i];

	contestantsFile.close();

	return true;
}
void Company::showContestants() {
	unsigned int i = 0;
	for (; i < contestants.size() - 1; i++) {
		contestants[i]->show();
		cout << endl;
	}
	contestants[i]->show();
}

/* --------------------------------------- JUDGE --------------------------------------*/
void Company::addJudge(Judge * judge) {
	for (unsigned int i = 0; i < judges.size(); i++)
	{
		if (*judges[i] == *judge)
			return;
	}
	lastJudgeId++;
	judge->setId(lastJudgeId);
	judges.push_back(judge);
	sort(judges.begin(), judges.end(), comparePointedValues<Judge>);
}
void Company::removeJudge(Judge * judge) {
	for (auto it = judges.begin(); it < judges.end(); it++)
	{
		if ((*it)->getId() == judge->getId())
			judges.erase(it);
	}
	throw JudgeIdNotFound(judge->getId());
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
bool Company::writeJudgesFile(string fileName) {
	ofstream judgesFile(fileName + ".dat");
	unsigned int i = 0;
	for (; i < judges.size() - 1; i++) {
		judgesFile << judges[i] << "\n";
	}
	judgesFile << judges[i];

	judgesFile.close();
	return true;
}
