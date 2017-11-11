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
	

public:
	/* ------------------------------------ CONTESTANT -----------------------------------*/
	void addContestant(Contestant * contestant);
	void removeContestant(Contestant * contestant);
	bool readContestantsFile(string fileName);
	bool writeContestantsFile(string fileName);
	bool readContestantsToEnrollFile(string fileName);
	bool writeContestantsToEnrollFile(string fileName);

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


#endif //_COMPANY_H
