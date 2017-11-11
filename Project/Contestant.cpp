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

	//get participations

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
//Set Methods
unsigned int Contestant::getId() const { return id; }
vector<participation*> Contestant::getParticipations() const { return participations; }
//Get Methods
void Contestant::setId(unsigned int id) { this->id = id; }
void Contestant::setParticipations(vector<participation*> participations) { this->participations = participations; };

//Operator overloading
bool Contestant::operator<(const Contestant & contestant1) const {
	return (id < contestant1.id);
}

//A contestant is "equal" to another if they share the same properties (except id, of course)
bool Contestant::operator==(const Contestant & contestant1) const {
	return (name == contestant1.name &&
		address == contestant1.address &&
		mobile == contestant1.mobile &&
		dob == contestant1.dob &&
		specialty == contestant1.specialty &&
		participations == contestant1.participations);


}
ostream& operator<<(ostream& os, const Contestant& contestant) {
	os << contestant.id << " ; " << contestant.name << " ; " << contestant.mobile << " ; " << contestant.address << " ; " << contestant.dob.date() << " ; " << contestant.specialty << " ; ";
	//print participations lacking
	os << " ; ";
	return os;
}



