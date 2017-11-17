/**
 * Project Untitled
 */


#include "Audition.h"
#include "Util.h"
#include <sstream>
#include <limits>
#include <cstddef>

using namespace std;

Audition::Audition(unsigned int id, Calendar start, Calendar end, string specialty, vector<unsigned int> evaluatorsId, unsigned int leaderId) {
	this->id = id;
	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->evaluatorsId = evaluatorsId;
	this->leaderId = leaderId;
	this->firstFase = 0;
	this->secondFase = 0;
}
Audition::Audition(string textline) {

	istringstream auditionLine;
	auditionLine.str(textline);

	unsigned int id;
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	vector<unsigned int> ids;
	string fase1;
	string fase2;
	string specialty;

	//get id
	auditionLine >> id;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');

	//get start
	auditionLine >> year;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> month;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> day;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> hour;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> minute;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');
	Calendar start(year, month, day, hour, minute);

	//get end
	auditionLine >> year;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> month;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> day;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> hour;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '/');
	auditionLine >> minute;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');
	Calendar end(year, month, day, hour, minute);

	//get specialty
	getline(auditionLine, specialty, '|');
	removeSpaces(specialty);

	//get evaluator1 id
	auditionLine >> id;
	ids.push_back(id);

	//get evaluator2 id
	auditionLine >> id;
	ids.push_back(id);
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');

	//get leader id
	auditionLine >> id;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');

	//get Fase1
	getline(auditionLine, fase1, '|');
	FirstFase * firstFase = new FirstFase(fase1);

	//get Fase2;
	getline(auditionLine, fase2, '|');
	SecondFase * secondFase = new SecondFase(fase2);

	//setting the attributes
	this->id = id;
	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->evaluatorsId = ids;
	this->leaderId = id;
	this->firstFase = firstFase;
	this->secondFase = secondFase;

}
//get Methods
unsigned int Audition::getId() const {
	return id;
}
Calendar Audition::getStart() const {
	return start;
}
Calendar Audition::getEnd() const {
	return end;
}
string Audition::getSpecialty() const {
	return specialty;
}
vector<unsigned int> Audition::getEvaluatorsId() const {
	return evaluatorsId;
}
unsigned int Audition::getLeaderId() const {
	return leaderId;
}
FirstFase* Audition::getFirstFase() const {
	return firstFase;
}
SecondFase* Audition::getSecondFase() const {
	return secondFase;
}
//set Methods
void Audition::setId(unsigned int id) {
	this->id = id;
}
void Audition::setStart(Calendar start) {
	this->start = start;
}
void Audition::setEnd(Calendar end) {
	this->end = end;
}
void Audition::setSpecialty(string specialty) {
	this->specialty = specialty;
}
void Audition::setEvaluatorsId(vector<unsigned int> evaluators) {
	this->evaluatorsId = evaluatorsId;
}
void Audition::setLeaderId(unsigned int leaderId) {
	this->leaderId = leaderId;
}
void Audition::setFirstFase(FirstFase * firstFase) {
	this->firstFase = firstFase;
}
void Audition::setSecondFase(SecondFase *  secondFase) {
	this->secondFase = secondFase;
}

//operator Overloading
bool Audition::operator<(const  Audition & audition1) const {
	return this->id < audition1.id;
}
bool Audition::operator==(const Audition & audition1) const {
	return (this->start.getDay() == audition1.start.getDay() &&
		this->start.getMonth() == audition1.start.getMonth() &&
		this->start.getYear() == audition1.start.getYear() &&
		this->specialty == audition1.specialty);
}
ostream& operator<<(ostream& os, const Audition & audition) {
	os << audition.getId() << " | " << audition.getStart().date() << " | " << audition.getEnd().date() << " | " << audition.getEvaluatorsId()[0] << ", "  << audition.getId() << " | " << audition.getStart().date() << " | " << audition.getEnd().date() << " | " << audition.getEvaluatorsId()[0] << ", " << audition.getEvaluatorsId()[1] << " | " << audition.getLeaderId() << " | " << audition.getFirstFase() << " | " << audition.getSecondFase() << " | ";
	return os;
}
