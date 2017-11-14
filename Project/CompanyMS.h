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
	void showApplicationsMenu();

	bool isValidOption(string option, unsigned int infLim, unsigned int supLim);
	bool isYesOrNo(string answer);
	bool isValidId(string id);
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);
	bool YesNoHandler();
	unsigned int IdHandler();
	void clearScreen();
	//Constructor
	CompanyMS(Company * company);
private:
	Company * company;
};

#endif //_COMPANYMS_H
