/**
 * Project Untitled
 */


#ifndef _PERSON_H
#define _PERSON_H

#include "Calendar.h"


class Person {
protected: 
    std::string name;
    std::string address;
    unsigned int mobile;
    Calendar dob;
    std::string specialty;
public:
	//Constructor
	Person() {};
	Person(std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty);
	//Get Methods
    std::string getName() const;
	void setName(std::string name);
	void setAddress(std::string address);
	void setMobile(unsigned int mobile);
	void setDob(Calendar dob);
	void setSpecialty(std::string specialty);
	//Other Methods
	unsigned int mobileGenerator();
};

#endif //_PERSON_H
