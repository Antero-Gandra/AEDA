/**
 * Project Untitled
 */

#ifndef _FASE_H
#define _FASE_H

#include "Contestant.h"

class Fase {
	unsigned int auditionId;
	unsigned int mark;
	vector<unsigned int> ev1;
	vector<unsigned int> ev2;
	vector <unsigned int> ld;
	vector<Contestant*> contestants;
public:
	Fase() {}
	Fase(unsigned int auditionId, unsigned int mark, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld);
	//Get Mehods
	unsigned int getAuditionId() const;
	//Set Methods
	void setAuditionId(unsigned int auditionId);
};

#endif //_FASE_H