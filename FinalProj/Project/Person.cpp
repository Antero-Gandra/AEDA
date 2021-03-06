#include "Person.h"
#include <stdio.h>
#include <ctime>

using namespace std;

Person::Person(string name, string address, unsigned int mobile, Calendar dob, string specialty)
{
	this->name = name;
	this->address = address;
	this->mobile = mobile;
	this->dob = dob;
	this->specialty = specialty;
}

//Get Methods
string Person::getName() const { return this->name; }
string Person::getAddress() const { return this->address; }
unsigned int Person::getMobile() const { return mobile; }
Calendar Person::getDob() const { return this->dob; }
string Person::getSpecialty() const { return this->specialty; }
//Set Methods
void Person::setName(string name) { this->name = name; }
void Person::setAddress(string address) { this->address = address; }
void Person::setMobile(unsigned int mobile) { this->mobile = mobile; }
void Person::setDob(Calendar dob) { this->dob = dob; }
void Person::setSpecialty(string specialty) { this->specialty = specialty; }

//Other Methods
/*unsigned int Person::mobileGenerator() {
	unsigned int number = rand()% 100000000 + 900000000;
	srand(Calendar(NULL));
	return number;
};*/
