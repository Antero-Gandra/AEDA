/**
 * Project Untitled
 */


#include "Audition.h"

using namespace std;

/**
 * Audition implementation
 */

Audition::Audition(string  specialty) {
	this->specialty = specialty;
}
Audition::Audition(unsigned int id, Time date, string specialty, vector<Judge*> evaluators, Judge *leader) {
	this->id = id;
	this->date = date;
	this->specialty = specialty;
	this->evaluators = evaluators;
	this->leader = leader;
	this->f1 = 0;
	this->f2 = 0;
}
