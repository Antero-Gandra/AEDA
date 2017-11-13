/**
 * Project Untitled
 */


#ifndef _SECONDFASE_H
#define _SECONDFASE_H

#include "Fase.h"


class SecondFase: public Fase { 
public:
	SecondFase() {}
	SecondFase(unsigned int auditionId, unsigned int grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld);
};

#endif //_SECONDFASE_H