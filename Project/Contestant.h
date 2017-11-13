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
	//Get Methods
	unsigned int getId() const;
	vector<participation*> getParticipations() const;
	//Set Methods
	void setId(unsigned int id);
	void setParticipations(vector<participation*> participation);
	//Other Methods
	void show() const ;
	//Operator overloading
	bool operator<(const Contestant & contestant1) const;
	bool operator==(const Contestant & contestant1) const;
	friend ostream& operator<<(ostream& os, const Contestant & contestant);
};

#endif //_CONTESTANT_H
