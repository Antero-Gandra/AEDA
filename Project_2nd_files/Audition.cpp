/**
 * Project Untitled
 */


#include "Audition.h"
#include "Util.h"
#include <sstream>
#include <limits>
#include <cstddef>
#include <algorithm> 

using namespace std;

Audition::Audition(unsigned int id, Calendar start, Calendar end, std::string specialty, std::vector<unsigned int> judgesId, unsigned int chiefJudgeId, std::vector<unsigned int> contestants) {
	this->id = id;
	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->judgesId = judgesId;
	this->chiefJudgeId = chiefJudgeId;
	this->firstPhase = new FirstPhase(id, {}, {}, {}, {}, contestants);
	this->secondPhase = new SecondPhase(id, {}, {}, {}, {}, {});
	addInterview(specialty, contestants);
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
	string phase1;
	string phase2;
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

	//get Phase1
	getline(auditionLine, phase1, '|');
	FirstPhase * firstPhase = new FirstPhase(phase1);

	//get Phase2;
	getline(auditionLine, phase2, '|');
	SecondPhase * secondPhase = new SecondPhase(phase2);

	//setting the attributes

	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->judgesId = ids;
	this->chiefJudgeId = id;
	this->firstPhase = firstPhase;
	this->secondPhase = secondPhase;

}
Audition::~Audition() {
	delete firstPhase;
	delete secondPhase;
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
FirstPhase* Audition::getFirstPhase() const {
	return firstPhase;
}
SecondPhase* Audition::getSecondPhase() const {
	return secondPhase;
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
void Audition::setFirstPhase(FirstPhase * firstPhase) {
	this->firstPhase = firstPhase;
}
void Audition::setSecondPhase(SecondPhase *  secondPhase) {
	this->secondPhase = secondPhase;
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
	os << audition.getId() << " | " << audition.getStart().full() << " | " << audition.getEnd().full() << " | " << audition.getSpecialty() << " | " << audition.getJudgesId()[0] << ", "  << audition.getJudgesId()[1] << " | " << audition.getChiefJudgeId() << " | " << *(audition.getFirstPhase()) << " | " << *(audition.getSecondPhase()) << " | ";
	return os;
}

//other methods
vector<unsigned int> Audition::gradeFirstPhase() {
	firstPhase->evaluate();
	firstPhase->overallGrading();

	vector<unsigned int> orderedContestants = firstPhase->getContestants();
	vector<double> orderedGrades = firstPhase->getFinalGrade();
	
	//double sort
	for (unsigned int j = orderedGrades.size() - 1; j > 0; j--){
		bool troca = false;
		for (unsigned int i = 0; i < j; i++)
			if (orderedGrades[i + 1] < orderedGrades[i]) {
				swap(orderedGrades[i], orderedGrades[i + 1]);
				swap(orderedContestants[i], orderedContestants[i + 1]);
				troca = true;
			}
		if (!troca) break;
	}
	//Contestants who were not qualified
	vector<unsigned int> contestantsNotQualified = orderedContestants;
	contestantsNotQualified.resize(orderedContestants.size() - 5);

	//Contestants who were qualified
	vector<unsigned int> contestantsQualified = orderedContestants;
	reverse(contestantsQualified.begin(), contestantsQualified.end());
	contestantsQualified.resize(5);
	sort(contestantsQualified.begin(), contestantsQualified.end());
	secondPhase->setContestants(contestantsQualified);

	return contestantsNotQualified;
}
vector<unsigned int> Audition::gradeSecondPhase() {
	secondPhase->evaluate();
	secondPhase->overallGrading();

	vector<unsigned int> orderedContestants = secondPhase->getContestants();
	vector<double> orderedGrades = secondPhase->getFinalGrade();

	//double sort
	for (unsigned int j = orderedGrades.size() - 1; j > 0; j--) {
		bool troca = false;
		for (unsigned int i = 0; i < j; i++)
			if (orderedGrades[i + 1] < orderedGrades[i]) {
				swap(orderedGrades[i], orderedGrades[i + 1]);
				swap(orderedContestants[i], orderedContestants[i + 1]);
				troca = true;
			}
		if (!troca) break;
	}
	reverse(orderedContestants.begin(), orderedContestants.end());
	return orderedContestants;
}
