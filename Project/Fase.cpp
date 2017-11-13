/**
 * Project Untitled
 */


#include "Fase.h"

/**
 * Fase implementation
 */

Fase::Fase(unsigned int auditionId, unsigned int mark, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld) {
	this->auditionId = auditionId;
	this->mark;
	this->ev1 = ev1;
	this->ev2 = ev2;
	this->ld = ld;
}

//Get Method
unsigned int Fase::getAuditionId() const { return auditionId; }
//Set Method
void Fase::setAuditionId(unsigned int auditionId) { this->auditionId = auditionId; }

