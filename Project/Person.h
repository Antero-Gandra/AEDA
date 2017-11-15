/**
 * Project Untitled
 */


#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <vector>
#include <stdlib.h>
#include "Time.h"

using namespace std;

class Person {
protected: 
    string name;
    string address;
    unsigned int mobile;
    Time dob;
    string specialty;
public:
	//Constructor
	Person() {};
	Person(string name, string address, unsigned int mobile, Time dob, string specialty);
	//Get Methods
    string getName() const;
	string getAddress() const;
	unsigned int getMobile() const;
	Time getDob() const;
	string getSpecialty() const;
	//Set Methods
	void setName(string name);
	void setAddress(string address);
	void setMobile(unsigned int mobile);
	void setDob(Time dob);
	void setSpecialty(string specialty);
	//Other Methods
	unsigned int mobileGenerator();
};

#endif //_PERSON_H