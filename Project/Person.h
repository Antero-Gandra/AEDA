/**
 * Project Untitled
 */


#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Person {
private: 
    string name;
    string address;
    unsigned int mobile;
    unsigned int dob;
    string specialty;
public:
	//Constructor
	Person() {};
	Person(string name, string address, unsigned int mobile, unsigned int dob, string specialty);
	//Get Methods
    string getName() const;
	string getAddress() const;
	unsigned int getMobile() const;
	unsigned int getDob() const;
	string getSpeciality() const;
	//Set Methods
	void setName(string name);
	void setAddress(string address);
	void setMobile(unsigned int mobile);
	void setDob(unsigned int dob);
	void setSpeciality(string specialty);
	//Other Methods
	unsigned int mobileGenerator();
};

#endif //_PERSON_H