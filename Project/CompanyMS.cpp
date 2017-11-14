/**
 * Project Untitled
 */


#define _CRT_SECURE_NO_WARNINGS
#include "CompanyMS.h"
#include "Company.h"
#include "Time.h"
#include "Util.h"
#include "ExceptionHand.h"
#include <iostream>
#include <time.h>
#include <stdio.h>


Time CompanyMS::currentTime = Time(2017, 11, 14, 12, 0);

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
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	currentTime.setYear(now->tm_year + 1900);
	currentTime.setMonth(now->tm_mon + 1);
	currentTime.setDay(now->tm_mday + 1);
	currentTime.setHour(now->tm_hour);
	currentTime.setMinute(now->tm_min);
	
	company->readContestantsFile("contestants");
	company->readApplicationsFile("applications");
	company->readJudgesFile("judges");
	do
	{
		clearScreen();
		mainMenu(); //invokes the menu displayer
	} while (!std::cin.eof());
	cin.clear();
	company->writeContestantsFile("contestants");
	company->writeApplicationsFile("applications");
	company->writeJudgesFile("judges");
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
	cout << "2. Modify the info of a contestant" << endl;
	cout << "3. Remove a contestant applicaton" << endl;
	cout << "4. Remove a contestant" << endl;
	cout << "5. Read applications from a file" << endl;
	cout << "6. Read contestants from a file" << endl;
	cout << "7. Show all contestants" << endl;
	cout << "8. Show all applications" << endl;
	cout << "Please Press Ctrl^Z to Exit" << endl;

	unsigned int option = optionHandler(1, 8);
	if (cin.eof()) return;

	switch (option) {
	case 1:
		do {
			clearScreen();
			EnrollAContestantMenu();
		} while (!std::cin.eof());
		cin.clear();
		break;
	case 2: do {
		clearScreen();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 3: do {
		clearScreen();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 4: do {
		clearScreen();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 5: do {
		clearScreen();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 8: do {
		clearScreen();
		showApplicationsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	}
}

void CompanyMS::judgeMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: JUDGE ::::::::: \n";

	cout << "1. Employ a judge" << endl;
	cout << "2. Modify the info of a current judge" << endl;
	cout << "3. Fire a judge" << endl;
	cout << "4. Print current list of judges" << endl;
	cout << "Please Press Ctrl^Z to go back to the Main Menu" << endl;

	unsigned int option = optionHandler(1, 4);
	if (cin.eof()) return;
}

void CompanyMS::auditionMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: AUDITION ::::::::: \n";

	cout << "1. Create a new specific audition" << endl;
	cout << "2. Modify a current audition" << endl;
	cout << "3. Disassemble an audition" << endl;
	cout << "4. Print current list of auditions" << endl;

	unsigned int option = optionHandler(1, 4);
	if (cin.eof()) return;
}

void CompanyMS::EnrollAContestantMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: ENROLL A CONTESTANT ::::::::: \n";

	cout << "First things first, is the candidate you want to enroll already in our database? (y/n)";

	bool answer = YesNoHandler();

	if (answer)
	{
		cout << "Available contestants: " << endl;
		company->showContestants();
	}
	
	unsigned int Id = IdHandler();
	if (cin.eof()) return;
	company->addApplication(currentTime, Id);

}

void CompanyMS::showApplicationsMenu() {
	vector<Application* > applications = company->getApplications();
	Contestant * contestant;
	for (size_t i = 0; i < applications.size(); i++) {
		cout << "Candidature sent at " << applications[i]->date << " by:" << endl;
		contestant = company->getContestantById(applications[i]->contestantId);
		contestant->show();
		cout << endl;
	}
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	unsigned int option = optionHandler(1, 4);
	if (cin.eof()) return;
}

bool CompanyMS::isValidOption(string option, unsigned int infLim, unsigned int supLim) {
	removeSpaces(option);
	if (cin.eof()) {
		return false;
	}
	if (option.length() == 0) throw EmptyAnswer();
	for (size_t i = 0; i < option.length(); i++)
	{
		if (!isdigit(option.at(i))) throw InvalidOption();
	}
	unsigned int op = stoi(option);
	if (op < infLim || op > supLim)
		throw OptionOutOfRange();
	return true;
}
bool CompanyMS::isYesOrNo(string answer) {
	removeSpaces(answer);
	if (cin.eof()) {
		return false;
	}
	if (answer.length() == 0) throw EmptyAnswer();
	
	if (answer != "y" && answer != "n" && answer != "N" && answer != "n")
		throw NotYesOrNo();
	return true;
}
bool CompanyMS::isValidId(string id) {
	removeSpaces(id);
	if (cin.eof()) {
		return false;
	}
	if (id.length() == 0) throw EmptyAnswer();

	for (size_t i = 0; i < id.length(); i++)
	{
		if (!isdigit(id[i]))
			throw InvalidId();
	}
	unsigned int Id = stoi(id);
	try {
		company->getContestantById(Id);
	}
	catch (ContestantIdNotFound) {
		throw ContestantIdNotFound(Id);
	}
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
			valid = isValidOption(op, infLim, supLim);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your option was empty. Note that it has to be a number between " << infLim << " and " << supLim << ". Please retry to enter it." << endl;
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
		if (cin.eof()) return 0;
	}
	return stoi(op);
}
bool CompanyMS::YesNoHandler() {
	string op;
	bool valid = false;

	while (!valid) {
		cout << "Answer:";
		getline(cin, op);
		try {
			valid = isYesOrNo(op);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to be one of the following: 'y', 'Y', 'n', 'N' . Please retry to enter it." << endl;
		}
		catch (NotYesOrNo) {
			valid = false;
			cout << "Your answer was invalid. Note that it has to be one of the following: 'y', 'Y', 'n', 'N' . Please retry to enter it." << endl;
		}
		
		if (cin.eof()) return false;
	}
	removeSpaces(op);
	if (op == "y" || op == "Y") return true;
	return false;
}
unsigned int CompanyMS::IdHandler() {
	string id;
	bool valid = false;

	while (!valid) {
		cout << "Id:";
		getline(cin, id);
		try {
			valid = isValidId(id);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to be the ID (a number) of one of the contestants' showed. . Please retry to enter it." << endl;
		}
		catch (InvalidId) {
			valid = false;
			cout << "Your answer has invalid characters. Note that it has to be the ID (a number) of one of the contestants' showed. . Please retry to enter it." << endl;
		}
		catch (ContestantIdNotFound) {
			valid = false;
			cout << "It looks like the id you entered is not on our database. Note that it has to be the ID (a number) of one of the contestants' showed. . Please retry to enter it." << endl;
		}
		if (cin.eof()) return false;
	}
	return stoi(id);
}