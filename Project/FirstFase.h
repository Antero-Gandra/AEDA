/**
 * Project Untitled
 */


#ifndef _FIRSTFASE_H
#define _FIRSTFASE_H

#include "Fase.h"


class FirstFase: public Fase {
public: 
	FirstFase() {}
	FirstFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld);
	FirstFase(string textline);
};

#endif //_FIRSTFASE_H