
#define _CRT_SECURE_NO_WARNINGS
#include "CompanyMS.h"
#include "Util.h"
#include "ExceptionHand.h"
#include <ctime>
#include <iostream>
#include <algorithm>
#include <wchar.h>
#include <stdio.h>
#include <string>
#include <iomanip>

Calendar CompanyMS::currentCalendar = Calendar(2017, 11, 14, 12, 0);
using namespace std;


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

	mainTitle();

	cout << "1. CONTESTANT" << endl;
	cout << "2. JUDGE" << endl;
	cout << "3. AUDITION" << endl;
	printInColour("4. SAVE\n", 6, true);

	cout << "Please Press ^Z to Exit" << endl;

	unsigned int option = optionHandler(1, 4);
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
	case 4: do {
		clearScreen();
		saveMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	}
}

void CompanyMS::saveMenu() {
	mainTitle();
	cout << "\t\t::::::::: SAVE ::::::::: \n";
	updateFilesHandler();
	if (cin.eof()) return;
	cout << "Please Press Ctrl^Z to go back to the Main Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}

void CompanyMS::contestantMenu()
{
	mainTitle();
	cout << "\t\t::::::::: CONTESTANT ::::::::: \n";

	cout << "1. Enroll a contestant" << endl;
	cout << "2. Modify the info of a contestant" << endl;
	cout << "3. Remove a contestant" << endl;
	cout << "4. Remove a contestant's applications" << endl;
	cout << "5. View contestants by id" << endl;
	cout << "6. View contestants by name" << endl;
	cout << "7. View contestants of a specialty" << endl;
	cout << "8. Search contestant by id" << endl;
	cout << "9. View all applications" << endl;
	cout << "Please Press Ctrl^Z to go back to the Main Menu" << endl;

	unsigned int option = optionHandler(1, 9);
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
		removeContestantsApplicationsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 5: do {
		clearScreen();
		showContestantsByIdMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 6: do {
		clearScreen();
		showContestantsByNameMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 7: do {
		clearScreen();
		showContestantsOfSpecialtyMenu();

	} while (!std::cin.eof());
	cin.clear();
	break;

	case 8: do {
		clearScreen();
		searchContestantByIdMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 9: do {
		clearScreen();
		showApplicationsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;

	}
}

void CompanyMS::judgeMenu() {

	mainTitle();
	cout << "\t\t::::::::: JUDGE ::::::::: \n";

	cout << "1. Employ a judge" << endl;
	cout << "2. Modify the info of a current judge" << endl;
	cout << "3. Fire a judge" << endl;
	cout << "4. View judges by id" << endl;
	cout << "5. View judges by name" << endl;
	cout << "6. View judges of specialty" << endl;
	cout << "7. Search judge by id" << endl;
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
		showJudgesByIdMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 5: do {
		clearScreen();
		showJudgesByNameMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 6: do {
		clearScreen();
		showJudgesOfSpecialtyMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 7: do {
		clearScreen();
		searchJudgeByIdMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	}
}

void CompanyMS::auditionMenu() {

	mainTitle();
	cout << "\t\t::::::::: AUDITION ::::::::: \n";

	cout << "1. Schedule an audition" << endl;
	cout << "2. Schedule the maximum number of auditions possible at the moment" << endl;
	cout << "3. Schedule the maximum number of auditions possible at the moment of a specialty" << endl;
	cout << "4. Disassemble an audition" << endl;
	cout << "5. Evaluate an audition" << endl;
	cout << "6. Evaluate all auditions" << endl;
	cout << "7. View all auditions" << endl;
	cout << "Please Press Ctrl^Z to go back to the Main Menu" << endl;

	unsigned int option = optionHandler(1, 7);
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
		scheduleMaxAuditionsOfSpecialtyMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 4: do {
		clearScreen();
		disassembleAuditionMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 5: do {
		clearScreen();
		evaluateAuditionMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 6: do {
		clearScreen();
		evaluateAllAuditionsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	case 7: do {
		clearScreen();
		showAuditionsMenu();
	} while (!std::cin.eof());
	cin.clear();
	break;
	}
}

void CompanyMS::enrollAContestantMenu() {
	mainTitle();
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
		updateFilesHandler();
		if (cin.eof()) return;
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
					updateFilesHandler();
					if (cin.eof()) return;
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
	mainTitle();
	cout << "\t\t::::::::: MODIFY A CONTESTANT ::::::::: \n";

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
				cout << "It looks like the contestant you specified IS already in our database. Please insert different data.";
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
	mainTitle();
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
void CompanyMS::showContestantsByIdMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW CONTESTESTANTS BY ID ::::::::: \n";
	bool answer;
	cout << "Would you like to see the total list of contestants? " << endl;
	answer = yesNoHandler();
	unsigned int aux;
	if (cin.eof()) return;
	if (answer)
		showContestants();
	else {
		cout << "Please insert the id of the first contestant you would like to see." << endl;
		unsigned int first_id = contestantIdHandler();
		if (cin.eof()) return;
		cout << "Please insert the id of the last contestant you would like to see." << endl;
		unsigned int last_id = contestantIdHandler();
		if (cin.eof()) return;
		if (first_id > last_id) {
			aux = first_id;
			first_id = last_id;
			last_id = aux;
		}
		showPartialContestants(first_id, last_id);
	}

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showContestantsByNameMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW CONTESTESTANTS BY NAME ::::::::: \n";
	bool answer;

	showContestantsByName();
	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showContestantsOfSpecialtyMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW CONTESTESTANTS OF SPECIALTY ::::::::: \n";

	cout << "Please insert the specialty you would like to see contestants of." << endl;
	string specialty = specialtyHandler();

	cout << "Contestants:" << endl;
	vector<Contestant*> contestants;
	company->getContestantsOfSpecialty(specialty, contestants);
	for (int i = 0; i < contestants.size(); i++) {
		contestants[i]->show();
		cout << endl;
	}


	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::removeContestantsApplicationsMenu() {
	mainTitle();
	cout << "\t\t::::::::: REMOVE CONTESTANT'S APPLICATIONS ::::::::: \n";

	cout << "Please insert the id of the contestant you would like remove applications from." << endl;
	unsigned int id = contestantIdHandler();
	Contestant * contestant = company->getContestantById(id);

	company->removeApplicationsOfContestant(contestant);
	cout << "The applications have been successfully removed!";

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showApplicationsMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW APPLICATIONS ::::::::: \n";
	vector<Application* > applications = company->getApplications();
	Contestant * contestant;
	for (size_t i = 0; i < applications.size(); i++) {
		cout << "Candidature sent at " << applications[i]->getDate() << " by:" << endl;
		contestant = company->getContestantById(applications[i]->getContestantId());
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
	mainTitle();
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
	mainTitle();
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
	mainTitle();
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
	mainTitle();
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
	cout << "Please Press Ctrl^Z to go back to the Judges' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showJudgesByIdMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW JUDGES ::::::::: \n";

	bool answer;
	cout << "Would you like to see the total list of judges? " << endl;
	answer = yesNoHandler();
	unsigned int aux;
	if (cin.eof()) return;
	if (answer)
		showJudges();
	else {
		cout << "Please insert the id of the first judge you would like to see." << endl;
		unsigned int first_id = judgeIdHandler();
		if (cin.eof()) return;
		cout << "Please insert the id of the last judge you would like to see." << endl;
		unsigned int last_id = judgeIdHandler();
		if (cin.eof()) return;
		if (first_id > last_id) {
			aux = first_id;
			first_id = last_id;
			last_id = aux;
		}
		showPartialJudges(first_id, last_id);
	}
	cout << "Please Press Ctrl^Z to go back to the Judges' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}

}
void CompanyMS::showJudgesByNameMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW JUDGES BY NAME ::::::::: \n";
	bool answer;

	showJudgesByName();
	cout << "Please Press Ctrl^Z to go back to the Judges' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showJudgesOfSpecialtyMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW JUDGES OF SPECIALTY ::::::::: \n";

	cout << "Please insert the specialty you would like to see judges of." << endl;
	string specialty = specialtyHandler();

	cout << "Judges:" << endl;
	vector<Judge*> judges;
	company->getJudgesOfSpecialty(specialty, judges);
	for (int i = 0; i < judges.size(); i++) {
		judges[i]->show();
		cout << endl;
	}


	cout << "Please Press Ctrl^Z to go back to the Judges' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::searchJudgeByIdMenu() {
	mainTitle();
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
	mainTitle();
	cout << "\t\t::::::::: SCHEDULE AUDITION ::::::::: \n";

	cout << "Which is the art specialty you would like your audition to be about?";

	string specialty = specialtyHandler();
	if (cin.eof()) return;

	company->scheduleAuditionOfSpecialty(specialty);

	updateFilesHandler();
	if (cin.eof()) return;

	cout << "Please Press Ctrl^Z to go back to the Judges' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}

}
void CompanyMS::scheduleMaxAuditionsMenu() {
	mainTitle();
	cout << "\t\t::::::::: SCHEDULE MAXIMUM OF AUDITIONS ::::::::: \n";

	company->scheduleMaxAuditions();

	cout << "Your auditions have been scheduled successfuly!" << endl;

	updateFilesHandler();
	if (cin.eof()) return;

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::scheduleMaxAuditionsOfSpecialtyMenu() {
	mainTitle();
	cout << "\t\t::::::::: SCHEDULE MAXIMUM OF AUDITIONS OF SPECIALTY  ::::::::: \n";

	cout << "Which is the art specialty you would like to schedule auditions for?";
	string specialty = specialtyHandler();
	if (cin.eof()) return;

	company->scheduleMaxAuditionsOfSpecialty(specialty);

	updateFilesHandler();
	if (cin.eof()) return;

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::evaluateAuditionMenu() {
	mainTitle();
	cout << "\t\t::::::::: EVALUATE AUDITION  ::::::::: \n";

	unsigned int auditionId = auditionIdHandler();
	if (cin.eof()) return;

	company->gradeAudition(auditionId);

	updateFilesHandler();
	if (cin.eof()) return;
	cout << "Your audition has been evaluated successfuly!" << endl;

	updateFilesHandler();
	if (cin.eof()) return;

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::evaluateAllAuditionsMenu() {
	mainTitle();
	cout << "\t\t::::::::: EVALUATE ALL AUDITIONS  ::::::::: \n";

	company->gradeAllAuditions();

	cout << "All auditions have been evaluated successfuly!" << endl;
	updateFilesHandler();
	if (cin.eof()) return;

	cout << "Please Press Ctrl^Z to go back to the Auditions' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::showAuditionsMenu() {
	mainTitle();
	cout << "\t\t::::::::: VIEW AUDITIONS  ::::::::: \n";

	showAuditions();

	cout << "Please Press Ctrl^Z to go back to the Contestants' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}
void CompanyMS::disassembleAuditionMenu() {
	mainTitle();
	cout << "\t\t::::::::: DISASSEMBLE AN AUDITION ::::::::: \n";
	bool sure = false, answer;

	cout << "Would you like to see the list of auditions? " << endl;
	answer = yesNoHandler();
	if (cin.eof()) return;
	if (answer) {
		cout << "List of auditions: " << endl;
		showAuditions();
		cout << endl;
	}
	//Choose of id
	while (!sure) {
		cout << "Which auditions would you like to disassemble?" << endl;
		unsigned int id = auditionIdHandler();
		if (cin.eof()) return;
		Audition * audition = company->getAuditionById(id);
		string warning = "Are you sure you wish to remove audition No. " + to_string(id) + "?\n";
		printInColour(warning, 3, false);
		showAudition(id);
		cout << endl;
		answer = yesNoHandler();
		if (cin.eof()) return;
		if (answer)
		{
			//Removal of the contestant
			company->removeAudition(audition);
			sure = true;
			cout << "Audition No. " << id << " has been removed  successfuly!" << endl;
			updateFilesHandler();
			if (cin.eof()) return;
		}
	}
	updateFilesHandler();
	if (cin.eof()) return;
	cout << "Please Press Ctrl^Z to go back to the Auditions' Menu" << endl;
	while (!cin.eof()) {
		string option;
		getline(cin, option);
	}
}


void CompanyMS::showContestants() {
	unsigned int limInf = company->getContestants()[0]->getId();
	unsigned int limSup = company->getContestants()[company->getContestants().size() - 1]->getId();
	showPartialContestants(limInf, limSup);
}
void CompanyMS::showPartialContestants(unsigned int limInf, unsigned int limSup) {
	vector<Contestant *> contestants = company->getContestants();
	unsigned int index = 0;
	unsigned int i = limInf;
	while (contestants[index]->getId() != limInf) {
		index++;
	}

	cout << endl << endl;
	for (; contestants[index]->getId() < limSup; index++) {
		contestants[index]->show();
		cout << endl;
	}
	contestants[index]->show();
	cout << endl;
}

void CompanyMS::showContestantsByName() {
	vector<Contestant*> contestants = company->getContestants();
	sort(contestants.begin(), contestants.end(), compareByName<Contestant>);
	for (size_t i = 0; i < contestants.size(); i++) {
		contestants[i]->show();
		cout << endl;
	}
}

void CompanyMS::showApplications() {
	vector<Application *> applications = company->getApplications();
	Contestant* contestant;
	for (unsigned int i = 0; i < applications.size(); i++)
	{
		cout << "Candidature sent at " << applications[i]->getDate() << " by contestant No. " << applications[i]->getContestantId() << endl;
		contestant = company->getContestantById(applications[i]->getContestantId());
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
		cout << "Candidature sent at " << applications[i]->getDate() << " by contestant No. " << applications[i]->getContestantId() << endl;
		contestant = company->getContestantById(applications[i]->getContestantId());
		contestant->show();
		cout << endl;
	}
}

void CompanyMS::showJudges() {
	unsigned int limInf = company->getJudges()[0]->getId();
	unsigned int limSup = company->getJudges()[company->getJudges().size() - 1]->getId();
	showPartialJudges(limInf, limSup);
}
void CompanyMS::showPartialJudges(unsigned int limInf, unsigned int limSup) {
	vector<Judge*> judges = company->getJudges();
	unsigned int index = 0;
	unsigned int i = limInf;
	while (judges[index]->getId() != limInf) {
		index++;
	}

	cout << endl << endl;
	for (; judges[index]->getId() < limSup; index++) {
		judges[index]->show();
		cout << endl;
	}
	judges[index]->show();
	cout << endl;
}

void CompanyMS::showJudgesByName() {
	vector<Judge*> judges = company->getJudges();
	sort(judges.begin(), judges.end(), compareByName<Judge>);
	for (size_t i = 0; i < judges.size(); i++) {
		judges[i]->show();
		cout << endl;
	}
}

void CompanyMS::showAudition(unsigned int id) {
	Audition * audition = company->getAuditionById(id);
	//ChiefJudge
	unsigned int chiefJudgeId = audition->getChiefJudgeId();
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
	if (audition->getFirstPhase()->getJudge1().empty()) {
		vector<unsigned int> contestants = audition->getFirstPhase()->getContestants();
		cout << "-> Contestants: " << endl;
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << contestant->getId() << " " << contestant->getName() << endl;
		}
	}
	else {
		cout << " FIRST PHASE : " << endl;
		cout << "    Contestant                         " << "    ChiefJudge   " << "    Judge1     " << "   Judge2    " << "   Final Grade   " << endl;
		vector<unsigned int> contestants = audition->getFirstPhase()->getContestants();
		vector<unsigned int> chiefJudgeGrades = audition->getFirstPhase()->getChiefJudge();
		vector<unsigned int> judge1Grades = audition->getFirstPhase()->getJudge1();
		vector<unsigned int> judge2Grades = audition->getFirstPhase()->getJudge2();
		vector<double> finalGrades = audition->getFirstPhase()->getFinalGrade();
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << fixed << setw(3) << contestant->getId() << setw(25) << contestant->getName() << setw(10) << chiefJudgeGrades[i] << setw(15) << judge1Grades[i] << setw(15) << judge2Grades[i] << setw(20) << finalGrades[i] << endl;
		}
	}
	if (audition->getSecondPhase()->getJudge1().empty() && (!audition->getSecondPhase()->getContestants().empty())) {
		vector<unsigned int> contestants = audition->getSecondPhase()->getContestants();
		cout << "-> Contestants: " << endl;
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << contestant->getId() << " " << contestant->getName() << endl;
		}
	}
	else if (!audition->getSecondPhase()->getContestants().empty())
	{
		cout << " SECOND PHASE : " << endl;
		cout << "    Contestant                         " << "    ChiefJudge   " << "    Judge1     " << "   Judge2    " << "   Final Grade   " << endl;
		vector<unsigned int> contestants = audition->getSecondPhase()->getContestants();
		vector<unsigned int> chiefJudgeGrades = audition->getSecondPhase()->getChiefJudge();
		vector<unsigned int> judge1Grades = audition->getSecondPhase()->getJudge1();
		vector<unsigned int> judge2Grades = audition->getSecondPhase()->getJudge2();
		vector<double> finalGrades = audition->getSecondPhase()->getFinalGrade();
		for (size_t i = 0; i < contestants.size(); i++)
		{
			Contestant * contestant = company->getContestantById(contestants[i]);
			cout << "   :: No. " << fixed << setw(3) << contestant->getId() << setw(25) << contestant->getName() << setw(10) << chiefJudgeGrades[i] << setw(15) << judge1Grades[i] << setw(15) << judge2Grades[i] << setw(20) << finalGrades[i] << endl;
		}
	}
}
void CompanyMS::showAuditions() {
	vector<Audition*> auditions = company->getAuditions();
	for (size_t i = 0; i < auditions.size(); i++)
	{
		showAudition(auditions[i]->getId());
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
		cout << "\033[0;" << (colour + 30) << "m" << text << "\033[0m";
	else cout << "\033[1;" << (colour + 30) << "m" << text << "\033[1m";
	cout << "\033[1;" << 27 << "m\033[0m";

}
void CompanyMS::mainTitle() {
	printInColour(":::::::::::::::::::::::::::::::::::: CASTINGS TV ::::::::::::::::::::::::::::::::::: \n", 7, false);
}
