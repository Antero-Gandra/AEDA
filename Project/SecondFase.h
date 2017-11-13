/**
 * Project Untitled
 */


#ifndef _SECONDFASE_H
#define _SECONDFASE_H

#include "Fase.h"


class SecondFase: public Fase { 
public:
	SecondFase() {}
	SecondFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld);
	SecondFase(string textLine);
};

#endif //_SECONDFASE_H