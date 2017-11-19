#include <sstream>
#include <iostream>
#include "Judge.h"
#include "Util.h"
#include <limits>

using namespace std;


Judge::Judge(unsigned int id, string name, string address, unsigned int mobile, Calendar dob, string specialty, std::vector<unsigned int> participations) : Person(name, address, mobile, dob, specialty) {
	this->id = id;
	this->participations = participations;
}
Judge::Judge(string textline) {

	const streamsize max = numeric_limits<streamsize>::max();

	istringstream judgeLine;
	judgeLine.str(textline);

	unsigned int id;
	string name;
	string address;
	unsigned int mobile;
	Calendar dob;
	unsigned int year;
	unsigned int month;
	unsigned int day;
	string prtcpations;
	unsigned int auditionId;
	string aud_id;
	string specialty;
	vector<unsigned int> pt;

	//get id
	judgeLine >> id;
judgeLine.ignore(max, ';');

//get name
getline(judgeLine, name, ';');
removeSpaces(name);

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

//get mobile
judgeLine >> mobile;
judgeLine.ignore(max, ';');

//get address
getline(judgeLine, address, ';');
removeSpaces(address);

//get specialty
getline(judgeLine, specialty, ';');
removeSpaces(specialty);

//get participations
getline(judgeLine, prtcpations, ';');
istringstream participationsLine(prtcpations);
getline(participationsLine, aud_id, ',');
removeSpaces(aud_id);

while (aud_id != "")
{
	auditionId = stoi(aud_id);
	pt.push_back(auditionId);
	getline(participationsLine, aud_id, ',');
	removeSpaces(aud_id);
}
//set attributes
this->id = id;
this->name = name;
this->mobile = mobile;
this->address = address;
this->dob = dob;
this->specialty = specialty;
this->participations = pt;

}

//Set Methods
unsigned int Judge::getId() const { return id; }
vector<unsigned int> Judge::getParticipations() const { return participations; }


//Get Methods
void Judge::setId(unsigned int id) { this->id = id; }
void Judge::setParticipations(vector<unsigned int> participations) { this->participations = participations; };

//Operator Overloading
bool Judge::operator<(const Judge & judge1) const {
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
	os << judge.getId() << " ; " << judge.getName() << " ; " << judge.getDob().date() << " ; " << judge.getMobile() << " ; " << judge.getAddress() << " ; " << judge.getSpecialty() << " ; ";
	//participations
	auto participations = judge.getParticipations();
	if (participations.size() > 0) {
		unsigned int i = 0;
		for (; i < participations.size(); i++) {
			os << participations[i] << ", ";
		}
	}
	os << " ;";
	return os;
}

//Other Methods
void Judge::show() {
	if (id != 0) {
		cout << "Judge No. " << id << endl;
	}
	cout << "-> Name: " << name << endl;
	cout << "-> Date of Birth: " << dob.date() << endl;
	cout << "-> Mobile: " << mobile << endl;
	cout << "-> Address: " << address << endl;
	cout << "-> Specialty: " << specialty << endl;
	cout << "-> Participations: " << endl;

	if (participations.size() == 0) {
		cout << " NONE. " << endl; return;
	}
	cout << "Auditions No. "; 
	size_t i = 0;
	for (; i < participations.size()-1; i++)
	{
		cout << participations[i] << ", ";
	}
	cout << participations[i] << "." << endl;
}
