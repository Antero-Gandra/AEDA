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

class Contestant : public Person {
	unsigned int id;
	vector<participation*> participations;
	

public:
	//Constructors
	Contestant(unsigned int id, string name, string address, unsigned int mobile, Time dob, string specialty, std::vector<unsigned int> participation);
	Contestant(string textLine);

	//Operator overloading
	bool operator<(Contestant & contestant1);
	bool operator==(Contestant & contestant1);
};

#endif //_CONTESTANT_H
