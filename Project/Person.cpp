#include "Person.h"
#include <cstdlib>
#include <stdio.h>
#include <time.h>

/**
 * Person implementation
 */

Person::Person(string name, string address, unsigned int mobile, Time dob, string specialty)
{
	this->name = name;
	this->address = address;
	this->mobile = mobile;
	this->dob = dob;
	this->specialty = specialty;
}

//Get Methods
string Person::getName() const { return name; }
string Person::getAddress() const { return address; }
unsigned int Person::getMobile() const { return mobile; }
Time Person::getDob() const { return dob; }
string Person::getSpecialty() const { return specialty; }
//Set Methods
void Person::setName(string name) { this->name = name; }
void Person::setAddress(string adress) { this->address = address; }
void Person::setMobile(unsigned int mobile) { this->mobile = mobile; }
void Person::setDob(Time dob) { this->dob = dob; }
void Person::setSpecialty(string speciality) { this->specialty = speciality; }

//Other Methods
unsigned int Person::mobileGenerator() {
	unsigned int number = rand()% 100000000 + 900000000;
	srand(time(NULL));
	return number;
};
