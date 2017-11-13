/**
 * Project Untitled
 */


#include "CompanyMS.h"
#include "Company.h"
#include "Time.h"
#include <iostream>


int main()
{
	Company company;
	CompanyMS MS(company);
	MS.run();

	return 0;
}

CompanyMS::CompanyMS(Company &company) {
	this->company = company;
}

void CompanyMS::run() {
	company.readContestantsFile("contestants");
	company.showContestants();
	company.writeContestantsFile("contestants");
	company.readJudgesFile("judges");
	company.showJudges();
	company.writeJudgesFile("judges");

	int a;
	cin >> a;
	/*
	do
	{
		clearScreen();
		mainMenu(); //invokes the menu displayer
	} while (!std::cin.eof());
	*/
}

void CompanyMS::mainMenu() {

	unsigned int op;

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";

	cout << "1. CONTESTANT" << endl;
	cout << "2. JUDGE" << endl;
	cout << "3. AUDITION" << endl;
	cout << "0. EXIT" << endl;


	clearScreen();

	while (!(cin >> op) && op > 3 && op < 0) {
		cout << "Option " << op << "is not valid. Please try again." << endl;
		cin >> op;
		cin.clear();
		cin.ignore(1000, '\n');
	}

	switch (op) {
	case 1: CompanyMS::contestantMenu(); break;
	case 2: CompanyMS::judgeMenu(); break;
	case 3: CompanyMS::auditionMenu(); break;
	case 0: exit(-1); break;
	default: CompanyMS::mainMenu(); break;
	}
}

void CompanyMS::contestantMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: CONTESTANT ::::::::: \n";

	cout << "1. Enroll a contestant" << endl;
	cout << "2. Modify the info of a current contestant" << endl;
	cout << "3. Kick a contestant out" << endl;
	cout << "4. Print current list of contestants" << endl;

}

void CompanyMS::judgeMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: JUDGE ::::::::: \n";

	cout << "1. Employ a judge" << endl;
	cout << "2. Modify the info of a current judge" << endl;
	cout << "3. Fire a judge" << endl;
	cout << "4. Print current list of judges" << endl;
}

void CompanyMS::auditionMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: AUDITION ::::::::: \n";

	cout << "1. Create a new specific audition" << endl;
	cout << "2. Modify a current audition" << endl;
	cout << "3. Disassemble an audition" << endl;
	cout << "4. Print current list of auditions" << endl;
}

void showContestantsByIdMenu() {

}

void CompanyMS::clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	cout << string(40, '\n');
#endif
}
