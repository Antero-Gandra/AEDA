#ifndef _AUDITION_H
#define _AUDITION_H

#include "FirstFase.h"
#include "SecondFase.h"
#include <string>
#include <vector>
#include "Calendar.h"

class Audition {
private: 
    unsigned int id;
    Calendar start;
	Calendar end;
    std::string specialty;
	std::vector<unsigned int> evaluatorsId;
	unsigned int leaderId;
	FirstFase* firstFase;
	SecondFase* secondFase;
public:
	Audition(unsigned int id, Calendar start, Calendar end, std::string specialty, std::vector<unsigned int> evaluators, unsigned int leader);
	Audition(std::string textline);
	//get Methods
	unsigned int getId() const;
	Calendar getStart() const;
	Calendar getEnd() const;
	std::string getSpecialty() const;
	std::vector<unsigned int> getEvaluatorsId() const;
	unsigned int getLeaderId() const;
	FirstFase* getFirstFase() const;
	SecondFase* getSecondFase() const;

	//set Methods
	void setId(unsigned int id);
	void setStart(Calendar start);
	void setEnd(Calendar end);
	void setSpecialty(std::string specialty);
	void setEvaluatorsId(std::vector<unsigned int> evaluators);
	void setLeaderId(unsigned int leaderId);
	void setFirstFase(FirstFase * firstFase);
	void setSecondFase(SecondFase *  secondFase);

	//operator overloading
	bool operator<(const  Audition & contestant1) const;
	bool operator==(const Audition & contestant1) const;
	friend std::ostream& operator<<(std::ostream& os, const Audition & contestant);
};

#endif //_AUDITION_H
