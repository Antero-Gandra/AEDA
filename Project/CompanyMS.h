#include "Company.h"


#ifndef _COMPANYMS_H
#define _COMPANYMS_H

class CompanyMS {
public:
	void run();
	//Constructor
	CompanyMS(Company &company);
private:
	Company company;
	void mainMenu();

};

#endif //_COMPANYMS_H