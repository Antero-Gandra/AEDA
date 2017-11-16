
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
	if (cin.eof()) return;

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

void CompanyMS::contestantMenu()
 {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: CONTESTANT ::::::::: \n";

	cout << "1. Enroll a contestant" << endl;
	cout << "2. Modify the info of a contestant" << endl;
	cout << "3. Remove a contestant" << endl;
	cout << "4. Read contestants from a file" << endl;
	cout << "5. View all contestants" << endl;
	cout << "6. Remove a contestant's applicatons" << endl;
	cout << "7. Read applications from a file" << endl;
	cout << "8. View all applications" << endl;
	cout << "Please Press Ctrl^Z to Exit" << endl;

	unsigned int option = optionHandler(1, 8);
	if (cin.eof()) return;

	switch (option) {
	case 1:
		do {
			clearScreen();
			enrollAContestantMenu();
		} while (!std::cin.eof());
		cin.clear();
		break;
	case 2: do {
		clearScreen();
		modifyContestantInfoMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 3: do {
		clearScreen();
		removeContestantMenu();
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
		showContestantsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 6: do {
		clearScreen();
		
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 7: do {
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
	cout << "4. Read judges from a file" << endl;
	cout << "5. View all judges" << endl;
	cout << "Please Press Ctrl^Z to go back to the Main Menu" << endl;

	unsigned int option = optionHandler(1, 5);
	if (cin.eof()) return;

	switch (option) {
	case 1:
		do {
			clearScreen();
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
		showJudgesMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	}
}

void CompanyMS::auditionMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: AUDITION ::::::::: \n";

	cout << "1. Schedule an audition" << endl;
	cout << "2. Schedule auditions for all contestants (if possible) " << endl;
	cout << "2. Modify an audition" << endl;
	cout << "3. Disassemble an audition" << endl;
	cout << "4. View all auditions" << endl;

	unsigned int option = optionHandler(1, 4);
	if (cin.eof()) return;

	switch (option) {
	case 1:
		do {
			clearScreen();
			scheduleAuditionMenu();
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
	}
}

void CompanyMS::enrollAContestantMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: ENROLL A CONTESTANT ::::::::: \n";

	cout << "First things first, is the candidate you want to enroll already in our database? (y/n)";

	bool answer = yesNoHandler();
	if (cin.eof()) return;

	if (answer)
	{
		cout << "Available contestants: " << endl;
		showContestants();
		unsigned int Id = idHandler();
		if (cin.eof()) return;
		company->addApplication(currentTime, Id);
	}
	else {
		Contestant * contestant = NULL;
		bool repeated = true;
		while (repeated) {
			cout << "Please insert the candidate's name." << endl;
			string name = stringHandler("name");
			if (cin.eof()) return;
			cout << "Please insert the candidate's date of birth." << endl;
			Time dob = dobHandler();
			if (cin.eof()) return;
			cout << "Please insert the candidate's mobile." << endl;
			unsigned int mobile = numberHandler("mobile");
			if (cin.eof()) return;
			cout << "Please insert the candidate's address." << endl;
			string address = stringHandler("address");
			if (cin.eof()) return;
			cout << "Please insert the candidate's specialty." << endl;
			string specialty = specialtyHandler();
			if (cin.eof()) return;

			contestant = new Contestant(0, name, address, mobile, dob, specialty, {});
			unsigned int i = 0;
			try {
				i = company->getContestantByInfo(contestant);
			}
			catch (ContestantInfoNotFound)
			{
				repeated = false;
				company->addContestant(contestant);
				company->addApplication(currentTime, company->getContestantByInfo(contestant));
			}
			if (i != 0) {
				cout << "Ooops! It looks like the contestant you specified IS already in our database." << endl;
				cout << "Do you still want to add an application? (y/n)";
				bool answer = yesNoHandler();
				if (cin.eof()) return;
				if (answer)
				{
					company->addApplication(currentTime, i);
					repeated = false;
				}

			}
		}
	}
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::modifyContestantInfoMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: MODIFY A CONTESTANT ::::::::: \n";
	bool repeated = true, answer;

	//Choose of id
	cout << "List of contestants: " << endl;
	showContestants();
	cout << endl;
	cout << "Which contestant would you like to modify?" << endl;
	unsigned int id = idHandler();
	if (cin.eof()) return;

	Contestant * contestant = company->getContestantById(id);


	while (repeated) {
		//show contestant
		cout << endl;
		contestant->show();
		cout << endl;

		//name
		cout << "Would you like to modify the contestant's name? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		string name;
		if (answer)
		{
			cout << "Please insert the contestant's new name. " << endl;
			name = stringHandler("name");
			if (cin.eof()) return;
		}
		else {
			name = contestant->getName();
		}
		//dob
		cout << "Would you like to modify the contestant's dob? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		Time dob;
		if (answer)
		{
			cout << "Please insert the contestant's new dob. " << endl;
			dob = dobHandler();
			if (cin.eof()) return;
		}
		else {
			dob = contestant->getDob();
		}

		//mobile
		cout << "Would you like to modify the contestant's mobile? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		unsigned int mobile;
		if (answer)
		{
			cout << "Please insert the contestant's new mobile. " << endl;
			mobile = numberHandler("mobile");
			if (cin.eof()) return;
		}
		else {
			mobile = contestant->getMobile();
		}

		//address
		cout << "Would you like to modify the contestant's address? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		string address;
		if (answer)
		{
			cout << "Please insert the contestant's new address.";
			address = stringHandler("address");
			if (cin.eof()) return;
		}
		else {
			address = contestant->getAddress();
		}
		//specialty
		cout << "Would you like to modify the contestant's specialty? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		string specialty;
		if (answer)
		{
			cout << "Please insert the contestant's new specialty.";
			specialty = specialtyHandler();
			if (cin.eof()) return;
		}
		else {
			specialty = contestant->getSpecialty();
		}
		Contestant * aux = new Contestant(id, name, address, mobile, dob, specialty, {});
		unsigned int i = 0;
		try {
			i = company->getContestantByInfo(aux);
		}
		catch (ContestantInfoNotFound)
		{
			repeated = false;
			company->updateContestant(contestant, aux);
		}
		if (i != 0) {
			cout << "Ooops! It looks like the contestant you specified IS already in our database." << endl;
			cout << "Please insert different data.";
		}
	}
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::removeContestantMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: REMOVE A CONTESTANT ::::::::: \n";
	bool sure = false, answer;

	//Choose of id
	cout << "List of contestants: " << endl;
	showContestants();
	cout << endl;
	while (!sure) {
		cout << "Which contestant would you like to remove?" << endl;
		unsigned int id = idHandler();
		if (cin.eof()) return;
		Contestant * contestant = company->getContestantById(id);
		cout << "Are you sure you wish to remove contestant No." << id << "? ";
		answer = yesNoHandler();
		if (cin.eof()) return;
		if (answer)
		{
			//Removal of the contestant
			company->removeContestant(contestant);
			company->removeApplicationsOfContestant(contestant);
			sure = true;
		}
	}
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showContestantsMenu() {
	showContestants();
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
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
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}

void CompanyMS::showJudgesMenu() {
	company->showJudges();
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}

void CompanyMS::scheduleAuditionMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: SCHEDULE AUDITION ::::::::: \n";

	cout << "Which is the art specialty you would like your audition to be about?";

	string specialty = specialtyHandler();
	if (cin.eof()) return;

	showApplicationsOfSpecialty(specialty);
	
	//Choosing candidates
	int a; cin >> a;
	
}


void CompanyMS::showContestants() {
	vector<Contestant *> contestants = company->getContestants();
	unsigned int i = 0;
	cout << endl << endl;
	for (; i < contestants.size(); i++) {
		contestants[i]->show();
		cout << endl << endl;
	}
}
void CompanyMS::showApplications() {
	vector<Application *> applications = company->getApplications();
	Contestant* contestant;
	for (unsigned int i = 0; i < applications.size(); i++)
	{
		cout << "Candidature sent at " << applications[i]->date << " by contestant No. " << applications[i]->contestantId << endl;
		contestant = company->getContestantById(applications[i]->contestantId);
		contestant->show();
			cout << endl;
	}
}
void CompanyMS::showApplicationsOfSpecialty(string specialty) {
	vector<Application*> applications = company->getApplicationsOfSpecialty(specialty);
	Contestant* contestant;
	for (unsigned int i = 0; i < applications.size(); i++)
	{
		cout << "Candidature sent at " << applications[i]->date << " by contestant No. " << applications[i]->contestantId << endl;
		contestant = company->getContestantById(applications[i]->contestantId);
		contestant->show();
		cout << endl;
	}
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
	if (cin.eof()) {
		return false;
	}
	removeSpaces(id);

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
bool CompanyMS::isValidString(string s) {
	if (cin.eof()) {
		return false;
	}
	removeSpaces(s);

	if (s.length() == 0) throw EmptyAnswer();

	return true;
}
bool CompanyMS::isValidDob(Time dob) {
	return dob.isValidDate();
}
bool CompanyMS::isValidNumber(string number) {
	for (size_t i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
			throw NotANumber();
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
bool CompanyMS::yesNoHandler() {
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
unsigned int CompanyMS::idHandler() {
	string id;
	bool valid = false;

	while (!valid) {
		cout << "Id:";
		getline(cin, id);
		if (cin.eof()) return 0;
		try {
			valid = isValidId(id);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to be the ID (a number) of one of the contestants' showed. Please retry to enter it." << endl;
		}
		catch (InvalidId) {
			valid = false;
			cout << "Your answer has invalid characters. Note that it has to be the ID (a number) of one of the contestants' showed. Please retry to enter it." << endl;
		}
		catch (ContestantIdNotFound) {
			valid = false;
			cout << "It looks like the id you entered is not on our database. Note that it has to be the ID (a number) of one of the contestants' showed. Please retry to enter it." << endl;
		}
	}
	return stoi(id);
}
string CompanyMS::stringHandler(string type) {
	string s;
	bool valid = false;

	while (!valid) {
		cout << type << ":";
		getline(cin, s);
		if (cin.eof()) return "";
		try {
			valid = isValidString(s);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to have at least one character. Please retry to enter it." << endl;
		}
	}
	return s;
}
Time CompanyMS::dobHandler() {
	bool valid = false;
	string number;
	unsigned int day, month, year;
	while (!valid) {
		//year
		while (!valid) {
			cout << "year:";
			getline(cin, number);
			if (cin.eof()) return Time();
			try {
				valid = isValidNumber(number);
			}
			catch (EmptyAnswer)
			{
				valid = false;
				cout << "Your answer was empty. Note that it has to a number. Please retry to enter it." << endl;
			}
			catch (NotANumber)
			{
				valid = false;
				cout << "Your answer has invalid characters. Note that it has to a number. Please retry to enter it." << endl;
			}
			if (cin.eof()) return Time();
		}
		year = stoi(number);
		valid = false;

		//month
		while (!valid) {
			cout << "month:";
			getline(cin, number);
			if (cin.eof()) return Time();
			try {
				valid = isValidNumber(number);
			}
			catch (EmptyAnswer)
			{
				valid = false;
				cout << "Your answer was empty. Note that it has to be a number. Please retry to enter it." << endl;
			}
			catch (NotANumber)
			{
				valid = false;
				cout << "Your answer has invalid characters. Note that it has to a number. Please retry to enter it." << endl;
			}
			if (cin.eof()) return Time();
		}
		month = stoi(number);
		valid = false;


		//day
		while (!valid) {
			cout << "day:";
			getline(cin, number);
			if (cin.eof()) return Time();
			try {
				valid = isValidNumber(number);
			}
			catch (EmptyAnswer)
			{
				valid = false;
				cout << "Your answer was empty. Note that it has to a number. Please retry to enter it." << endl;
			}
			catch (NotANumber)
			{
				valid = false;
				cout << "Your answer has invalid characters. Note that it has to a number. Please retry to enter it." << endl;
			}
			if (cin.eof()) return Time();
		}
		day = stoi(number);
		valid = isValidDob(Time(year, month, day, 0, 0));
		if (!valid)
			cout << "Your answer is not a valid date. Not that is has to a be a valid calendar date. Please retry to enter it." << endl;
	}
	return Time(year, month, day, 0, 0);
}
string CompanyMS::specialtyHandler() {
	bool valid = false;
	string specialty;

	while (!valid) {
		cout << "specialty:";
		getline(cin, specialty);
		if (cin.eof()) return "";
		try {
			valid = isValidString(specialty);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to have characters and be one the specialties presented. Please retry to enter it." << endl;
		}

		try {
			valid = company->hasSpecialty(specialty);
		}
		catch (SpecialtyNotAvailable)
		{
			valid = false;
			cout << "It looks like the id you entered is not on our database. Note that it has to be the ID (a number) of one of the contestants' showed. Please retry to enter it." << endl;
		}
	}
	return specialty;
}
unsigned int CompanyMS::numberHandler(string type) {
	string number;
	bool valid = false;;
	while (!valid) {
		cout << type << ":";
		getline(cin, number);
		try {
			valid = isValidNumber(number);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to a number. Please retry to enter it." << endl;
		}
		catch (NotANumber)
		{
			valid = false;
			cout << "Your answer has invalid characters. Note that it has to a number. Please retry to enter it." << endl;
		}
		if (cin.eof()) return false;
	}
	return stoi(number);
}