/**
 * Project Untitled
 */


#ifndef _AUDITION_H
#define _AUDITION_H

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
	FirstFase* firstFase;
	SecondFase* secondFase;
public:
	Audition(unsigned int id, Time start, Time end, string specialty, vector<unsigned int> evaluators, unsigned int leader);
	Audition(string textline);
	//get Methods
	unsigned int getId() const;
	Time getStart() const;
	Time getEnd() const;
	string getSpecialty() const;
	vector<unsigned int> getEvaluatorsId() const;
	unsigned int getLeaderId() const;
	FirstFase* getFirstFase() const;
	SecondFase* getSecondFase() const;

	//set Methods
	void setId(unsigned int id);
	void setStart(Time start);
	void setEnd(Time end);
	void setSpecialty(string specialty);
	void setEvaluatorsId(vector<unsigned int> evaluators);
	void setLeaderId(unsigned int leaderId);
	void setFirstFase(FirstFase * firstFase);
	void setSecondFase(SecondFase *  secondFase);

	//operator overloading
	bool operator<(const  Audition & contestant1) const;
	bool operator==(const Audition & contestant1) const;
	friend ostream& operator<<(ostream& os, const Audition & contestant);
};

#endif //_AUDITION_H