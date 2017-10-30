/**
 * Project Untitled
 */


#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person {
private: 
    string name;
    string address;
    unsigned int mobile;
    unsigned int dob;
    string specialty;
public:
	Person() {};
	Person(string name, string address, unsigned int mobile, unsigned int dob, string specialty);
};

#endif //_PERSON_H