/**
 * Project Untitled
 */

#include <sstream>
#include "Contestant.h"

<<<<<<< HEAD
Contestant::Contestant(string textLine) {
	istringstream contestantLine;
	contestantLine.str(textLine);

	unsigned int id;
	string name;
	string address;
	unsigned int mobile;
	unsigned int dob;
	string specialty;
	vector<participation*> participations;

	//get id
	contestantLine >> id;
	fileDriver.ignore(max, ';');

	//get name
	std::getline(fileDriver, name, ';');
	testReadingFail(fileDriver);
	eliminateSpaces(name);

	//get maxHours
	fileDriver >> maxHours;
	testReadingFail(fileDriver);
	fileDriver.ignore(max, ';');
	this->maxHours = Time(maxHours, 0);

	//get maxWeekWorkingTime
	fileDriver >> maxWeekWorkingTime;
	testReadingFail(fileDriver);
	fileDriver.ignore(max, ';');
	this->maxWeekWorkingTime = Time(maxWeekWorkingTime, 0);

	//get minRestTime
	fileDriver >> minRestTime;
	testReadingFail(fileDriver);
	this->minRestTime = Time(minRestTime, 0);

	//new shifts
	shifts = { {},{},{},{},{},{},{} };

	//set week working time
	weekWorkingTime = Time(maxWeekWorkingTime, 0);
=======
/**
 * Contestant implementationsssss
 */

Contestant::Contestant(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation): Person(name, address, mobile, dob, specialty), id(id), participation(participation) {

>>>>>>> 3350bd0d819b65cdbdb07909f1906bb354411f48
}
