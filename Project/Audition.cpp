/**
 * Project Untitled
 */


#include "Audition.h"
#include "Util.h"
#include <sstream>

using namespace std;

/**
 * Audition implementation
 */

Audition::Audition(unsigned int id, Time start, Time end, string specialty, vector<unsigned int> evaluatorsId, unsigned int leaderId) {
	this->id = id;
	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->evaluatorsId = evaluatorsId;
	this->leaderId = leaderId;
	this->f1 = 0;
	this->f2 = 0;
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
	unsigned int ev1, ev2, ld;
	vector<unsigned int> evs1, evs2, lds2;
	string s1, s2, s3;
	string grade;
	string specialty;

	//get id
	auditionLine >> id;
	auditionLine.ignore(max, '|');

	//get start
	auditionLine >> year;
	auditionLine.ignore(max, '/');
	auditionLine >> month;
	auditionLine.ignore(max, '/');
	auditionLine >> day;
	auditionLine.ignore(max, '/');
	auditionLine >> hour;
	auditionLine.ignore(max, '/');
	auditionLine >> minute;
	auditionLine.ignore(max, '|');
	Time start(year, month, day, hour, minute);

	//get end
	auditionLine >> year;
	auditionLine.ignore(max, '/');
	auditionLine >> month;
	auditionLine.ignore(max, '/');
	auditionLine >> day;
	auditionLine.ignore(max, '/');
	auditionLine >> hour;
	auditionLine.ignore(max, '/');
	auditionLine >> minute;
	auditionLine.ignore(max, '|');
	Time end(year, month, day, hour, minute);

	//get specialty
	getline(auditionLine, specialty, '|');
	removeSpaces(specialty);

	//get evaluator 1 grades
	getline(auditionLine, s1, '|');
	istringstream grades1(s1);
	getline(grades1, grade, ',');
	removeSpaces(grade);

	while (grade != "")
	{
		ev1 = stoi(grade);
		evs1.push_back(ev1);
		getline(grades1, grade, ',');
		removeSpaces(grade);
	}

}