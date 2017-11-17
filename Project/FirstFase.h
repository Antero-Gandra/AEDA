/**
 * Project Untitled
 */


#ifndef _FIRSTFASE_H
#define _FIRSTFASE_H

#include "Fase.h"


class FirstFase: public Fase {
public: 
	FirstFase() {}
	FirstFase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld);
	FirstFase(std::string textline);
};

#endif //_FIRSTFASE_H
