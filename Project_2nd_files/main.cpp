
#include "CompanyMS.h"
#include "Util.h"
#include "ExceptionHand.h"
#include <ctime>
#include <iostream>
#include <wchar.h>
#include <stdio.h>
#include <string>
#include <iomanip>


int main() {
	Company * company = new Company();
	CompanyMS * managementSystem= new CompanyMS(company);
	managementSystem->run();
	delete company;
	delete managementSystem;
	return 0;
}