/**
 * Project Untitled
 */


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"


extern const std::streamsize max;

struct participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int leaderGrade;
};

class Contestant: public Person {
public:

	Contestant(string textLine);

private: 

  Contestant(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation);
private:

    unsigned int id;
    vector<participation*> participations;
};

#endif //_CONTESTANT_H
