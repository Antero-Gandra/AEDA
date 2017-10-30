/**
 * Project Untitled
 */


#include "Judge.h"

/**
 * Judge implementation
 */
Judge::Judge(unsigned int id, vector<unsigned int> participation) : Person() {
	this->id = id;
	this->participation = participation;
}