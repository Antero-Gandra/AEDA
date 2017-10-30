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

using namespace std;

class Audition {
private: 
    unsigned int id;
    unsigned int date;
    string specialty;
	vector<Judge*> evaluators;
	Judge* leader;
	FirstFase * f1;
	SecondFase * f2;
public:
	Audition(string specialty);
	Audition(unsigned int id, unsigned int date, string specialty, vector<Judge *> evaluators, Judge * leader);

};

#endif //_AUDITION_H