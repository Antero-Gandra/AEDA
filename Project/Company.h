#include <string>
#include "Person.h"
#include "Contestant.h"
#include "Judge.h"
using namespace std;

#ifndef _COMPANY_H
#define _COMPANY_H

class Company {
	vector<Contestant*> contestants;
	vector<Contestant*> contestantsToEnroll;
	vector<Judge *> judges;
	static unsigned int lastContestantId;
	static unsigned int lastJudgeId;
	
public:
	//getMethods
	vector<Contestant*> getContestants() const;
	vector<Judge*> getJudges() const;

	/* ------------------------------------ CONTESTANT -----------------------------------*/
	void addContestant(Contestant * contestant);
	void removeContestant(Contestant * contestant);
	bool readContestantsFile(string fileName);
	bool writeContestantsFile(string fileName);
	bool readContestantsToEnrollFile(string fileName);
	bool writeContestantsToEnrollFile(string fileName);
	void showContestants();

	/* -------------------------------------- JUDGE --------------------------------------*/
	void addJudge(Judge * judge);
	void removeJudge(Judge * judge);
	bool readJudgesFile(string fileName);
	bool writeJudgesFile(string fileName);
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
