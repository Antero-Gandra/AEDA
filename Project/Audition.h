/**
 * Project Untitled
 */


#ifndef _AUDITION_H
#define _AUDITION_H

#include "Judge.h"
#include "Judge.h"
#include "FirstFase.h"
#include "SecondFase.h"
#include <string>
#include <vector>
#include <string>

using namespace std;

class Audition {
private: 
    unsigned int id;
    Time start;
	Time end;
    string specialty;
	vector<unsigned int> evaluatorsId;
	unsigned int leaderId;
	FirstFase* f1;
	SecondFase* f2;
public:
	Audition(unsigned int id, Time start, Time end, string specialty, vector<unsigned int> evaluators, unsigned int leader);
	Audition(string textline);
};

#endif //_AUDITION_H