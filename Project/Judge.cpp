#include <sstream>
#include <iostream>
#include "Judge.h"
#include "Util.h"

const std::streamsize max = std::numeric_limits<std::streamsize>::max();

Judge::Judge(unsigned int id, string name, string address, unsigned int mobile, Time dob, string specialty, std::vector<unsigned int> participations) : Person(name, address, mobile, dob, specialty) {
	this->id;
	this->participations = participations;
}
Judge::Judge(string textline) {
	istringstream judgeLine;
	judgeLine.str(textline);

	unsigned int id;
	string name;
	string address;
	unsigned int mobile;
	Time dob;
	unsigned int year;
	unsigned int month;
	unsigned int day;

	string specialty;
	vector<unsigned int> participations;

	//get id
	judgeLine >> id;
	judgeLine.ignore(max, ';');

	//get name
	getline(judgeLine, name, ';');
	removeSpaces(name);

	//get mobile
	judgeLine >> mobile;
	judgeLine.ignore(max, ';');

	//get address
	getline(judgeLine, address, ';');
	removeSpaces(address);

	//get dob
	judgeLine >> year;
	judgeLine.ignore(max, '/');
	judgeLine >> month;
	judgeLine.ignore(max, '/');
	judgeLine >> day;
	judgeLine.ignore(max, ';');
	dob.setYear(year);
	dob.setMonth(month);
	dob.setDay(day);

	//get specialty
	getline(judgeLine, specialty, ';');

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

//Set Methods
unsigned int Judge::getId() const {return id;}
vector<unsigned int> Judge::getParticipation() const { return participations; }


//Get Methods
void Judge::setId(unsigned int id){this->id=id;}
void Judge::setParticipation(vector<unsigned int> participations) { this->participations = participations;};

//Operator Overloading
bool Judge::operator<(const Judge & judge1) const  {
	return id < judge1.id;
}
//A judge is "equal" to another if they share the same properties (except id, of course)
bool Judge::operator==(const Judge & judge1) const {
	return (name == judge1.name &&
		address == judge1.address &&
		mobile == judge1.mobile &&
		dob == judge1.dob &&
		specialty == judge1.specialty &&
		participations == judge1.participations);
}
ostream& operator<<(ostream& os, const Judge& judge) {
	os << judge.id << " ; " << judge.name << " ; " << judge.mobile << " ; " << judge.address << " ; " << judge.dob.date() << " ; " << judge.specialty << " ; ";
	unsigned int i = 0;
	for (; i < judge.participations.size() -1; i++) {
		os << judge.participations[i] << ", ";
	}
	os << judge.participations[i] << ";";
	return os;
}