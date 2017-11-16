#ifndef _EXCEPTIONHAND_H
#define _EXCEPTIONHAND_H

#include <string> 
using namespace std;

class ContestantInfoNotFound {
};

class ContestantIdNotFound {
	unsigned int id;
public:
	ContestantIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};
class JudgeInfoNotFound {
};

class JudgeIdNotFound {
	unsigned int id;
public:
	JudgeIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }

};

class AuditionIdNotFound{
	unsigned int id;
public:
	AuditionIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};

class SpecialtyNotAvailable {
	string specialty;
public:
	SpecialtyNotAvailable(string specialty) { this->specialty = specialty; }
	string getSpecialty() const { return specialty; }
};

class EmptyAnswer {

};

class InvalidOption {

};

class OptionOutOfRange {

};

class NotYesOrNo {

};

class InvalidId {

};

class NotANumber {

};

#endif