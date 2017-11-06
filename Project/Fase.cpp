/**
 * Project Untitled
 */


#include "Fase.h"

/**
 * Fase implementation
 */

Fase::Fase(unsigned int auditionId) {
	this->auditionId = auditionId;
}
//Get Method
unsigned int Fase::getAuditionId() const { return auditionId; }
//Set Method
void Fase::setAuditionId(unsigned int auditionId) { this->auditionId = auditionId; }

