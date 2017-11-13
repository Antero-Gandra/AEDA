/**
 * Project Untitled
 */


#include "Fase.h"
#include "Util.h"
#include <sstream>

 /**
  * Fase implementation
  */

Fase::Fase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld) {
	this->auditionId = auditionId;
	this->final_grade;
	this->ev1 = ev1;
	this->ev2 = ev2;
	this->ld = ld;
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
	vector<unsigned int> final_grades;
	vector<unsigned int> ev1s;
	vector<unsigned int> ev2s;
	vector<unsigned int> lds;
	vector<unsigned int> cntestants;
	unsigned int grd;
	unsigned int ev1;
	unsigned int ev2;
	unsigned int ld;
	unsigned int contestantId;

	//get id
	faseLine >> auditionId;
	faseLine.ignore(max, ';');

	//get final marks
	getline(faseLine, gf, ';');
	istringstream gradesf(gf);
	getline(gradesf, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		grd = stoi(grade);
		final_grades.push_back(grd);
		getline(gradesf, grade, ',');
		removeSpaces(grade);
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

	// leader
	getline(faseLine, g3, ';');
	istringstream grades3(g3);
	getline(grades3, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		ld = stoi(grade);
		lds.push_back(ld);
		getline(grades3, grade, ',');
		removeSpaces(grade);
	}

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
}

//Get Method
unsigned int Fase::getAuditionId() const { return auditionId; }
//Set Method
void Fase::setAuditionId(unsigned int auditionId) { this->auditionId = auditionId; }

