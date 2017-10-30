/**
 * Project Untitled
 */


#ifndef _SECONDFASE_H
#define _SECONDFASE_H

#include "Fase.h"
#include "Audition.h"


class SecondFase: public Fase { 
	unsigned int auditionId;
public:
	SecondFase(unsigned int auditionId);
};

#endif //_SECONDFASE_H