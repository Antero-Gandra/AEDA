/**
 * Project Untitled
 */

#include <sstream>
#include <iostream>
#include <ios>
#include "Contestant.h"
#include "Util.h"
#include <limits>

using namespace std;

//Constructors
Contestant::Contestant(string textLine) {
	const streamsize max = numeric_limits<streamsize>::max();
	istringstream contestantLine(textLine);

	unsigned int id;
	string name;
	string address;
	unsigned int mobile;
	Calendar dob;
	unsigned int year;
	unsigned int month;
	unsigned int day;
	string prtcpations;
	string prtcpation;
	vector<Participation*> participations;
	unsigned int auditionId;
	unsigned int place;
	unsigned int chiefJudgeGrade;

	//get id
	contestantLine >> id;
	contestantLine.ignore(max, ';');

	//get name
	getline(contestantLine, name, ';');
	removeSpaces(name);

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

	//get mobile
	contestantLine >> mobile;
	contestantLine.ignore(max, ';');

	//get address
	getline(contestantLine, address, ';');
	removeSpaces(address);

	//get specialty
	getline(contestantLine, specialty, ';');
	removeSpaces(specialty);

	//get participations
	getline(contestantLine, prtcpations, ';');
	removeSpaces(prtcpations);

	istringstream participationsLine;
	participationsLine.str(prtcpations);

	//Reading each participation
	getline(participationsLine, prtcpation, '.');
	istringstream participationLine(prtcpation);
	while (prtcpation != "")
	{
		participationLine >> auditionId;
		participationLine.ignore(max, ',');
		participationLine >> place;
		participationLine.ignore(max, ',');
		participationLine >> chiefJudgeGrade;

		Participation * p = new Participation(auditionId, place, chiefJudgeGrade);
		participations.push_back(p);
		getline(participationsLine, prtcpation, '.');
		istringstream participationLine(prtcpation);
	}

	//set attributes
	this->id = id;
	this->name = name;
	this->mobile = mobile;
	this->address = address;
	this->dob = dob;
	this->specialty = specialty;
	this->participations = participations;

}
Contestant::Contestant(unsigned int id, string name, string address, unsigned int mobile, Calendar dob, string specialty, std::vector<unsigned int> participation): Person(name, address, mobile, dob, specialty) {
	this->id = id;
	this->participations = participations;
}
//Set Methods
unsigned int Contestant::getId() const { return id; }
vector<Participation*> Contestant::getParticipations() const { return participations; }
//Get Methods
void Contestant::setId(unsigned int id) { this->id = id; }
void Contestant::setParticipations(vector<Participation*> participations) { this->participations = participations; };

//Operator overloading
bool Contestant::operator<(const Contestant & contestant1) const {
	return (id < contestant1.id);
}
//A contestant is "equal" to another if they share the same properties (except id and participations, of course)
bool Contestant::operator==(const Contestant & contestant1) const {
	return (name == contestant1.name &&
		address == contestant1.address &&
		mobile == contestant1.mobile &&
		dob == contestant1.dob &&
		specialty == contestant1.specialty);
}
ostream& operator<<(ostream& os, const Contestant& contestant) {

	os << contestant.getId() << " ; " << contestant.getName() << " ; " << contestant.getDob().date() << " ; "  << contestant.getMobile() << " ; " << contestant.getAddress() << " ; "  << contestant.getSpecialty() << " ; ";
	//print participations
	auto participations = contestant.getParticipations();

	for (size_t i = 0; i < participations.size(); i++)
	{
		os << participations[i]->auditionId << " , ";
		os <<participations[i]->place << " , ";
		os << participations[i]->chiefJudgeGrade << ". ";
	}
	os << " ;";
	return os;
}

//Other Methods
void Contestant::show() const {
	cout << "Contestant No. " << id << endl;
	cout << "-> Name: " << name << endl;
	cout << "-> Date of Birth: " << dob.date() << endl;
	cout << "-> Mobile: " << mobile << endl;
	cout << "-> Address: " << address << endl;
	cout << "-> Specialty: " << specialty << endl;
	cout << "-> Participations: " << endl;

	if (participations.size() == 0) cout << " NONE. ";
	for (size_t i = 0; i < participations.size(); i++)
	{cout << "    Audition No. " << participations[i]->auditionId << endl;
	cout << "    ::Place: " << participations[i]->place << endl;
	cout << "    ::Chief judges's grade: " << participations[i]->chiefJudgeGrade << endl;
	}
}



