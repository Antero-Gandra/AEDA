/**
 * Project Untitled
 */


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"
#include <fstream>
#include "Participation.h"
#include "Calendar.h"

class Contestant : public Person {
	unsigned int id;
	std::vector<Participation*> participations;
	
public:
	//Constructors
	Contestant(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<unsigned int> participation);
	Contestant(std::string textLine);
	//Get Methods
	unsigned int getId() const;
	std::vector<Participation*> getParticipations() const;
	//Set Methods
	void setId(unsigned int id);
	void setParticipations(std::vector<Participation*> participation);
	//Other Methods
	void show() const ;
	//Operator overloading
	bool operator<(const Contestant & contestant1) const;
	bool operator==(const Contestant & contestant1) const;
	friend std::ostream& operator<<(std::ostream& os, const Contestant & contestant);
};

#endif //_CONTESTANT_H
