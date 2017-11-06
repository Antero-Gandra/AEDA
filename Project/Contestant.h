/**
 * Project Untitled
 */


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"

struct participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int leaderGrade;
};

class Contestant: public Person {
public:
	Contestant(string textLine);
private: 
    unsigned int id;
    vector<participation*> participations;
};

#endif //_CONTESTANT_H