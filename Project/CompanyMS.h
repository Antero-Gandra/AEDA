#include "Company.h"


#ifndef _COMPANYMS_H
#define _COMPANYMS_H


#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class CompanyMS {
public:
	void run();
	void mainMenu();
	void contestantMenu();
	void judgeMenu();
	void auditionMenu();
	void clearScreen();
	//Constructor
	CompanyMS(Company &company);
private:
	Company company;
	void mainMenu();

};

#endif //_COMPANYMS_H#endif //_COMPANYMS_H
