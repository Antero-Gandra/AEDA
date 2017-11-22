
#define _CRT_SECURE_NO_WARNINGS
#include "CompanyMS.h"
#include "Util.h"
#include "ExceptionHand.h"
#include <ctime>
#include <iostream>
#include <wchar.h>
#include <stdio.h>
#include <string>
#include <iomanip>

Calendar CompanyMS::currentCalendar = Calendar(2017, 11, 14, 12, 0);
using namespace std;

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

	srand(time(NULL));

	currentCalendar.setYear(now->tm_year + 1900);
	currentCalendar.setMonth(now->tm_mon + 1);
	currentCalendar.setDay(now->tm_mday);
	currentCalendar.setHour(now->tm_hour);
	currentCalendar.setMinute(now->tm_min);

	company->readContestantsFile("contestants");
	company->readApplicationsFile("applications");
	company->readJudgesFile("judges");
	company->readAuditionsFile("auditions");
	do
	{
		clearScreen();
		mainMenu(); //invokes the menu displayer
	} while (!std::cin.eof());
	cin.clear();
	updateFilesHandler();
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
	cout << "4. Remove a contestant's applicatons" << endl;
	cout << "7. View all contestants" << endl;
	cout << "8. View all applications" << endl;
	cout << "9. View contestants of a specialty" << endl;
	cout << "10. View contestants who won castings" << endl;
	cout << "11. Search contestant by id" << endl;
	cout << "12. Search contestant by name" << endl;
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
		modifyContestantMenu();
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
		searchContestantByIdMenu();
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
		showContestantsMenu();

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
	cout << "4. View all judges" << endl;
	cout << "5. View judges of specialty" << endl;
	cout << "6. Search judge by id" << endl;
	cout << "7. Search judge by name" << endl;
	cout << "Please Press Ctrl^Z to go back to the Main Menu" << endl;

	unsigned int option = optionHandler(1, 7);
	if (cin.eof()) return;

	switch (option) {
	case 1:
		do {
			clearScreen();
			employJudgeMenu();
		} while (!std::cin.eof());
		cin.clear();
		break;
	case 2: do {
		clearScreen();
		modifyJudgeMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 3: do {
		clearScreen();
		fireJudgeMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 4: do {
		clearScreen();
		showJudgesMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 5: do {
		clearScreen();
		
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 6: do {
		clearScreen();
		searchJudgeByIdMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 7: do {
		clearScreen();
	} while (!std::cin.eof());
	cin.clear();
	break;
	}
}

void CompanyMS::auditionMenu() {

	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: AUDITION ::::::::: \n";

	cout << "1. Schedule an audition" << endl;
	cout << "2. Schedule the maximum number of auditions possible at the moment" << endl;
	cout << "3. Schedule the maximum number of auditions possible at the moment of a specialty" << endl;
	cout << "4. Modify an audition" << endl;
	cout << "5. Disassemble an audition" << endl;
	cout << "6. Evaluate first fase of an audition" << endl;
	cout << "7. Evaluate second fase of an audition" << endl;
	cout << "8. Evaluate an audition" << endl;
	cout << "9. Evaluate all auditions" << endl;
	cout << "10. View all auditions" << endl;

	unsigned int option = optionHandler(1, 10);
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
		scheduleMaxAuditionsMenu();
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
		showAuditionsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 5: do {
		clearScreen();
		showAuditionsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 6: do {
		clearScreen();
		showAuditionsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 7: do {
		clearScreen();
		showAuditionsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 8: do {
		clearScreen();
		evaluateAuditionMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 9: do {
		clearScreen();
		evaluateAllAuditions();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 10: do {
		clearScreen();
		showAuditionsMenu();
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
		cout << "Would you like to see the list of contestants? " << endl;
		answer = yesNoHandler();
		if (cin.eof()) return;
		if (answer) {
			cout << "List of contestants: " << endl;
			showContestants();
			cout << endl;
		}
		unsigned int Id = contestantIdHandler();
		if (cin.eof()) return;
		company->addApplication(currentCalendar, Id);
	}
	else {
		Contestant * contestant = NULL;
		bool repeated = true;
		while (repeated) {
			cout << "Please insert the candidate's name." << endl;
			string name = stringHandler("name");
			if (cin.eof()) return;
			cout << "Please insert the candidate's date of birth." << endl;
			Calendar dob = dobHandler();
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
				string warning = "Are you sure you wish to add this contestant? \n";
				printInColour(warning, 3, false);
				contestant->show();
				answer = yesNoHandler();
				if (answer) {
					repeated = false;
					company->addNewContestant(contestant);
					company->addApplication(currentCalendar, company->getContestantByInfo(contestant));
					cout << "Your contestant has been added and enrolled successfuly!" << endl;
					updateFilesHandler();
					if (cin.eof()) return;
				}
			}
			if (i != 0) {
				printInColour("Ooops!\n ", 3, false);
				cout << "It looks like the contestant you specified IS already in our database." << endl;
				cout << "Do you still want to add an application? (y/n)";
				bool answer = yesNoHandler();
				if (cin.eof()) return;
				if (answer)
				{
					company->addApplication(currentCalendar, i);
					repeated = false;
				}
				cout << "Your application has been added successfuly!" << endl;
				updateFilesHandler();
				if (cin.eof()) return;

			}
		}
	}
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::modifyContestantMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: MODIFY A CONTESTANT ::::::::: \n";
	printInColour("Important Notes: \n", 3, false);
	cout << "-> Changing a contestants's specialty means its applications will all be deleted from our database, but the contestants's participation records will be kept. \n" << endl;
	bool repeated = true, answer;
	bool changes = false;
	cout << "Would you like to see the list of contestants? " << endl;
	answer = yesNoHandler();
	if (cin.eof()) return;
	if (answer) {
		cout << "List of contestants: " << endl;
		showContestants();
		cout << endl;
	}
	//Choose of id
	cout << "Which contestant would you like to modify?" << endl;
	unsigned int id = contestantIdHandler();
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
			if (name != contestant->getName()) changes = true;
		}
		else {
			name = contestant->getName();
		}
		//dob
		cout << "Would you like to modify the contestant's dob? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		Calendar dob;
		if (answer)
		{
			changes = true;
			cout << "Please insert the contestant's new dob. " << endl;
			dob = dobHandler();
			if (cin.eof()) return;
			if (dob != contestant->getDob()) changes = true;
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
			if (mobile != contestant->getMobile()) changes = true;
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
			if (address != contestant->getAddress()) changes = true;
		}
		else {
			address = contestant->getAddress();
		}
	
		string specialty = contestant->getSpecialty();

		Contestant * aux = new Contestant(id, name, address, mobile, dob, specialty, {});
		unsigned int i = 0;
		if (changes) {
			try {
				i = company->getContestantByInfo(aux);
			}
			catch (ContestantInfoNotFound)
			{
				string warning = "Are you sure you wish to update contestant No. " + to_string(id) + "? \n";
				printInColour(warning, 3, false);
				printInColour("old : \n", 5, false);
				contestant->show(); cout << endl;
				printInColour("new : \n", 5, false);
				aux->show(); cout << endl;
				answer = yesNoHandler();
				if (answer)
				{
					company->updateContestant(contestant, aux);
					cout << "Contestant No. " << id << " has been updates successfuly!" << endl;
					updateFilesHandler();
				}
				else repeated = false;
			}
			if (i != 0) {
				printInColour("Ooops!\n ", 3, false);
				cout <<"It looks like the contestant you specified IS already in our database. Please insert different data.";
			}
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

	cout << "Would you like to see the list of contestants? " << endl;
	answer = yesNoHandler();
	if (cin.eof()) return;
	if (answer) {
		cout << "List of contestants: " << endl;
		showContestants();
		cout << endl;
	}
	//Choose of id
	while (!sure) {
		cout << "Which contestant would you like to remove?" << endl;
		unsigned int id = contestantIdHandler();
		if (cin.eof()) return;
		Contestant * contestant = company->getContestantById(id);
		string warning = "Are you sure you wish to remove contestant No. " + to_string(id) + "? \n";
		printInColour(warning, 3, false);
		answer = yesNoHandler();
		if (cin.eof()) return;
		if (answer)
		{
			//Removal of the contestant
			company->removeContestant(contestant);
			company->removeApplicationsOfContestant(contestant);
			sure = true;
			cout << "Contestant No. " << id << " has been removed  successfuly!" << endl;
			updateFilesHandler();
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
void CompanyMS::searchContestantByIdMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: SEARCH A CONTESTANT BY ID ::::::::: \n";

	unsigned int id = contestantIdHandler();
	if (cin.eof()) return;
	Contestant * contestant = company->getContestantById(id);
	contestant->show();
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}

}


void CompanyMS::employJudgeMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: EMPLOY A JUDGE ::::::::: \n";

	Judge * judge = NULL;
	bool repeated = true, answer;

	while (repeated) {
		cout << "Please insert the judge's name." << endl;
		string name = stringHandler("name");
		if (cin.eof()) return;
		cout << "Please insert the judges's date of birth." << endl;
		Calendar dob = dobHandler();
		if (cin.eof()) return;
		cout << "Please insert judge's mobile." << endl;
		unsigned int mobile = numberHandler("mobile");
		if (cin.eof()) return;
		cout << "Please insert the judge's address." << endl;
		string address = stringHandler("address");
		if (cin.eof()) return;
		cout << "Please insert the judge's specialty." << endl;
		string specialty = specialtyHandler();
		if (cin.eof()) return;

		judge = new Judge(0, name, address, mobile, dob, specialty, {});
		unsigned int i = 0;
		try {
			i = company->getJudgeByInfo(judge);
		}
		catch (JudgeInfoNotFound)
		{
			string warning = "Are you sure you wish to employ this judge? \n";
			printInColour(warning, 3, false);
			judge->show();
			answer = yesNoHandler();
			if (cin.eof()) return;
			if (answer) {
				repeated = false;
				company->addNewJudge(judge);
				cout << "Your judge has been addeed successfuly!" << endl;
				updateFilesHandler();
				if (cin.eof()) return;
			}
		}
		if (i != 0) {
			printInColour("Ooops!\n ", 3, false);
			cout << "It looks like the judge you specified IS already in our database. Please insert different data." << endl;

		}
	}
	cout << "Please Press Ctrl^Z to go back to the Judge's Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::modifyJudgeMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: MODIFY A JUDGE ::::::::: \n";

	bool repeated = true, answer;
	bool changes = false;
	cout << "Would you like to see the list of judges? " << endl;
	answer = yesNoHandler();
	if (cin.eof()) return;
	if (answer) {
		cout << "List of judges: " << endl;
		showJudges();
		cout << endl;
	}
	//Choose of id
	cout << "Which judge would you like to modify?" << endl;
	unsigned int id = judgeIdHandler();
	if (cin.eof()) return;

	Judge * judge = company->getJudgeById(id);


	while (repeated) {
		//show judge
		cout << endl;
		judge->show();
		cout << endl;

		//name
		cout << "Would you like to modify the judge's name? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		string name;
		if (answer)
		{
			cout << "Please insert the judge's new name. " << endl;
			name = stringHandler("name");
			if (cin.eof()) return;
			if (name != judge->getName()) changes = true;
		}
		else {
			name = judge->getName();
		}
		//dob
		cout << "Would you like to modify the judge's dob? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		Calendar dob;
		if (answer)
		{
			changes = true;
			cout << "Please insert the judge's new dob. " << endl;
			dob = dobHandler();
			if (cin.eof()) return;
			if (dob != judge->getDob()) changes = true;
		}
		else {
			dob = judge->getDob();
		}

		//mobile
		cout << "Would you like to modify the judge's mobile? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		unsigned int mobile;
		if (answer)
		{
			cout << "Please insert the judge's new mobile. " << endl;
			mobile = numberHandler("mobile");
			if (cin.eof()) return;
			if (mobile != judge->getMobile()) changes = true;
		}
		else {
			mobile = judge->getMobile();
		}

		//address
		cout << "Would you like to modify the judge's address? (y/n)";
		answer = yesNoHandler();
		if (cin.eof()) return;
		string address;
		if (answer)
		{
			cout << "Please insert the judge's new address.";
			address = stringHandler("address");
			if (cin.eof()) return;
			if (address != judge->getAddress()) changes = true;
		}
		else {
			address = judge->getAddress();
		}
		
		string specialty = judge->getSpecialty();

		Judge * aux = new Judge(id, name, address, mobile, dob, specialty, {});
		unsigned int i = 0;
		if (changes) {
			try {
				i = company->getJudgeByInfo(aux);
			}
			catch (JudgeInfoNotFound)
			{
				string warning = "Are you sure you wish to update judge No. " + to_string(id) + "? \n";
				printInColour(warning, 3, false);
				printInColour("old : \n", 5, false);
				judge->show(); cout << endl;
				printInColour("new : \n", 5, false);
				aux->show(); cout << endl;
				answer = yesNoHandler();
				if (answer)
				{
					company->updateJudge(judge, aux);
					cout << "Judge No. " << id << " has been updates successfuly!" << endl;
					updateFilesHandler();
					repeated = false;
				}
			}
			if (i != 0) {
				printInColour("Ooops!\n ", 3, false);
				cout << "It looks like the judge you specified IS already in our database. Please insert different data.";
			}
		}
	}
	cout << "Please Press Ctrl^Z to go back to the Judge's Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::fireJudgeMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: FIRE A JUDGE ::::::::: \n";
	bool sure = false, answer;

	cout << "Would you like to see the list of judges? " << endl;
	answer = yesNoHandler();
	if (cin.eof()) return;
	if (answer) {
		cout << "List of judges: " << endl;
		showJudges();
		cout << endl;
	}
	//Choose of id
	while (!sure) {
		cout << "Which judge would you like to remove?" << endl;
		unsigned int id = judgeIdHandler();
		if (cin.eof()) return;
		Judge * judge = company->getJudgeById(id);
		string warning = "Are you sure you wish to remove judge No. " + to_string(id) + "?\n";
		printInColour(warning, 3, false);
		judge->show();
		cout << endl;
		answer = yesNoHandler();
		if (cin.eof()) return;
		if (answer)
		{
			//Removal of the contestant
			company->removeJudge(judge);
			sure = true;
			cout << "Judge No. " << id << " has been removed  successfuly!" << endl;
			updateFilesHandler();
			if (cin.eof()) return;
		}
	}
	cout << "Please Press Ctrl^Z to go back to the Judge' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showJudgesMenu() {
	showJudges();
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::searchJudgeByIdMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: SEARCH A JUDGE BY ID ::::::::: \n";

	unsigned int id = judgeIdHandler();
	if (cin.eof()) return;
	Judge * judge = company->getJudgeById(id);
	judge->show();
	cout << "Please Press Ctrl^Z to go back to the Judges' Menu" << endl;
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

	//Choosing judges
	vector<Judge*> judges;

	//Choosing candidates
	unsigned int i = 0;
	unsigned int id;
	vector<Contestant*> contestants;
	cout << company->getMaxNumOfContestantsPerAudition();
	cout << "Please choose the candidates you would like to include in the audition (min = 6; max = 24)." << endl;
	cout << "If you want to stop inserting candidates, please press 0" << endl;
	while (i < company->getMaxNumOfContestantsPerAudition())
	{
		id = contestantIdHandler();
		if (cin.eof()) return;
		if (id == 0)
			if (i >= 6) break;
			else cout << "Ooops! It looks like you haven't completed yet the minimum of contestants required (6)." << endl;
			contestants.push_back(company->getContestantById(id));
	}

	cout << "You have included " << i << "contestants in the audition, which makes a total duration of ";

}
void CompanyMS::scheduleMaxAuditionsMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: SCHEDULE MAXIMUM OF AUDITIONS ::::::::: \n";

	company->scheduleMaxAuditions();

	cout << "Your auditions have been scheduled successfuly!" << endl;

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::scheduleMaxAuditionsOfSpecialtyMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: SCHEDULE MAXIMUM OF AUDITIONS OF SPECIALTY  ::::::::: \n";

	cout << "Which is the art specialty you would like to schedule auditions for?";
	string specialty = specialtyHandler();
	if (cin.eof()) return;

	company->scheduleMaxAuditionsOfSpecialty(specialty);

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::evaluateAuditionMenu() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: EVALUATE AUDITION  ::::::::: \n";

	unsigned int auditionId = auditionIdHandler();
	if (cin.eof()) return;

	company->gradeAudition(auditionId);

	cout << "Your audition has been evaluated successfuly!" << endl;


	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::evaluateFirstFaseMenu() {

}
void CompanyMS::evaluateAllAuditions() {
	cout << ":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n";
	cout << "\t\t::::::::: EVALUATE ALL AUDITION  ::::::::: \n";

	company->gradeAllAuditions();

	cout << "All auditions have been evaluated successfuly!" << endl;

	cout << "Please Press Ctrl^Z to go back to the Auditions' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showAuditionsMenu() {
	vector<Audition*> auditions = company->getAuditions();
	for (size_t i = 0; i < auditions.size(); i++)
	{
		showAudition(auditions[i]->getId());
	}
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}


void CompanyMS::showContestants() {
	vector<Contestant *> contestants = company->getContestants();
	unsigned int i = 0;
	cout << endl << endl;
	for (; i < contestants.size(); i++) {
		contestants[i]->show();
		cout << endl;
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
	vector<Application*> applications;
	company->getApplicationsOfSpecialty(specialty, applications);
	Contestant* contestant;
	for (unsigned int i = 0; i < applications.size(); i++)
	{
		cout << "Candidature sent at " << applications[i]->date << " by contestant No. " << applications[i]->contestantId << endl;
		contestant = company->getContestantById(applications[i]->contestantId);
		contestant->show();
		cout << endl;
	}
}
void CompanyMS::showJudges() {
	vector<Judge *> judges = company->getJudges();
	unsigned int i = 0;
	cout << endl << endl;
	for (; i < judges.size() - 1; i++) {
		judges[i]->show();
		cout << endl;
	}
	judges[i]->show();
}
void CompanyMS::showAudition(unsigned int id) {
	Audition * audition = company->getAuditionById(id);
	//ChiefJudge
	unsigned int chiefJudgeId= audition->getChiefJudgeId();
	string chiedJudgeName = company->getJudgeById(chiefJudgeId)->getName();
	//Judge1
	unsigned int judge1Id = audition->getJudgesId()[0];
	string judge1Name = company->getJudgeById(judge1Id)->getName();
	//Judge2
	unsigned int judge2Id = audition->getJudgesId()[1];
	string judge2Name = company->getJudgeById(judge2Id)->getName();

	//Printing info
	cout << "Audition No. " << id << endl;
	cout << "-> Specialty: " << audition->getSpecialty() << endl;
	cout << "-> Date: " << audition->getStart().date() << endl;
	cout << "   ::Begining:  " << audition->getStart().time() << endl;
	cout << "   ::Ending:  " << audition->getEnd().time() << endl;
	cout << "-> ChiefJudge: " << endl;
	cout << "   :: No. " << chiefJudgeId << " " << chiedJudgeName << endl;
	cout << "-> Other judges: " << endl;
	cout << "   :: No. " << judge1Id << " " << judge1Name << endl;
	cout << "   :: No. " << judge2Id << " " << judge2Name << endl;
	if (audition->getFirstFase()->getJudge1().empty()) {
		vector<unsigned int> contestants = audition->getFirstFase()->getContestants();
		cout << "-> Contestants: " << endl;
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << contestant->getId() << " " << contestant->getName() << endl;
		}
	}
	else {
		cout << " FIRST FASE : " << endl;
		cout << "    Contestant                         " << "    ChiefJudge   " << "    Judge1     " << "   Judge2    " << "   Final Grade   " << endl;
		vector<unsigned int> contestants = audition->getFirstFase()->getContestants();
		vector<unsigned int> chiefJudgeGrades = audition->getFirstFase()->getChiefJudge();
		vector<unsigned int> judge1Grades = audition->getFirstFase()->getJudge1();
		vector<unsigned int> judge2Grades = audition->getFirstFase()->getJudge2();
		vector<double> finalGrades = audition->getFirstFase()->getFinalGrade();
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << fixed << setw(3) << contestant->getId() << setw(25) <<  contestant->getName() << setw(10) << chiefJudgeGrades[i] << setw(15) << judge1Grades[i] << setw(15) << judge2Grades[i] << setw(20) << finalGrades[i] << endl;
		}
	}
	if (audition->getSecondFase()->getJudge1().empty() && (!audition->getSecondFase()->getContestants().empty())) {
		vector<unsigned int> contestants = audition->getSecondFase()->getContestants();
		cout << "-> Contestants: " << endl;
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << contestant->getId() << " " << contestant->getName() << endl;
		}
	}
	else if (!audition->getSecondFase()->getContestants().empty())
	{
		cout << " SECOND FASE : " << endl;
		cout << "    Contestant                         " << "    ChiefJudge   " << "    Judge1     " << "   Judge2    " << "   Final Grade   " << endl;
		vector<unsigned int> contestants = audition->getSecondFase()->getContestants();
		vector<unsigned int> chiefJudgeGrades = audition->getSecondFase()->getChiefJudge();
		vector<unsigned int> judge1Grades = audition->getSecondFase()->getJudge1();
		vector<unsigned int> judge2Grades = audition->getSecondFase()->getJudge2();
		vector<double> finalGrades = audition->getSecondFase()->getFinalGrade();
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << fixed << setw(3) << contestant->getId() << setw(25) << contestant->getName() << setw(10) << chiefJudgeGrades[i] << setw(15) << judge1Grades[i] << setw(15) << judge2Grades[i] << setw(20) << finalGrades[i] << endl;
		}
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

	if (answer != "y" && answer != "n" && answer != "N" && answer != "Y")
		throw NotYesOrNo();
	return true;
}
bool CompanyMS::isValidContestantId(string id) {
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
bool CompanyMS::isValidJudgeId(string id) {
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
		company->getJudgeById(Id);
	}
	catch (JudgeIdNotFound) {
		throw JudgeIdNotFound(Id);
	}
	return true;
}
bool CompanyMS::isValidAuditionId(string id) {
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
		company->getAuditionById(Id);
	}
	catch (AuditionIdNotFound) {
		throw AuditionIdNotFound(Id);
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
bool CompanyMS::isValidDob(Calendar dob) {
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
unsigned int CompanyMS::contestantIdHandler() {
	string id;
	bool valid = false;

	while (!valid) {
		cout << "Id:";
		getline(cin, id);
		if (cin.eof()) return 0;
		try {
			valid = isValidContestantId(id);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
		catch (InvalidId) {
			valid = false;
			cout << "Your answer has invalid characters. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
		catch (ContestantIdNotFound) {
			valid = false;
			cout << "It looks like the id you entered is not on our database. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
	}
	return stoi(id);
}
unsigned int CompanyMS::judgeIdHandler() {
	string id;
	bool valid = false;

	while (!valid) {
		cout << "Id:";
		getline(cin, id);
		if (cin.eof()) return 0;
		try {
			valid = isValidJudgeId(id);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
		catch (InvalidId) {
			valid = false;
			cout << "Your answer has invalid characters. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
		catch (JudgeIdNotFound) {
			valid = false;
			cout << "It looks like the id you entered is not on our database. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
	}
	return stoi(id);
}
unsigned int CompanyMS::auditionIdHandler() {
	string id;
	bool valid = false;

	while (!valid) {
		cout << "Id:";
		getline(cin, id);
		if (cin.eof()) return 0;
		try {
			valid = isValidAuditionId(id);
		}
		catch (EmptyAnswer)
		{
			valid = false;
			cout << "Your answer was empty. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
		catch (InvalidId) {
			valid = false;
			cout << "Your answer has invalid characters. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
		}
		catch (AuditionIdNotFound) {
			valid = false;
			cout << "It looks like the id you entered is not on our database. Note that it has to be the ID (a number) and be part of the company's database. Please retry to enter it." << endl;
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
Calendar CompanyMS::dobHandler() {
	bool valid = false;
	string number;
	unsigned int day, month, year;
	while (!valid) {
		//year
		while (!valid) {
			cout << "year:";
			getline(cin, number);
			if (cin.eof()) return Calendar();
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
			if (cin.eof()) return Calendar();
		}
		year = stoi(number);
		valid = false;

		//month
		while (!valid) {
			cout << "month:";
			getline(cin, number);
			if (cin.eof()) return Calendar();
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
			if (cin.eof()) return Calendar();
		}
		month = stoi(number);
		valid = false;


		//day
		while (!valid) {
			cout << "day:";
			getline(cin, number);
			if (cin.eof()) return Calendar();
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
			if (cin.eof()) return Calendar();
		}
		day = stoi(number);
		valid = isValidDob(Calendar(year, month, day, 0, 0));
		if (!valid)
			cout << "Your answer is not a valid date. Not that is has to a be a valid calendar date. Please retry to enter it." << endl;
	}
	return Calendar(year, month, day, 0, 0);
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
			cout << "It looks like the specialty you entered is not on our database. Please retry to enter it." << endl;
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
void CompanyMS::updateFilesHandler() {
	cout << "Would you like to update the new changes on the database files?";
	bool answer = yesNoHandler();
	if (cin.eof()) return;
	if (answer) {
		company->writeApplicationsFile("applications");
		company->writeContestantsFile("contestants");
		company->writeAuditionsFile("auditions");
		company->writeJudgesFile("judges");
	}
}

void CompanyMS::printInColour(string text, unsigned int colour, bool dark) {
	if (dark)
		cout << "\033[0;" << (colour + 30) << "m" << text << "!\033[0m";
	else cout << "\033[1;" << (colour + 30) << "m" << text << "\033[1m";
	cout << "\033[1;" << 27 << "m\033[0m";

}
