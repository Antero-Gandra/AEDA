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
	
	/**
	* @brief Manages to get the id of the contestant that was not found
	* @return unsigned integer id of the contestant not found
	*/
	unsigned int getId() const { return id; }
};


class UnavailableContestantIdNotFound {
	unsigned int id;
public:
	UnavailableContestantIdNotFound(unsigned int id) { this->id = id; }

	/**
	* @brief Manages to get the id of the contestant that was not found
	* @return unsigned integer id of the contestant not found
	*/
	unsigned int getId() const { return id; }
};
class JudgeInfoNotFound {
};

class JudgeIdNotFound {
	unsigned int id;
public:
	JudgeIdNotFound(unsigned int id) { this->id = id; }
	
	/**
	* @brief Manages to get the id of the judge that was not found
	* @return unsigned integer id of the judge not found
	*/
	unsigned int getId() const { return id; }

};

class AuditionIdNotFound{
	unsigned int id;
public:
	AuditionIdNotFound(unsigned int id) { this->id = id; }

	/**
	* @brief Manages to get the id of the audition that was not found
	* @return unsigned integer of id of the audition not found
	*/
	unsigned int getId() const { return id; }
};

class SpecialtyNotAvailable {
	string specialty;
public:
	SpecialtyNotAvailable(string specialty) { this->specialty = specialty; }
	
	/**
	* @brief Manages to get the id of the specialty that is not available
	* @return string of the speciality that is not available
	*/
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