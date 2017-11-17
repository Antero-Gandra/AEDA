#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include "Company.h"
#include "Contestant.h"
#include "Judge.h"
#include "ExceptionHand.h"
#include "Audition.h"
#include "Calendar.h"
#include "Util.h"
#include "time.h"

using namespace std;

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
vector<Audition*> Company::getAuditions() const {
	return auditions;
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
void Company::getContestantsOfSpecialty(string specialty, vector<Contestant*> & contestants) {
	for (size_t i = 0; i< this->contestants.size(); i++)
	{
		if (this->contestants[i]->getSpecialty() == specialty)
			contestants.push_back(this->contestants[i]);
	}
}
void Company::getApplicationsOfSpecialty(string specialty, vector<Application*> & applications) {
	for (size_t i = 0; i< this->applications.size(); i++)
	{
		Contestant * contestant = getContestantById(this->applications[i]->contestantId);
		if (contestant->getSpecialty() == specialty)
			applications.push_back(this->applications[i]);
	}
}
void Company::generateContestantsOfSpecialty(string specialty, vector<Contestant*> & contestants) {
	srand(time(NULL));
	vector<Contestant*> contestantsOfSpecialty;
	getContestantsOfSpecialty(specialty, contestantsOfSpecialty);
	unsigned int counter = 0;
	unsigned int i;

	//Choosing contestants
	while (counter < 24 && contestantsOfSpecialty.size() > 0) {
		i = rand() % contestantsOfSpecialty.size(); //randomly
		contestants.push_back(contestantsOfSpecialty[i]);
		contestantsOfSpecialty.erase(contestantsOfSpecialty.begin() + i);
		counter++;
	}
}
void Company::getContestantsOfApplications(vector<unsigned int> & contestants, const vector<Application*> & applications) {
	for (size_t i = 0; i < applications.size(); i++) {
		unsigned int id = applications[i]->contestantId;
		bool repeated = false;
		for (size_t i = 0; (i < contestants.size()) && (!repeated); i++)
		{
			if (contestants[i] == id) repeated = true;
		}
		if (!repeated) contestants.push_back(id);
	}
}
void Company::addContestant(Contestant * contestant) {
	lastContestantId++;
	contestant->setId(lastContestantId);
	contestants.push_back(contestant);
	sort(contestants.begin(), contestants.end(), comparePointedValues<Contestant>);
}
void Company::addApplication(Calendar calendar, unsigned int id) {
	Application * application = new Application(calendar, id);
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
Calendar Company::removeOneApplicationOfContestant(Contestant* contestant) {
	for (auto it = applications.begin(); it < applications.end(); it++)
	{
		if ((*it)->contestantId == contestant->getId())
		{
			Calendar oldestApplication = (*it)->date;
			applications.erase(it);
			return oldestApplication;
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
	Calendar date;
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
void Company::getJudgesOfSpecialty(string specialty, vector<Judge*>  & judges) {
	for (size_t i = 0; i< this->judges.size(); i++)
	{
		if (this->judges[i]->getSpecialty() == specialty)
			judges.push_back(this->judges[i]);
	}
}
void Company::getJudgesNotOfSpecialty(string specialty, vector<Judge*> & judges) {
	for (size_t i = 0; i< this->judges.size(); i++)
	{
		if (this->judges[i]->getSpecialty() != specialty)
			judges.push_back(this->judges[i]);
	}
}
void Company::generateChiefJudge(string specialty, unsigned int & chiefJudge) {
	srand(time(NULL));
	vector<Judge*> judgesOfSpecialty;
	getJudgesOfSpecialty(specialty, judgesOfSpecialty);
	unsigned int i;

	i = rand() % judgesOfSpecialty.size();
	chiefJudge = judgesOfSpecialty[i]->getId();
}
void Company::generateJudges(string specialty, vector<unsigned int> & judges) {
	srand(time(NULL));
	vector<Judge*> judgesNotOfSpecialty;
	getJudgesNotOfSpecialty(specialty, judgesNotOfSpecialty);
	unsigned int i, j;

	//1st Judge
	i = rand() % judgesNotOfSpecialty.size();
	judges.push_back(judgesNotOfSpecialty[i]->getId());

	//2nd Judge
	do {
		j = rand() % judgesNotOfSpecialty.size();
	} while (j == i);

	judges.push_back(judgesNotOfSpecialty[j]->getId());

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
void Company::getSpecialties(std::vector<std::string> & specialties) {
	bool repeated;
	for (size_t i = 0; i < judges.size(); i++) {
		repeated = false;
		string specialty = judges[i]->getSpecialty();
		for (size_t i = 0; i < specialties.size() && (!repeated); i++)
		{
			if (specialty == specialties[i]) repeated = true;
		}
		if (!repeated) specialties.push_back(specialty);
	}
}
/* -------------------------------------- AUDITION ------------------------------------*/

Audition * Company::getAuditionById(unsigned int id) {
	for (size_t i = 0; i < auditions.size(); i++) {
		if (auditions[i]->getId() == id)
			return auditions[i];
	}
	throw AuditionIdNotFound(id);
}
void Company::getAuditionsOfSpecialy(string specialty, vector<Audition*> & auditions) {
	for (size_t i = 0; i < this->auditions.size(); i++)
	{
		if (this->auditions[i]->getSpecialty() == specialty)
			auditions.push_back(this->auditions[i]);
	}
}
Calendar Company::getDurationOfAudition(unsigned int nContestants) {
	unsigned int durationPer1 = (unsigned int)durationOfPerformancesF1;
	unsigned int breakPer1 = (unsigned int)breakBetweenPerfomancesF1;
	unsigned int durationPer2 = (unsigned int)durationOfPerformancesF2;
	unsigned int breakPer2 = (unsigned int)breakBetweenPerfomancesF2;
	unsigned int breakBetF1andF2 = (unsigned int)breakBetweenF1andF2;
	unsigned int totalDuration = ((nContestants - 1)*(durationPer1 + breakPer1) + durationPer1 + breakBetF1andF2 + 4 * (durationPer2 + breakPer2) + durationPer2);
	Calendar duration = Calendar(0, 0, 0, totalDuration / 60, totalDuration % 60);
	return duration;

}
unsigned int Company::getMaxNumOfContestantsPerAudition() {
	unsigned int durationPer1 = (unsigned int)this->durationOfPerformancesF1;
	unsigned int breakPer1 = (unsigned int)this->breakBetweenPerfomancesF1;
	unsigned int durationPer2 = (unsigned int)this->durationOfPerformancesF2;
	unsigned int breakPer2 = (unsigned int)this->breakBetweenPerfomancesF2;
	unsigned int breakBetF1andF2 = (unsigned int)this->breakBetweenF1andF2;
	unsigned int fullDay = (unsigned int)this->endOfFunctions - (unsigned int)this->startOfFunctions;
	unsigned int nom = (fullDay - (durationPer1 + breakBetF1andF2 + 4 * (durationPer2 + breakPer2) + durationPer2));
	unsigned int denom = (durationPer1 + breakPer1);
	unsigned int nContestants = nom / denom + 1;
	return nContestants;
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
void Company::scheduleAudition(string specialty, Calendar begining, vector<unsigned int> contestants, vector<unsigned int> judges, unsigned int chiefJudge) {
	lastAuditionId++;
	Calendar ending = getDurationOfAudition(contestants.size()) + begining;
	vector<Calendar> dateOfApplications;
	for (size_t i = 0; i < contestants.size(); i++)
	{
		Contestant * contestant = getContestantById(contestants[i]);
		Calendar date = removeOneApplicationOfContestant(contestant);
		dateOfApplications.push_back(date);
	}
	Calendar newestApp = dateOfApplications[1];
	for (size_t i = 0; i < dateOfApplications.size(); i++){
		if (newestApp < dateOfApplications[i])
			newestApp = dateOfApplications[i];
	}
	begining.setDay(newestApp.getDay()+Calendar(0,0,1,0,0));
	begining.setMonth(newestApp.getMonth());
	begining.setYear(newestApp.getYear());
	Audition * audition = new Audition(lastAuditionId, begining, ending, specialty, judges, chiefJudge, contestants);
	auditions.push_back(audition);
}
void Company::scheduleMaxAuditions() {
	vector<string> specialties;
	getSpecialties(specialties);
	for (size_t i = 0; i < specialties.size(); i++) {
		scheduleMaxAuditionsOfSpecialty(specialties[i]);
	}
}
void Company::scheduleMaxAuditionsOfSpecialty(string specialty) {
	vector<Application*> applications;
	vector<unsigned int> contestants;
	vector<unsigned int> judges;
	unsigned int chiefJudge;

	// Contestants 
	getApplicationsOfSpecialty(specialty, applications);
	getContestantsOfApplications(contestants, applications);
	unsigned int max = getMaxNumOfContestantsPerAudition();


	while (contestants.size() > 6) {
		if (contestants.size() > max) contestants.resize(max);

		//Judges
		judges = {};
		generateJudges(specialty, judges);
		generateChiefJudge(specialty, chiefJudge);

		scheduleAudition(specialty, startOfFunctions, contestants, judges, chiefJudge);

		// Contestants 
		applications = {}; contestants = {};
		getApplicationsOfSpecialty(specialty, applications);
		getContestantsOfApplications(contestants, applications);
	}
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