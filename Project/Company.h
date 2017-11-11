#include <string>
#include "Person.h"
#include "Contestant.h"
#include "Judge.h"
using namespace std;

#ifndef _COMPANY_H
#define _COMPANY_H

class Company {
	vector<Contestant*> contestants;
	vector<Judge *> judges;
	

public:
	/* ------------------------------------ CONTESTANT -----------------------------------*/
	bool addContestant(Contestant * contestant);
	bool readContestantsFile(string fileName);
	void writeContestantsFile(string fileName);

	/* -------------------------------------- JUDGE --------------------------------------*/
	bool addJudge(Judge * judge);
	bool readJudgesFile(string fileName);
	void writeJudgesFile(string fileName);
};


#endif //_COMPANY_H
