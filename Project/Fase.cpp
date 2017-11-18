/**
 * Project Untitled
 */


#include "Fase.h"
#include "Util.h"
#include <sstream>
#include <limits>
#include <ctime>

using namespace std;

Fase::Fase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> judge1,  vector<unsigned int> judge2, vector<unsigned int> chiefJudge, vector<unsigned int> contestants) {
	this->auditionId = auditionId;
	this->finalGrade;
	this->judge1 = judge1;
	this->judge2 = judge2;
	this->chiefJudge = chiefJudge;
	this->contestants = contestants;
}
Fase::Fase(string textline) {
	//get id
	istringstream faseLine;
	faseLine.str(textline);

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
	faseLine >> auditionId;
	faseLine.ignore(numeric_limits<streamsize>::max(), ';');

	//get contestants
	getline(faseLine, cont, ';');
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
	getline(faseLine, g1, ';');
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
	getline(faseLine, g2, ';');
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
	getline(faseLine, g3, ';');
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
	getline(faseLine, gf, ';');
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
unsigned int Fase::getAuditionId() const { return auditionId; }
vector<double> Fase::getFinalGrade() const { return finalGrade; }
vector<unsigned int> Fase::getJudge1() const { return judge1; }
vector<unsigned int> Fase::getJudge2() const {	return judge2;}
vector<unsigned int> Fase::getChiefJudge() const { return chiefJudge; }
vector<unsigned int> Fase::getContestants() const { return contestants; }
//Set Method
void Fase::setAuditionId(unsigned int auditionId) { this->auditionId = auditionId; }

//other methods
void Fase::evaluate() {
	srand(time(NULL));
	for (size_t i = 0; i < contestants.size(); i++)
	{
		judge1.push_back(rand() % 10 + 1);
		judge2.push_back(rand() % 10 + 1);
		chiefJudge.push_back(rand() % 10 + 1);
	}
}



