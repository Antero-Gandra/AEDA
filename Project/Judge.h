/**
 * Project Untitled
 */


#ifndef _JUDGE_H
#define _JUDGE_H

#include "Person.h"


class Judge: public Person {
private: 
    unsigned int id;
    vector<unsigned int> participation;
};

#endif //_JUDGE_H