/**
 * Project Untitled
 */


#ifndef _FIRSTFASE_H
#define _FIRSTFASE_H

#include "Fase.h"


class FirstFase: public Fase {
public: 
	FirstFase() {}
	FirstFase::FirstFase(unsigned int auditionId, unsigned int grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld);
};

#endif //_FIRSTFASE_H