#ifndef _COMPANYMS_H
#define _COMPANYMS_H


#include <cstdlib>
#include <vector>

#include "Calendar.h"
#include "Company.h"

using namespace std;
class CompanyMS {
	static Calendar currentCalendar;
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

	//AUDITIONS
	void scheduleAuditionMenu();
	void scheduleMaxAuditionsMenu();
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
	bool isValidDob(Calendar dob);
	bool isValidNumber(string number);
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);
	bool yesNoHandler();
	unsigned int idHandler();
	string stringHandler(string type);
	Calendar dobHandler();
	string specialtyHandler();
	unsigned int numberHandler(string type);

	void clearScreen();
	//Constructor
	CompanyMS(Company * company);
private:
	Company * company;
};

#endif //_COMPANYMS_H
