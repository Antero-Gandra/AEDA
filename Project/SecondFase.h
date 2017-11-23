/**
* Project Untitled
*/


#ifndef _SECONDFASE_H
#define _SECONDFASE_H

#include "Fase.h"


public:
	SecondFase() {}
	SecondFase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld, std::vector<unsigned int> contestants);
	SecondFase(std::string textLine);
	virtual void overallGrading();

	//Operator overloading
};

#endif //_SECONDFASE_H
