/**
 * Project Untitled
 */


#ifndef _FIRSTFASE_H
#define _FIRSTFASE_H

#include "Fase.h"
#include "Audition.h"


class FirstFase: public Fase {
	unsigned int auditionId;
public: 
	FirstFase(unsigned int auditionId);
};

#endif //_FIRSTFASE_H