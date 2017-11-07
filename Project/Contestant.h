/**
 * Project Untitled
 */


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"


class Contestant: public Person {
public:
  Contestant(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation);
private:
    unsigned int id;
    vector<unsigned int> participation;
};

#endif //_CONTESTANT_H
