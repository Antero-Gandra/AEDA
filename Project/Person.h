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
	std::string getAddress() const;
	unsigned int getMobile() const;
	Calendar getDob() const;
	std::string getSpecialty() const;
	//Set Methods
	void setName(std::string name);
	void setAddress(std::string address);
	void setMobile(unsigned int mobile);
	void setDob(Calendar dob);
	void setSpecialty(std::string specialty);
	//Other Methods
	unsigned int mobileGenerator();
};

#endif //_PERSON_H
