/**
* Project Untitled
*/


#ifndef _FIRSTFASE_H
#define _FIRSTFASE_H

#include "Fase.h"
#include <ostream>


	FirstFase() {}
	FirstFase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld, std::vector<unsigned int> contestants);
	FirstFase(std::string textline);
	void overallGrading();
	//Operator overloading
	friend std::ostream& operator<<(std::ostream& os, const FirstFase & firstFase);
};


#endif //_FIRSTFASE_H
