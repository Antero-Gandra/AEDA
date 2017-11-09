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
<<<<<<< HEAD
	Contestant(string textLine);
private: 
=======
  Contestant(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation);
private:
>>>>>>> 3350bd0d819b65cdbdb07909f1906bb354411f48
    unsigned int id;
    vector<participation*> participations;
};

#endif //_CONTESTANT_H#endif //_CONTESTANT_H
