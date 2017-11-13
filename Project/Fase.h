/**
 * Project Untitled
 */

#ifndef _FASE_H
#define _FASE_H

#include "Contestant.h"

class Fase {
	unsigned int auditionId;
	vector<unsigned int> final_grade;
	vector<unsigned int> ev1;
	vector<unsigned int> ev2;
	vector <unsigned int> ld;
	vector<unsigned int> contestants;
public:
	Fase() {}
	Fase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld);
	Fase(string textline);
	//Get Mehods
	unsigned int getAuditionId() const;
	//Set Methods
	void setAuditionId(unsigned int auditionId);
};

#endif //_FASE_H