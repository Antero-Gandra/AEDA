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
	void EnrollAContestantMenu();
	void ModifyContestantInfo();
	void showApplicationsMenu();
	void showContestantsMenu();
	void showJudgesMenu();

	bool isValidOption(string option, unsigned int infLim, unsigned int supLim);
	bool isYesOrNo(string answer);
	bool isValidId(string id);
	bool isValidString(string s);
	bool isValidDob(Time dob);
	bool isValidNumber(string number);
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);
	bool YesNoHandler();
	unsigned int IdHandler();
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
