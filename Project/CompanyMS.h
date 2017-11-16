#include "Company.h"

#ifndef _COMPANYMS_H
#define _COMPANYMS_H


#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
class CompanyMS {
	static Time currentTime;
public:
	void run();
	void mainMenu();
	void contestantMenu();
	void judgeMenu();
	void auditionMenu();
	//CONTESTANTS MENUS
	void enrollAContestantMenu();
	void modifyContestantInfoMenu();
	void removeContestantMenu();
	void readContestantsFileMenu();
	void showContestantsMenu();
	void removeContestantsApplicationsMenu();
	void readApplicationsFileMenu();
	void showApplicationsMenu();

	//JUDGES MENUS
	void employJudgeMenu();
	void modifyJudgeInfoMenu();
	void fireJudgeMenu();
	void readJudgesFileMenu();
	void showJudgesMenu();

	//SESSIONS
	void scheduleAuditionMenu();
	void scheduleAuditionsForAllMenu();
	void modifyAuditionMenu();
	void disassembleAuditionMenu();
	void showAuditionsMenu();

	//CANDIDATES SHOW FUNCTIONS
	void showContestants();
	void showApplications();
	void showApplicationsOfSpecialty(string specialty);

	//INPUT HANDLING
	bool isValidOption(string option, unsigned int infLim, unsigned int supLim);
	bool isYesOrNo(string answer);
	bool isValidId(string id);
	bool isValidString(string s);
	bool isValidDob(Time dob);
	bool isValidNumber(string number);
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);
	bool yesNoHandler();
	unsigned int idHandler();
	string stringHandler(string type);
	Time dobHandler();
	string specialtyHandler();
	unsigned int numberHandler(string type);

	void clearScreen();
	//Constructor
	CompanyMS(Company * company);
private:
	Company * company;
};

#endif //_COMPANYMS_H
