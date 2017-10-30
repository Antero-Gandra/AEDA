/**
 * Project Untitled
 */


#include "Person.h"

/**
 * Person implementation
 */

Person::Person(string name, string address, unsigned int mobile, unsigned int dob, string specialty)
{
	this->name = name;
	this->address = address;
	this->mobile = mobile;
	this->dob = dob;
	this->specialty = specialty;
}