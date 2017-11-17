
#ifndef _COMPANY_H
#define _COMPANY_H

#include <string>
#include "Person.h"
#include "Contestant.h"
#include "Judge.h"
#include "Audition.h"
#include "Application.h"
#include "Calendar.h"

class Company {
	std::vector<Contestant*> contestants;
	std::vector<Application*> applications;
	std::vector<Judge *> judges;
	std::vector<Audition*> auditions;
	static unsigned int lastContestantId;
	static unsigned int lastJudgeId;
	static unsigned int lastAuditionId;
	const Calendar startOfFunctions = Calendar(0, 0, 0, 8, 30);
	const Calendar endOfFunctions = Calendar(0, 0, 0, 20, 30);
	const Calendar durationOfPerformancesF1 = Calendar(0, 0, 0, 0, 15);
	const Calendar breakBetweenPerfomancesF1 = Calendar(0, 0, 0, 0, 5);
	const Calendar breakBetweenF1andF2 = Calendar(0, 0, 0, 0, 35);
	const Calendar durationOfPerformancesF2 = Calendar(0, 0, 0, 0, 30);
	const Calendar breakBetweenPerfomancesF2 = Calendar(0, 0, 0, 0, 10);
	
public:
	//getMethods
	std::vector<Contestant*> getContestants() const;
	std::vector<Judge*> getJudges() const;
	std::vector<Application*> getApplications() const;

	/* ------------------------------------ CONTESTANT -----------------------------------*/

	Contestant * getContestantById(unsigned int id);
	unsigned int getContestantByInfo(Contestant *);
	void getContestantsOfSpecialty(std::string specialty, std::vector<Contestant*> & contestants);
	void getApplicationsOfSpecialty(std::string specialty, std::vector<Application*> & applications);
	void generateContestantsOfSpecialty(std::string specialty, std::vector<Contestant*> & contestants);
	void addContestant(Contestant * contestant);
	void addApplication(Calendar calendar, unsigned int id);
	void updateContestant(Contestant * contestant, Contestant * modContestant);
	void removeContestant(Contestant * contestant);
	std::vector<Application*> getApplicationsById(unsigned int id);
	void removeOneApplicationOfContestant(Contestant* contestant);
	void removeApplicationsOfContestant(Contestant * contestant);
	bool readContestantsFile(std::string fileName);
	bool writeContestantsFile(std::string fileName);
	bool readApplicationsFile(std::string fileName);
	bool writeApplicationsFile(std::string fileName);

	/* -------------------------------------- JUDGE --------------------------------------*/
	Judge * getJudgeById(unsigned int id);
	void getJudgesOfSpecialy(std::string specialty, std::vector<Judge*> & judges);
	void generateJudgesForSpecialty(std::string specialty, std::vector<Judge*> & judges);
	void addJudge(Judge * judge);
	void removeJudge(Judge * judge);
	bool readJudgesFile(std::string fileName);
	bool writeJudgesFile(std::string fileName);
	void showJudges();
	bool hasSpecialty(std::string specialty);

	/* -------------------------------------- AUDITION -----------------------------------*/
	Audition * getAuditionById(unsigned int id);
	void getAuditionsOfSpecialy(std::string specialty, std::vector<Audition*> & auditions);
	Calendar getDurationOfAudition(unsigned int nCandidates);
	unsigned int getMaxNumOfContestantsPerAudition();
	void addAudition(Audition * audition);
	void scheduleAudition(std::string speacialty, std::vector<unsigned int>, std::vector<unsigned int>);
	bool readAuditionsFile(std::string fileName);
	bool writeAuditionsFile(std::string fileName);
	void showAuditionInDetail(unsigned int id);

};
   

template <class Comparable>
bool comparePointedValues(Comparable * comparable1, Comparable * comparable2) {
	return (*comparable1 < *comparable2);
}

template <class Person>
bool shareSameId(Person * person1, Person * person2) {
	return person1->getId() == person2->getId();
}


#endif //_COMPANY_H
