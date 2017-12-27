#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
#include "Company.h"
#include "Contestant.h"
#include "UnavailableContestant.h"
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
	Contestant * contestant = new Contestant(id, "", "", 0, Calendar(), "", {});
	contestant = binarySearch<Contestant>(contestants, contestant);
	if (contestant == NULL)
		throw ContestantIdNotFound(id);
	else return contestant;
}
unsigned int Company::getContestantByInfo(Contestant * contestant) {
	for (size_t i = 0; i < contestants.size(); i++) {
		if (*contestants[i] == *contestant)
			return contestants[i]->getId();
	}
	throw ContestantInfoNotFound();
}
void Company::getContestantsOfSpecialty(string specialty, vector<Contestant*> & contestants) {
	for (size_t i = 0; i < this->contestants.size(); i++)
	{
		if (this->contestants[i]->getSpecialty() == specialty)
			contestants.push_back(this->contestants[i]);
	}
}
void Company::getApplicationsOfSpecialty(string specialty, vector<Application*> & applications) {
	for (size_t i = 0; i < this->applications.size(); i++)
	{
		Contestant * contestant = getContestantById(this->applications[i]->contestantId);
		if (contestant->getSpecialty() == specialty)
			applications.push_back(this->applications[i]);
	}
}
void Company::generateContestantsOfSpecialty(string specialty, vector<Contestant*> & contestants) {
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
	sort(contestants.begin(), contestants.end());
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
void Company::addNewContestant(Contestant * contestant) {
	lastContestantId++;
	contestant->setId(lastContestantId);
	addContestant(contestant);
}
void Company::addContestant(Contestant * contestant) {
	contestants.push_back(contestant);
	sort(contestants.begin(), contestants.end(), compareById<Contestant>);
}
void Company::switchToUnavailble(Contestant *  contestant, Calendar unavailablePeriodBegin, Calendar unavailbalePeriodEnd, string reason) {
	removeContestant(contestant);
	UnavailableContestant * uCont = new UnavailableContestant(contestant->getId(), contestant->getName(), contestant->getAddress(), contestant->getMobile(), contestant->getDob(), contestant->getSpecialty(), contestant->getParticipations(), unavailablePeriodBegin, unavailbalePeriodEnd, reason);
	UContestantPtr uCPtr;
	uCPtr.uCont = uCont;
	unavailable_contestants.insert(uCPtr);
}
void Company::addApplication(Calendar calendar, unsigned int id) {
	Application * application = new Application(calendar, id);
	applications.push_back(application);
}
void Company::updateContestant(Contestant * contestant, Contestant * modContestant) {

	if (contestant->getSpecialty() != modContestant->getSpecialty())
		removeApplicationsOfContestant(contestant);
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
	return Calendar(0, 0, 0, 0, 0);
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
		lastContestantId = contestant->getId();
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
	sort(applications.begin(), applications.end(), compareWithOperator<Application>);
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
	Judge * judge = new Judge(id, "", "", 0, Calendar(), "", {});
	judge = binarySearch<Judge>(judges, judge);
	if (judge == NULL)
		throw JudgeIdNotFound(id);
	else return judge;
}
unsigned int Company::getJudgeByInfo(Judge * judge) {
	for (size_t i = 0; i < judges.size(); i++) {
		if (*judges[i] == *judge)
			return judges[i]->getId();
	}
	throw JudgeInfoNotFound();
}
void Company::getJudgesOfSpecialty(string specialty, vector<Judge*>  & judges) {
	for (size_t i = 0; i < this->judges.size(); i++)
	{
		if (this->judges[i]->getSpecialty() == specialty)
			judges.push_back(this->judges[i]);
	}
}
void Company::getJudgesNotOfSpecialty(string specialty, vector<Judge*> & judges) {
	for (size_t i = 0; i < this->judges.size(); i++)
	{
		if (this->judges[i]->getSpecialty() != specialty)
			judges.push_back(this->judges[i]);
	}
}
void Company::generateChiefJudge(Calendar date, string specialty, unsigned int & chiefJudge) {
	vector<Judge*> judgesOfSpecialty;
	getJudgesOfSpecialty(specialty, judgesOfSpecialty);
	unsigned int i;

	do {
		i = rand() % judgesOfSpecialty.size();

	} while (judgeIsOcupied(date, judgesOfSpecialty[i]->getId())!= -1);
	chiefJudge = judgesOfSpecialty[i]->getId();
}
void Company::generateJudges(Calendar date, string specialty, vector<unsigned int> & judges) {
	srand(time(NULL));
	vector<Judge*> judgesNotOfSpecialty;
	getJudgesNotOfSpecialty(specialty, judgesNotOfSpecialty);
	unsigned int i, j;

	//1st Judge
	do {
		i = rand() % judgesNotOfSpecialty.size();

	} while (judgeIsOcupied(date, judgesNotOfSpecialty[i]->getId()) != -1);
	judges.push_back(judgesNotOfSpecialty[i]->getId());

	//2nd Judge
	do {
		j = rand() % judgesNotOfSpecialty.size();
	} while (j == i || (judgeIsOcupied(date, judgesNotOfSpecialty[i]->getId()) != -1));
	sort(judgesNotOfSpecialty.begin(), judgesNotOfSpecialty.end());
	judges.push_back(judgesNotOfSpecialty[j]->getId());

}
void Company::addJudge(Judge * judge) {
	for (unsigned int i = 0; i < judges.size(); i++)
	{
		if (*judges[i] == *judge)
			return;
	}
	judges.push_back(judge);
	sort(judges.begin(), judges.end(), compareById<Judge>);
}
void Company::addNewJudge(Judge * judge) {
	lastJudgeId++;
	judge->setId(lastJudgeId);
	addJudge(judge);
}
void Company::updateJudge(Judge * judge, Judge * modJudge) {
	judge->setName(modJudge->getName());
judge->setDob(modJudge->getDob());
judge->setMobile(modJudge->getMobile());
judge->setAddress(modJudge->getAddress());
judge->setSpecialty(modJudge->getSpecialty());
}
void Company::removeJudge(Judge * judge) {
	for (auto it = judges.begin(); it < judges.end(); it++)
	{
		if ((*it)->getId() == judge->getId())
		{
			judges.erase(it);
			return;
		}
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
		lastJudgeId = judge->getId();
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
bool Company::hasSpecialty(string specialty) {
	for (size_t i = 0; i < judges.size(); i++) {
		if (judges[i]->getSpecialty() == specialty)
			return true;
	}
	throw SpecialtyNotAvailable(specialty);
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
int Company::judgeIsOcupied(Calendar date, unsigned int id) {
	unsigned int i = 0;
	if (auditions.empty()) return -1;
	for (size_t i = 0; i < auditions.size(); i++)
	{
		if (auditions[i]->getStart().date() == date.date()) {
			if (auditions[i]->getChiefJudgeId() == id || auditions[i]->getJudgesId()[0] == id || auditions[i]->getJudgesId()[1] == id)
				return i;
		}
	}
	return -1;
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
int Company::getAuditionOfDayOfSpecialty(Calendar date, std::string specialty) {
	for (size_t i = 0; i < auditions.size(); i++)
	{
		if (auditions[i]->getStart().date() == date.date() && auditions[i]->getSpecialty() == specialty)
			return i;
	}
	return -1;
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
	auditions.push_back(audition);
	sort(auditions.begin(), auditions.end(), compareWithOperator<Audition>);
}
void Company::showAuditionInDetail(unsigned int id) {


}
void Company::scheduleAudition(string specialty, Calendar beginning, vector<unsigned int> contestants, vector<unsigned int> judges, unsigned int chiefJudge) {
	lastAuditionId++;
	vector<Calendar> dateOfApplications;

	Calendar ending= getDurationOfAudition(contestants.size()) + beginning;

	sort(contestants.begin(), contestants.end());
	Audition * audition = new Audition(lastAuditionId, beginning, ending, specialty, judges, chiefJudge, contestants);
	auditions.push_back(audition);

}
Calendar Company::scheduleAuditionCalendar(vector<unsigned int> contestants, string specialty) {
	vector<Calendar> dateOfApplications;
	Calendar date;
	for (size_t i = 0; i < contestants.size(); i++)
	{
		Contestant * contestant = getContestantById(contestants[i]);
		Calendar date = removeOneApplicationOfContestant(contestant);
		dateOfApplications.push_back(date);
	}
	Calendar newestApp = dateOfApplications[0];
	for (size_t i = 0; i < dateOfApplications.size(); i++) {
		if (newestApp < dateOfApplications[i])
			newestApp = dateOfApplications[i];
	}
	date.setDay(newestApp.getDay() + Calendar(0, 0, 1, 0, 0));
	date.setMonth(newestApp.getMonth());
	date.setYear(newestApp.getYear());

	int auditionId = -1;

	auditionId = getAuditionOfDayOfSpecialty(date, specialty);
	while (auditionId != -1) {
		date = date + Calendar(0, 0, 1, 0, 0);
		auditionId = getAuditionOfDayOfSpecialty(date, specialty);
	}

	return date;
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
	unsigned int auditionId;

	// Contestants 
	getApplicationsOfSpecialty(specialty, applications);
	getContestantsOfApplications(contestants, applications);

	if (contestants.size() < 6) return;
	unsigned int max = getMaxNumOfContestantsPerAudition();

	while (contestants.size() >= 6) {
		if (contestants.size() > max) contestants.resize(max);
		
		//Get Date
		Calendar date = scheduleAuditionCalendar(contestants, specialty);
		date.setHour(startOfFunctions.getHour());
		date.setMinute(startOfFunctions.getMinute());

		//Judges
		judges = {};
		generateJudges(date, specialty, judges);
		generateChiefJudge(date, specialty, chiefJudge);

		scheduleAudition(specialty, date, contestants, judges, chiefJudge);


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
		if (textLine == "") break;
		Audition * audition = new Audition(textLine);
		addAudition(audition);
		lastAuditionId = audition->getId();
	}

	auditionsFile.close();
	return true;
}
bool Company::writeAuditionsFile(string fileName) {
	ofstream auditionsFile(fileName + ".dat");
	int i = 0;
	if (!auditions.empty()) {
		for (i = 0; i < (auditions.size() - 1); i++) {
			auditionsFile << *auditions[i] << "\n";
		}
		auditionsFile << *auditions[i];
	}
	auditionsFile.close();
	return true;

}
void Company::gradeAllAuditions() {
	for (size_t i = 0; i < auditions.size(); i++) {
		

	}
}
void Company::gradeAudition(unsigned int auditionId) {

	Audition * audition = getAuditionById(auditionId);
	vector<unsigned int> contestantsNotQualified = audition->gradeFirstFase();
	//Updating participations of contestants who did not qualify for secondFase

	for (size_t j = 0; j < contestantsNotQualified.size(); j++)
	{
		unsigned int id = contestantsNotQualified[j];
		Contestant * contestant = getContestantById(id);
		vector<Participation*> participations = contestant->getParticipations();
		vector<unsigned int> allContestants = audition->getFirstFase()->getContestants();
		//searching the grade
		unsigned int l = 0;
		while (allContestants[l] != id) {
			l++;
		}
		unsigned int chiefJudge = audition->getFirstFase()->getChiefJudge()[l];
		participations.push_back(new Participation(audition->getId(), 0, chiefJudge));
		contestant->setParticipations(participations);
	}

	vector<unsigned int> contestantsOrdered = audition->gradeSecondFase();

	//Updating participations of contestants who went to the secondFase
	for (size_t j = 0; j < contestantsOrdered.size(); j++) {
		unsigned int id = contestantsOrdered[j];
		Contestant * contestant = getContestantById(id);
		vector<Participation*> participations = contestant->getParticipations();
		vector<unsigned int> allContestants = audition->getSecondFase()->getContestants();
		//searching the grade
		unsigned int l = 0;
		while (allContestants[l] != id) {
			l++;
		}
		unsigned int chiefJudge = audition->getSecondFase()->getChiefJudge()[l];
		participations.push_back(new Participation(audition->getId(), j + 1, chiefJudge));
		contestant->setParticipations(participations);
	}
}

bool compareByCalendar(Audition * audition1, Audition *  audition2) {
	return (audition1->getStart() < audition2->getStart());
}