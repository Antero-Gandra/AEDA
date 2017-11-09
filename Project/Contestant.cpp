/**
 * Project Untitled
 */

#include <sstream>
#include <iostream>
#include "Contestant.h"
#include "Util.h"

const std::streamsize max = std::numeric_limits<std::streamsize>::max();
//Constructors
Contestant::Contestant(string textLine) {
	istringstream contestantLine;
	contestantLine.str(textLine);

	unsigned int id;
	string name;
	string address;
	unsigned int mobile;
	Time dob;
	unsigned int year;
	unsigned int month;
	unsigned int day;

	string specialty;
	vector<participation*> participations;

	//get id
	contestantLine >> id;
	contestantLine.ignore(max, ';');

	//get name
	getline(contestantLine, name, ';');
	removeSpaces(name);

	//get mobile
	contestantLine >> mobile;
	contestantLine.ignore(max, ';');

	//get address
	getline(contestantLine, address, ';');
	removeSpaces(address);

	//get dob
	contestantLine >> year;
	contestantLine.ignore(max, '/');
	contestantLine >> month;
	contestantLine.ignore(max, '/');
	contestantLine >> day;
	contestantLine.ignore(max, ';');
	dob.setYear(year);
	dob.setMonth(month);
	dob.setDay(day);

	//get specialty
	getline(contestantLine, specialty, ';');

	//set attributes
	this->id = id;
	this->name = name;
	this->mobile = mobile;
	this->address = address;
	this->dob = dob;
	this->specialty = specialty;
	this->participations = participations;

}

Contestant::Contestant(unsigned int id, string name, string address, unsigned int mobile, Time dob, string specialty, std::vector<unsigned int> participation): Person(name, address, mobile, dob, specialty) {
	this->id = id;
	this->participations = participations;
}


//Operator overloading
bool Contestant::operator<(Contestant & contestant1) {
	return (id < contestant1.id);
}
bool Contestant::operator==(Contestant & contestant1) {
	return 0;
}

