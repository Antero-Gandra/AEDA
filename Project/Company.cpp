#include <fstream>
#include <iostream>
#include <algorithm>
#include "Company.h"
#include "Contestant.h"
#include "Judge.h"
#include "ExceptionHand.h"
#include "Audition.h"


unsigned int Company::lastContestantId = 0;
unsigned int Company::lastJudgeId = 0;
unsigned int Company::lastAuditionId = 0;

// getMethods
vector<Contestant*> Company::getContestants() const {
	return contestants;
}
vector<Judge*> Company::getJudges() const {
	return judges;
}

/* ------------------------------------ CONTESTANT -----------------------------------*/
void Company::addContestant(Contestant * contestant) {
	unsigned int repeatedId = 0;
	for (unsigned int i = 0; i < contestants.size(); i++)
	{
		if (*contestants[i] == *contestant)
		{
			repeatedId = contestants[i]->getId();
		}
	}
	if (repeatedId != 0) {
		lastContestantId++;
		contestant->setId(lastContestantId);
		contestants.push_back(contestant);
		sort(contestants.begin(), contestants.end(), comparePointedValues<Contestant>);
		contestantsToEnroll.push_back(contestant);
	}

	contestant->setId(repeatedId);
	contestantsToEnroll.push_back(contestant);
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
bool Company::readContestantsToEnrollFile(string fileName) {
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
bool Company::writeContestantsToEnrollFile(string fileName) {
	ofstream contestantsFile(fileName + ".dat");
	unsigned int i = 0;
	for (; i < contestantsToEnroll.size() - 1; i++) {
		contestantsFile << (*contestantsToEnroll[i]) << "\n";
	}
	contestantsFile << *contestantsToEnroll[i];

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
void Company::showContestantsToEnroll() {
	unsigned int i = 0;
	for (; i < contestantsToEnroll.size() - 1; i++) {
		contestantsToEnroll[i]->show();
		cout << endl;
	}
	contestantsToEnroll[i]->show();
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
		judgesFile << *judges[i] << "\n";
	}
	judgesFile << *judges[i];

	judgesFile.close();
	return true;
}
void Company::showJudges() {
	unsigned int i = 0;
	for (; i < judges.size() - 1; i++) {
		judges[i]->show();
		cout << endl;
	}
	judges[i]->show();
}

/* -------------------------------------- AUDITION ------------------------------------*/

void Company::scheduleAudition(string specialty, vector<unsigned int> cntestnts, vector<unsigned int> jdges) {
	//if (cntestnts.size() <= 6)
		// throw an exception

	//if (jdges.size() < 3)
		// throw an exception

	//if (jdges.size() > 4
	unsigned int dur = cntestnts.size()*(15 + 5) + 5 * 30;
	Time duration = Time(0,0,0,dur / 60, dur % 60);
	lastAuditionId++;
	vector<unsigned int> evs;
	evs.push_back(jdges[0]);
	evs.push_back(jdges[1]);
	unsigned int id = lastAuditionId;
	Time begining = startOfFunctions;
	Time ending = duration + startOfFunctions;
	Audition audition(id,begining,ending, specialty, evs, jdges[2]);
}