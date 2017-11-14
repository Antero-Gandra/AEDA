/**
 * Project Untitled
 */


#include "CompanyMS.h"
#include "Company.h"
#include "Time.h"
#include "Util.h"
#include "ExceptionHand.h"
#include <iostream>
Time currentTime = Time(2017, 11, 14, 12, 0);

int main()
{
	Company * company = new Company;
	CompanyMS MS(company);
	MS.run();

	return 0;
}

CompanyMS::CompanyMS(Company * company) {
	this->company = company;
}

void CompanyMS::run() {
	do
	{
		clearScreen();
		mainMenu(); //invokes the menu displayer
	} while (!std::cin.eof());
	cin.clear();
}

void CompanyMS::mainMenu() {

	string op;
	

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";

	cout << "1. CONTESTANT" << endl;
	cout << "2. JUDGE" << endl;
	cout << "3. AUDITION" << endl;
	cout << "Please Press ESC to Exit" << endl;

	unsigned int option = optionHandler(1, 3);

	switch (option) {
	case 1:
		do {
			clearScreen();
			contestantMenu();
		} while (!std::cin.eof());
		cin.clear();
		break;
	case 2: do {
		clearScreen();
		judgeMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 3: do {
		clearScreen();
		auditionMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
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

void CompanyMS::showApplicationsMenu() {
	vector<Application* > applications = company->getApplications();
	Contestant * contestant;
	for (size_t i = 0; i < applications.size(); i++) {
		cout << "Candidature sent at " << applications[i]->date << " by:" << endl;
		contestant = company->getContestantById(applications[i]->contestantId);
		cout << *contestant << endl;
	}
}

bool CompanyMS::isValidOption(string option, unsigned int infLim, unsigned int supLim) {
	removeSpaces(option);
	if (option.length() == 0) throw EmptyOption();
	for (size_t i = 0; i < option.length(); i++)
	{
		if (!isdigit(option.at(i))) throw InvalidOption();
	}
	unsigned int op = stoi(option);
	if (op < infLim || op > supLim)
		throw OptionOutOfRange();
	return true;
}
void CompanyMS::clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	cout << string(40, '\n');
#endif
}

unsigned int CompanyMS::optionHandler(unsigned int infLim, unsigned int supLim) {
	string op;
	bool valid = false;


	while (!valid) {
		cout << "Option:";
		getline(cin, op);
		try {
			valid = isValidOption(op, 1, 3);
		}
		catch (EmptyOption)
		{
			valid = false;
			cout << "Your option was empty. Note that it has to be a number between " << infLim << " and "<< supLim <<". Please retry to enter it." << endl;
		}
		catch (InvalidOption)
		{
			valid = false;
			cout << "Your option has invalid characters. Note that it has to be a number between " << infLim << " and " << supLim << ". Please retry to enter it." << endl;
		}
		catch (OptionOutOfRange)
		{
			valid = false;
			cout << "Your option was out of range. Note that it has to be a number between " << infLim << " and " << supLim << ". Please retry to enter it." << endl;
		}
	}
	return stoi(op);
}