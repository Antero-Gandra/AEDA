#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Company.h"
#include "Contestant.h"
#include "Judge.h"
#include "ExceptionHand.h"
#include "Audition.h"
#include "Util.h"


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
vector<Application*> Company::getApplications() const {
	return applications;
}

/* ------------------------------------ CONTESTANT -----------------------------------*/
Contestant * Company::getContestantById(unsigned int id) {
	for (size_t i = 0; i < contestants.size(); i++) {
		if (contestants[i]->getId() == id)
			return contestants[i];
	}
	throw ContestantIdNotFound(id);
}
unsigned int Company::getContestantByInfo(Contestant * contestant) {
	for (size_t i = 0; i < contestants.size(); i++) {
		if (*contestants[i] == *contestant)
			return contestants[i]->getId();
	}
	throw ContestantInfoNotFound();
}
vector<Contestant*> Company::getContestantsOfSpecialty(string specialty) {
	vector<Contestant*> contestantsOfSpecialty;
	for (size_t i = 0; i< contestants.size(); i++)
	{
		if (contestants[i]->getSpecialty() == specialty)
			contestantsOfSpecialty.push_back(contestants[i]);
	}
	return contestantsOfSpecialty;
}
vector<Application*> Company::getApplicationsOfSpecialty(string specialty) {
	vector<Application*> applicationsOfSpecialty;

	for (size_t i = 0; i< applications.size(); i++)
	{
		Contestant * contestant = getContestantById(applications[i]->contestantId);
		if (contestant->getSpecialty() == specialty)
			applicationsOfSpecialty.push_back(applications[i]);
	}
	return applicationsOfSpecialty;
}
void Company::addContestant(Contestant * contestant) {
	lastContestantId++;
	contestant->setId(lastContestantId);
	contestants.push_back(contestant);
	sort(contestants.begin(), contestants.end(), comparePointedValues<Contestant>);
}
void Company::addApplication(Time ctime, unsigned int id) {
	Application * application = new Application(ctime, id);
	applications.push_back(application);
}
void Company::updateContestant(Contestant * contestant, Contestant * modContestant) {
	contestant->setName(modContestant->getName());
	contestant->setDob(modContestant->getDob());
	contestant->setMobile(modContestant->getMobile());
	contestant->setAddress(modContestant->getAddress());
	contestant->setSpecialty(modContestant->getSpecialty());
}
void Company::removeContestant(Contestant * contestant) {
	for (auto it = contestants.begin(); it < contestants.end(); it++)
	{
		if ((*it)->getId() == contestant->getId())
		{
			contestants.erase(it);
			return;
		}
	}
}
vector<Application*> Company::getApplicationsById(unsigned int id) {
	vector<Application*> contestantApp;
	for (auto it = applications.begin(); it < applications.end(); it++) {
		if ((*it)->contestantId == id)
			contestantApp.push_back(*it);
	}
	return contestantApp;
}
void Company::removeOneApplicationOfContestant(Contestant* contestant) {
	for (auto it = applications.begin(); it < applications.end(); it++)
	{
		if ((*it)->contestantId == contestant->getId())
		{
			applications.erase(it);
			return;
		}
	}
}
void Company::removeApplicationsOfContestant(Contestant * contestant) {
	vector<vector<Application*>::const_iterator> elementsToErase;
	for (auto it = applications.begin(); it < applications.end(); it++)
	{
		if ((*it)->contestantId == contestant->getId())
		{
			elementsToErase.push_back(it);
		}
	}
	for (size_t i = 0; i < elementsToErase.size(); i++) {
		applications.erase(elementsToErase[i]);
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
bool Company::readApplicationsFile(string fileName) {
	ifstream applicationsFile(fileName + ".dat");

	string textLine;
	Time date;
	unsigned int year, month, day, hour, minute;
	unsigned int id;

	//in case of failure during the opening
	if (applicationsFile.fail())
	{
		return false;
	}

	while (!applicationsFile.eof()) /* adds elements to the Contestant* std::vector until the whole file is read */
	{
		getline(applicationsFile, textLine);
		istringstream applicationLine(textLine);
		//get date
		applicationLine >> year;
		applicationLine.ignore(std::numeric_limits<std::streamsize>::max(), '/');
		applicationLine >> month;
		applicationLine.ignore(std::numeric_limits<std::streamsize>::max(), '/');
		applicationLine >> day;
		applicationLine.ignore(std::numeric_limits<std::streamsize>::max(), '/');
		applicationLine >> hour;
		applicationLine.ignore(std::numeric_limits<std::streamsize>::max(), '/');
		applicationLine >> minute;
		applicationLine.ignore(std::numeric_limits<std::streamsize>::max(), ';');
		date.setYear(year);
		date.setMonth(month);
		date.setDay(day);
		date.setHour(hour);
		date.setMinute(minute);

		// get id
		applicationLine >> id;

		Application *  app = new Application(date, id);
		applications.push_back(app);
	}

	applicationsFile.close();
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
bool Company::writeApplicationsFile(string fileName) {
	ofstream contestantsFile(fileName + ".dat");
	unsigned int i = 0;
	for (; i < applications.size() - 1; i++) {
		contestantsFile << applications[i]->date.full() << " ; " << applications[i]->contestantId << endl;
	}
	contestantsFile << applications[i]->date.full() << " ; " << applications[i]->contestantId;

	contestantsFile.close();

	return true;
}

/* --------------------------------------- JUDGE --------------------------------------*/
Judge * Company::getJudgeById(unsigned int id) {
	for (size_t i = 0; i < judges.size(); i++) {
		if (judges[i]->getId() == id)
			return judges[i];
	}
	throw JudgeIdNotFound(id);
}
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
bool Company::hasSpecialty(string specialty) {
	for (size_t i = 0; i < judges.size(); i++) {
		if (judges[i]->getSpecialty() == specialty)
			return true;
	}
	return false;
}
/* -------------------------------------- AUDITION ------------------------------------*/

Audition * Company::getAuditionById(unsigned int id) {
	for (size_t i = 0; i < auditions.size(); i++) {
		if (auditions[i]->getId() == id)
			return auditions[i];
	}
	throw AuditionIdNotFound(id);
}
void Company::addAudition(Audition * audition) {
	for (unsigned int i = 0; i < auditions.size(); i++)
	{
		if (*auditions[i] == *audition)
			return;
	}
	lastJudgeId++;
	audition->setId(lastJudgeId);
	auditions.push_back(audition);
	sort(auditions.begin(), auditions.end(), comparePointedValues<Audition>);
}
void Company::showAuditionInDetail(unsigned int id) {

		
}
void Company::scheduleAudition(string specialty, vector<unsigned int> cntestnts, vector<unsigned int> jdges) {
	//if (cntestnts.size() <= 6)
		// throw an exception

	//if (jdges.size() < 3)
		// throw an exception

	//if (jdges.size() > 4
	unsigned int dur = cntestnts.size()*(15 + 5) + 5 * 30;
	Time duration = Time(0, 0, 0, dur / 60, dur % 60);
	lastAuditionId++;
	vector<unsigned int> evs;
	evs.push_back(jdges[0]);
	evs.push_back(jdges[1]);
	unsigned int id = lastAuditionId;
	Time begining = startOfFunctions;
	Time ending = duration + startOfFunctions;
	Audition audition(id, begining, ending, specialty, evs, jdges[2]);
}
bool Company::readAuditionsFile(string fileName) {
	ifstream auditionsFile(fileName + ".dat");

	string textLine;
	//in case of failure during the opening
	if (auditionsFile.fail())
	{
		return false;
	}

	while (!auditionsFile.eof()) /* adds elements to the Contestant* std::vector until the whole file is read */
	{
		getline(auditionsFile, textLine);
		Audition * audition = new Audition(textLine);
		//addAudition(audition);
	}

	auditionsFile.close();
	return true;
}
bool Company::writeAuditionsFile(string fileName) {
	return true;
}