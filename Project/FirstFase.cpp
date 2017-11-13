/**
 * Project Untitled
 */


#include "FirstFase.h"
#include <sstream>
#include "Util.h"

 /**
  * FirstFase implementation
  */

FirstFase::FirstFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld) :Fase(auditionId, final_grade, ev1, ev2, ld) {
}
FirstFase::FirstFase(string textline) {
	//get id
	istringstream faseLine;
	faseLine.str(textline);

	unsigned int auditionId;
	string finals;
	string gf;
	string g1;
	string g2;
	string g2;
	string grade;
	vector<unsigned int> final_marks;
	vector<unsigned int> ev1s;
	vector<unsigned int> ev2s;
	vector<unsigned int> lds;
	vector<unsigned int> cntestants;
	unsigned int g;
	unsigned int ev1;
	unsigned int ev2;
	unsigned int ld;
	unsigned int contestant;

	//get id
	faseLine >> auditionId;
	faseLine.ignore(max, ';');

	//get marks
	getline(faseLine, g1, ';');
	istringstream grades1(g1);
	getline(grades1, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		g = stoi(grade);
		ev1s.push_back(g);
		getline(grades1, grade, ',');
		removeSpaces(grade);
	}
	faseLine.ignore(max, ';');

	// evaluator 1
	getline(faseLine, g1, ';');
	istringstream grades1(g1);
	getline(grades1, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		g = stoi(grade);
		ev1s.push_back(g);
		getline(grades1, grade, ',');
		removeSpaces(grade);
	}

	//get leader grades
	getline(auditionLine, s3, '|');
	istringstream grades3(s3);
	getline(grades3, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		ld = stoi(grade);
		lds.push_back(ev1);
		getline(grades3, grade, ',');
		removeSpaces(grade);
	}


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
}
