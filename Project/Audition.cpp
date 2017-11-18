/**
 * Project Untitled
 */


#include "Audition.h"
#include "Util.h"
#include <sstream>
#include <limits>
#include <cstddef>

using namespace std;

Audition::Audition(unsigned int id, Calendar start, Calendar end, std::string specialty, std::vector<unsigned int> judgesId, unsigned int chiefJudgeId, std::vector<unsigned int> contestants) {
	this->id = id;
	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->judgesId = judgesId;
	this->chiefJudgeId = chiefJudgeId;
	this->firstFase = new FirstFase(id, {}, {}, {}, {}, contestants);
	this->secondFase = new SecondFase(id, {}, {}, {}, {}, {});
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
	this->id = id;
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
	auditionLine.ignore(numeric_limits<streamsize>::max(), ',');

	//get evaluator2 id
	auditionLine >> id;
	ids.push_back(id);
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');

	//get chiefJudge id
	auditionLine >> id;
	auditionLine.ignore(numeric_limits<streamsize>::max(), '|');

	//get Fase1
	getline(auditionLine, fase1, '|');
	FirstFase * firstFase = new FirstFase(fase1);

	//get Fase2;
	getline(auditionLine, fase2, '|');
	SecondFase * secondFase = new SecondFase(fase2);

	//setting the attributes

	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->judgesId = ids;
	this->chiefJudgeId = id;
	this->firstFase = firstFase;
	this->secondFase = secondFase;

}
Audition::~Audition() {
	delete[] firstFase;
	delete[] secondFase;
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
vector<unsigned int> Audition::getJudgesId() const {
	return judgesId;
}
unsigned int Audition::getChiefJudgeId() const {
	return chiefJudgeId;
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
void Audition::setJudgesId(vector<unsigned int> evaluators) {
	this->judgesId = judgesId;
}
void Audition::setChiefJudgeId(unsigned int chiefJudgeId) {
	this->chiefJudgeId = chiefJudgeId;
}
void Audition::setFirstFase(FirstFase * firstFase) {
	this->firstFase = firstFase;
}
void Audition::setSecondFase(SecondFase *  secondFase) {
	this->secondFase = secondFase;
}

//operator Overloading
bool Audition::operator<(const  Audition & audition1) const {
	return this->start < audition1.start;
}
bool Audition::operator==(const Audition & audition1) const {
	return (this->start.getDay() == audition1.start.getDay() &&
		this->start.getMonth() == audition1.start.getMonth() &&
		this->start.getYear() == audition1.start.getYear() &&
		this->specialty == audition1.specialty);
}
ostream& operator<<(ostream& os, const Audition & audition)
{
	os << audition.getId() << " | " << audition.getStart().full() << " | " << audition.getEnd().full() << " | " << audition.getSpecialty() << " | " << audition.getJudgesId()[0] << ", "  << audition.getJudgesId()[1] << " | " << audition.getChiefJudgeId() << " | " << *(audition.getFirstFase()) << " | " << *(audition.getSecondFase()) << " | ";
	return os;
}

//other methods
void Audition::gradeFirstFase() {
	firstFase->evaluate();
	firstFase->overallGrading();
}
void Audition::gradeSecondFase() {
	firstFase->evaluate();
	firstFase->overallGrading();
}
