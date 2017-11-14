#include "Company.h"

#ifndef _COMPANYMS_H
#define _COMPANYMS_H


#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
extern Time currentTime;
class CompanyMS {
public:
	void run();
	void mainMenu();
	void contestantMenu();
	void judgeMenu();
	void auditionMenu();
	void showApplicationsMenu();

	bool isValidOption(string option, unsigned int infLim, unsigned int supLim);
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);
	void clearScreen();
	//Constructor
	CompanyMS(Company * company);
private:
	Company * company;
};

#endif //_COMPANYMS_H
