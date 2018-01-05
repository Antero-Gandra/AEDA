/**
 * Project Untitled
 */


#include "Phase.h"
#include "Util.h"
#include <sstream>
#include <limits>
#include <ctime>

using namespace std;

Phase::Phase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> judge1,  vector<unsigned int> judge2, vector<unsigned int> chiefJudge, vector<unsigned int> contestants) {
	this->auditionId = auditionId;
	this->finalGrade;
	this->judge1 = judge1;
	this->judge2 = judge2;
	this->chiefJudge = chiefJudge;
	this->contestants = contestants;
}
Phase::Phase(string textline) {
	//get id
	istringstream phaseLine;
	phaseLine.str(textline);

	unsigned int auditionId;
	string finals;
	string gf;
	string g1;
	string g2;
	string g3;
	string grade;
	string cont;
	string id;
	vector<double> finalGrades;
	vector<unsigned int> ev1s;
	vector<unsigned int> ev2s;
	vector<unsigned int> chiefs;
	vector<unsigned int> cntestants;
	double grd;
	unsigned int ev1;
	unsigned int ev2;
	unsigned int chief;
	unsigned int contestantId;

	//get id
	phaseLine >> auditionId;
	phaseLine.ignore(numeric_limits<streamsize>::max(), ';');

	//get contestants
	getline(phaseLine, cont, ';');
	istringstream contestantsLine(cont);
	getline(contestantsLine, id, ',');
	removeSpaces(id);

	while (id != "")
	{
		contestantId = stoi(id);
		contestants.push_back(contestantId);
		getline(contestantsLine, id, ',');
		removeSpaces(id);
	}
	// evaluator 1
	getline(phaseLine, g1, ';');
	istringstream grades1(g1);
	getline(grades1, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		ev1 = stoi(grade);
		ev1s.push_back(ev1);
		getline(grades1, grade, ',');
		removeSpaces(grade);
	}
	// evaluator 2
	getline(phaseLine, g2, ';');
	istringstream grades2(g2);
	getline(grades2, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		ev2 = stoi(grade);
		ev2s.push_back(ev2);
		getline(grades2, grade, ',');
		removeSpaces(grade);
	}

	// chiefJudge
	getline(phaseLine, g3, ';');
	istringstream grades3(g3);
	getline(grades3, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		chief = stoi(grade);
		chiefs.push_back(chief);
		getline(grades3, grade, ',');
		removeSpaces(grade);
	}


	//get final marks
	getline(phaseLine, gf, ';');
	istringstream gradesf(gf);
	getline(gradesf, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		grd = stoi(grade);
		finalGrades.push_back(grd);
		getline(gradesf, grade, ',');
		removeSpaces(grade);
	}

	this->auditionId = auditionId;
	this->judge1 = ev1s;
	this->judge2 = ev2s;
	this->chiefJudge = chiefs;
	this->finalGrade = finalGrades;
	this->contestants = contestants;
}

//Get Methods
unsigned int Phase::getAuditionId() const { return auditionId; }
vector<double> Phase::getFinalGrade() const { return finalGrade; }
vector<unsigned int> Phase::getJudge1() const { return judge1; }
vector<unsigned int> Phase::getJudge2() const {	return judge2;}
vector<unsigned int> Phase::getChiefJudge() const { return chiefJudge; }
vector<unsigned int> Phase::getContestants() const { return contestants; }
//Set Method
void Phase::setAuditionId(unsigned int auditionId) { this->auditionId = auditionId; }
void Phase::setContestants(std::vector<unsigned int> contestants) {
	this->contestants = contestants;
}

//other methods
void Phase::evaluate() {
	srand(time(NULL));
	for (size_t i = 0; i < contestants.size(); i++)
	{
		judge1.push_back(rand() % 10 + 1);
		judge2.push_back(rand() % 10 + 1);
		chiefJudge.push_back(rand() % 10 + 1);
	}
}



