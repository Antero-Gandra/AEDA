
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
	/**
	* @brief Manages to access all contestants ever applied
	* @return constant vector of Contestant Object pointers
	*/
	std::vector<Contestant*> getContestants() const;
	
	/**
	* @brief Manages to access all judges ever hired
	* @return constant vector of Judge Object pointers
	*/
	std::vector<Judge*> getJudges() const;
	
	/**
	* @brief Manages to access all applications ever created
	* @return constant vector of Application Object pointers
	*/
	std::vector<Application*> getApplications() const;
	
	/**
	* @brief Manages to access all auditions ever created
	* @return constant vector of Audition Object pointers
	*/
	std::vector<Audition*> getAuditions() const;

	/* ------------------------------------ CONTESTANT -----------------------------------*/
	
	/**
	* @brief Manages to access a Contestant by ID
	* @param id an unsigned int
	* @return Contestant Object pointer
	*/
	Contestant * getContestantById(unsigned int id);
	
	/**
	* @brief Manages to access a contestant's ID
	* @param contestant a Contestant Object pointer
	* @return unsigned integer's ID of the Contestant
	*/
	unsigned int getContestantByInfo(Contestant * contestant);
	
	/**
	* @brief Manages to get all contestnts of a specific specialty and save them to a reference vector of Contestant Object Pointers
	* @param specialty a string, contestants a reference vector of Contestant Object pointer
	*/
	void getContestantsOfSpecialty(std::string specialty, std::vector<Contestant*> & contestants);
	
	/**
	* @brief Manages to get all applications of a specific specialty and save them to a reference vector of Application Object Pointers
	* @param specialty a string, applications a reference vector of Application Object pointer
	*/
	void getApplicationsOfSpecialty(std::string specialty, std::vector<Application*> & applications);
	
	/**
	* @brief Manages to randomly select, at least, 24 contestants of a given specialty and saving them to a reference vector of Contestant Object Pointers
	* @param specialty a string, contestants a reference vector of Contestant Object pointer
	*/
	void generateContestantsOfSpecialty(std::string specialty, std::vector<Contestant*> & contestants);
	
	/**
	* @brief Manages to apply contestants to a reference vector of Application Object Pointers
	* @param contestants a reference vector of unsigined integers, applications a reference vector of Application Object Pointers 
	*/
	void getContestantsOfApplications(std::vector<unsigned int> & contestants, const std::vector<Application*> & applications);
	
	/**
	* @brief Adds a new Contestant to the vector of all Contestants of the company
	* @param contestant a pointer of Contestant Object
	*/
	void addNewContestant(Contestant * contestant);
	
	/**
	* @brief Adds a Contestant to the vector of all Contestants of the company
	* @param contestant a pointer of Contestant Object
	*/
	void addContestant(Contestant * contestant);
	
	/**
	* @brief Adds an application with the date and id
	* @param calendar a Calendar Object, id unsigined integer
	*/
	void addApplication(Calendar calendar, unsigned int id);
	
	/**
	* @brief Updates a Contestant with new information
	* @param contestant a Contestant Object Pointer, modConstant a Contestant Object Pointer
	*/
	void updateContestant(Contestant * contestant, Contestant * modContestant);
	
	/**
	* @brief Removes a specified Contestant
	* @param contestant a Contestant Object pointer
	*/
	void removeContestant(Contestant * contestant);
	
	/**
	* @brief Manages to access a vector of applications from a specified Contestant's ID
	* @param id unsigined integer
	* @return vector of Application Object Pointers
	*/
	std::vector<Application*> getApplicationsById(unsigned int id);
	
	/**
	* @brief Removes a Contestant's application when they get appied due to a schedule creation
	* @param contestant a Contestant Object Pointer
	* @return Calendar Object
	*/
	Calendar removeOneApplicationOfContestant(Contestant* contestant);
	void removeApplicationsOfContestant(Contestant * contestant);
	
	/**
	* @brief Reads the contestant information from a file and calls the function that creates a contestant
	* @param fileName a string with the name of the file
	* @return true if successfully reads all the file, false otherwise
	*/
	bool readContestantsFile(std::string fileName);
	
	/**
	* @brief Writes the contestant information into a file
	* @param fileName a string with the name of the file
	* @return true if successfully writes all the information into the file, false otherwise
	*/
	bool writeContestantsFile(std::string fileName);
	
	/**
	* @brief Reads the application information from a file and calls the function that creates an application
	* @param fileName a string with the name of the file
	* @return true if successfully reads all the file, false otherwise
	*/
	bool readApplicationsFile(std::string fileName);
	
	/**
	* @brief Writes the application information into a file
	* @param fileName a string with the name of the file
	* @return true if successfully writes all the information into the file, false otherwise
	*/
	bool writeApplicationsFile(std::string fileName);

	/* -------------------------------------- JUDGE --------------------------------------*/
	/**
	* @brief Manages to access a Judge by ID
	* @param id an unsigned int
	* @return Judge Object pointer
	*/
	Judge * getJudgeById(unsigned int id);
	
	/**
	* @brief Manages to get the ID of a Judge 
	* @param judge a Judge Object Pointer
	* @return unsigined integer of the Judge's ID
	*/
	unsigned int getJudgeByInfo(Judge * judge);
	
	/**
	* @brief Manages to sort a vector of judges who are of the specified specialty
	* @param specialty a string, judges a vector reference of Judge Object Pointers
	*/
	void getJudgesOfSpecialty(std::string specialty, std::vector<Judge*> & judges);
	
	/**
	* @brief Manages to sort a vector of judges who are not of the specified specialty
	* @param specialty a string, judges a vector reference of Judge Object Pointers
	*/
	void getJudgesNotOfSpecialty(std::string specialty, std::vector<Judge*> & judges);
	
	/**
	* @brief Manages to randomly select the Judge who will be responsible for the audition, that has the same specialty as said audition at a given date
	* @param date Calendar Object, specialty a string, chiefJudge an unsigined int reference
	*/
	
	void generateChiefJudge(Calendar date, std::string specialty, unsigned int & chiefJudge);
	
	/**
	* @brief Manages to randomly select the two Judges who are not responsible for the audition, that have the same specialty as said audition at a given date
	* @param date Calendar Object, specialty a string, judges a vector reference of unsigined int
	*/
	void generateJudges(Calendar date, std::string specialty, std::vector<unsigned int> & judges);
	
	/**
	* @brief Adds a Judge to the vector of all Contestants of the company
	* @param judge a pointer of Judge Object
	*/
	void addJudge(Judge * judge);
	
	/**
	* @brief Adds a new Judge to the vector of all Contestants of the company
	* @param judge a pointer of Judge Object
	*/
	void addNewJudge(Judge * judge);
	
	/**
	* @brief Updates a Judge with new information
	* @param judge a Judge Object Pointer, modJudge a Judge Object Pointer
	*/
	void updateJudge(Judge * judge, Judge * modJudge);
	
	/**
	* @brief Removes a specified Judge
	* @param judge a Judge Object pointer
	*/
	void removeJudge(Judge * judge);
	
	/**
	* @brief Reads the judges information from a file and calls the function that creates a judge
	* @param fileName a string with the name of the file
	* @return true if successfully reads all the file, false otherwise
	*/
	bool readJudgesFile(std::string fileName);
	
	/**
	* @brief Writes the judge information into a file
	* @param fileName a string with the name of the file
	* @return true if successfully writes all the information into the file, false otherwise
	*/
	bool writeJudgesFile(std::string fileName);
	
	/**
	* @brief Checks if a judge has the specified specialty
	* @param specialty a string 
	* @return true if the judge has specialty, false otherwise
	*/
	bool hasSpecialty(std::string specialty);
	
	/**
	* @brief Adds to specialties, vector of strings, all the individual specialties there currently are 
	* @param specialties a vector reference of strings
	*/
	void getSpecialties(std::vector<std::string> & specialties);
	
	/**
	* @brief Checks if a judge is already evaluating an audition at a specific date
	* @param date a Calendar Object, id an unsigined int of the judge
	* @return integer -1 if the judge with the specified id is already evaluating an audition at that specific date, otherwise returns the judge's id
	*/
	int judgeIsOcupied(Calendar date, unsigned int id);

	/* -------------------------------------- AUDITION -----------------------------------*/
	/**
	* @brief Manages to access an Audition by ID
	* @param id an unsigned int
	* @return Audition Object pointer
	*/
	Audition * getAuditionById(unsigned int id);
	
	/**
	* @brief Manages to add to the auditions vector all the auditions of a specified specialy
	* @param specialty a string, auditions a vector reference of Audition Object Pointers
	*/
	void getAuditionsOfSpecialy(std::string specialty, std::vector<Audition*> & auditions);
	
	/**
	* @brief Searches an audition from a specified date and specialty
	* @param date a Calendar Object, specialty a string
	* @return integer -1 if there is no audition with the specified date and specialty, otherwise returns the position of the auditions vector
	*/
	int getAuditionOfDayOfSpecialty(Calendar date, std::string specialty);
	
	/**
	* @brief Manages to get the duration of the full audition due to the number of candidates
	* @param nCandidates an unsigined int
	* @return Calendar Object
	*/
	Calendar getDurationOfAudition(unsigned int nCandidates);
	
	/**
	* @brief Manages to get the number of Contestants per Audition
	* @return unsigined int 
	*/
	unsigned int getMaxNumOfContestantsPerAudition();
	
	/**
	* @brief Adds an audition
	* @param audition an Audition Object Pointer
	*/
	void addAudition(Audition * audition);
	
	/**
	* @brief Schedule an audition with specific specialty, beginning date, vector of contestant's id, vector of judge's id and the id of the reposible judge; calculates the ending time of said audition
	* @param specialty a string, beginning a Calendar Object, contestants a vector of unsigined integeters, judges a vector of unsigined integers, chiefJudge an unsigined integer
	*/
	void scheduleAudition(std::string specialty, Calendar beginning, std::vector<unsigned int> contestants, std::vector<unsigned int> judges, unsigned int chiefJudge);
	
	/**
	* @brief Schedule an audition with the max number of contestants within a specific specialty
	* @param specialty a string
	*/
	void scheduleMaxAuditionsOfSpecialty(std::string specialty);
	
	/**
	* @brief Schedule an audition with the max number of contestants
	*/
	void scheduleMaxAuditions();
	
	/**
	* @brief Schedule an audition with specific specialty
	* @param contestants a vector of unsigned integets, specialty a string
	* @return Calendar Object
	*/
	Calendar scheduleAuditionCalendar(std::vector<unsigned int> contestants, std::string specialty);
	
	/**
	* @brief Reads the audition information from a file and calls the function that creates an audition
	* @param fileName a string with the name of the file
	* @return true if successfully reads all the file, false otherwise
	*/
	bool readAuditionsFile(std::string fileName);
	
	/**
	* @brief Writes the audition information into a file
	* @param fileName a string with the name of the file
	* @return true if successfully writes all the information into the file, false otherwise
	*/
	bool writeAuditionsFile(std::string fileName);
	
	/**
	*TBC
	*/
	void showAuditionInDetail(unsigned int id);
	
	/**
	* @brief Grades all auditions, updating the participation of contestants who managed to get to Second Phase and those who didn't
	*/
	
	void gradeAllAuditions();

	void gradeAudition(unsigned int auditionId);
};
   
/**
* @brief Compares two templates from object Comperable to check which one is greater or lesser
* @param comparable1 Comperable Object Pointer, comparable2 Comperable Object Pointer
* @return true if comparable1's id is smaller than comparable2's id, false otherwise
*/
template <class Comparable>
bool compareById(Comparable * comparable1, Comparable * comparable2) {
	return (comparable1->getId() < comparable2->getId());
}

/**
* @brief Compares two templates from object Comparable to check which one is greater or lesser
* @param comparable1 Comperable Object Pointer, comparable2 Comperable Object Pointer
* @return true if comparable1 is smaller than comparable2, false otherwise
*/ 
template <class Comparable>
bool compareWithOperator(Comparable * comparable1, Comparable * comparable2) {
	return *comparable1 < *comparable2;
}

/**
* @brief Compares two templates from object P to check if they are the same
* @param person1 P Object Pointer, person2 P Object Pointer
* @return true if person1's id is equal to person's id, false otherwise
*/
template <class P>
bool shareSameId(P * person1, P * person2) {
	return person1->getId() == person2->getId();
}

#endif //_COMPANY_H
