#include <string>
#include "Person.h"
#include "Contestant.h"
#include "Judge.h"


#ifndef _COMPANY_H
#define _COMPANY_H

struct Application {
	Time date;
	unsigned int contestantId;
	Application(Time date, unsigned int contestantId) {
		this->date = date;
		this->contestantId = contestantId;
	}
};

class Company {
	vector<Contestant*> contestants;
	vector<Application*> applications;
	vector<Judge *> judges;
	static unsigned int lastContestantId;
	static unsigned int lastJudgeId;
	static unsigned int lastAuditionId;
	const Time startOfFunctions = Time(0, 0, 0, 8, 30);
	const Time endOfFunctions = Time(0, 0, 0, 20, 30);
	
public:
	//getMethods
	vector<Contestant*> getContestants() const;
	vector<Judge*> getJudges() const;
	vector<Application*> getApplications() const;

	/* ------------------------------------ CONTESTANT -----------------------------------*/

	Contestant * getContestantById(unsigned int id);
	unsigned int getContestantByInfo(Contestant *);
	void addContestant(Contestant * contestant);
	void addApplication(Time ctime, unsigned int id);
	void updateContestant(Contestant * contestant, Contestant * modContestant);
	void removeContestant(Contestant * contestant);
	bool readContestantsFile(string fileName);
	bool writeContestantsFile(string fileName);
	bool readApplicationsFile(string fileName);
	bool writeApplicationsFile(string fileName);
	void showContestants();
	void showApplications();

	/* -------------------------------------- JUDGE --------------------------------------*/
	void addJudge(Judge * judge);
	void removeJudge(Judge * judge);
	bool readJudgesFile(string fileName);
	bool writeJudgesFile(string fileName);
	void showJudges();
	bool hasSpecialty(string specialty);

	/* -------------------------------------- AUDITION -----------------------------------*/
	void scheduleAudition(string speacialty, vector<unsigned int>, vector<unsigned int>);

};
   

template <class Comparable>
bool comparePointedValues(Comparable * comparable1, Comparable * comparable2) {
	return (*comparable1 < *comparable2);
}

template <class Person>
bool shareSameId(Person * person1, Person * person2) {
	return *person1.getId() == person2.getId();
}


#endif //_COMPANY_H
