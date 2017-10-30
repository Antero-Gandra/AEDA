/**
 * Project Untitled
 */


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"


class Contestant: public Person {
private: 
    unsigned int id;
    vector<unsigned int> participation;
};

#endif //_CONTESTANT_H