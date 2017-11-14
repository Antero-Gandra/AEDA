/**
 * Project Untitled
 */


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"

struct Participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int leaderGrade;
	Participation(unsigned int auditionId, unsigned int place, unsigned int leaderGrade) {
		this->auditionId = auditionId;
		this->place = place;
		this->leaderGrade = leaderGrade;
	}
};


class Contestant : public Person {
	unsigned int id;
	vector<Participation*> participations;
	

public:
	//Constructors
	Contestant(unsigned int id, string name, string address, unsigned int mobile, Time dob, string specialty, std::vector<unsigned int> participation);
	Contestant(string textLine);
	//Get Methods
	unsigned int getId() const;
	vector<Participation*> getParticipations() const;
	//Set Methods
	void setId(unsigned int id);
	void setParticipations(vector<Participation*> participation);
	//Other Methods
	void show() const ;
	//Operator overloading
	bool operator<(const Contestant & contestant1) const;
	bool operator==(const Contestant & contestant1) const;
	friend ostream& operator<<(ostream& os, const Contestant & contestant);
};

#endif //_CONTESTANT_H
