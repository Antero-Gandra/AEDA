/**
 * Project Untitled
 */


#ifndef _AUDITION_H
#define _AUDITION_H

#include "Judge.h"
#include "Judge.h"
#include "FirstFase.h"
#include "SecondFase.h"


class Audition {
public: 
    Judge evaluators;
    Judge leader;
    FirstFase f1;
    SecondFase f2;
private: 
    unsigned int id;
    unsigned int date;
    string specialty;
};

#endif //_AUDITION_H