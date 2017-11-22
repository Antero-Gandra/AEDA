#ifndef _COMPANYMS_H
#define _COMPANYMS_H


#include <cstdlib>
#include <vector>

#include "Calendar.h"
#include "Company.h"

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
	void modifyContestantMenu();
	void removeContestantMenu();
	void readContestantsFileMenu();
	void showContestantsMenu();
	void searchContestantByIdMenu();
	void removeContestantsApplicationsMenu();
	void readApplicationsFileMenu();
	void showApplicationsMenu();

	//JUDGES MENUS
	void employJudgeMenu();
	void modifyJudgeMenu();
	void fireJudgeMenu();
	void readJudgesFileMenu();
	void showJudgesMenu();
	void searchJudgeByIdMenu();

	//AUDITIONS
	void scheduleAuditionMenu();
	void scheduleMaxAuditionsMenu();
	void modifyAuditionMenu();
	void disassembleAuditionMenu();
	void evaluateAuditionMenu();
	void evaluateAllAuditions();
	void showAuditionsMenu();

	//CANDIDATES SHOW FUNCTIONS
	void showContestants();
	void showApplications();
	void showApplicationsOfSpecialty(std::string specialty);
	void showJudges();
	void showAudition(unsigned int id);

	//INPUT HANDLING
	bool isValidOption(std::string option, unsigned int infLim, unsigned int supLim);
	bool isYesOrNo(std::string answer);
	bool isValidContestantId(std::string id);
	bool isValidJudgeId(std::string id);
	bool isValidString(std::string s);
	bool isValidDob(Calendar dob);
	bool isValidNumber(std::string number);
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);
	bool yesNoHandler();
	unsigned int contestantIdHandler();
	unsigned int judgeIdHandler();
	std::string stringHandler(std::string type);
	Calendar dobHandler();
	std::string specialtyHandler();
	unsigned int numberHandler(std::string type);

	//FILE SYNC
	void updateFilesHandler();
	//APPEARANCE
	void printInColour(std::string text, unsigned  int colour, bool dark);
	void clearScreen();
	//Constructor
	CompanyMS(Company * company);
private:
	Company * company;
};

#endif //_COMPANYMS_H
