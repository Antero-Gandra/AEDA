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
	vector<unsigned int> ids;
	string fase1;
	string fase2;
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

	//get evaluator1 id
	auditionLine >> id;
	ids.push_back(id);

	//get evaluator2 id
	auditionLine >> id;
	ids.push_back(id);
	auditionLine.ignore(max, '|');

	//get leader id
	auditionLine >> id;
	auditionLine.ignore(max, '|');

	//get Fase1
	getline(auditionLine, fase1, '|');

	//get Fase2;
	getline(auditionLine, fase2, '|');

	//setting the attributes
	this->id = id;
	this->start = start;
	this->end = end;
	this->specialty = specialty;
	this->evaluatorsId = ids;
	this->leaderId = id;
}