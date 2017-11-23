/**
* Project Untitled
*/


#ifndef _FIRSTPHASE_H
#define _FIRSTPHASE_H

#include "Phase.h"
#include <ostream>


class FirstPhase : public Phase {
public:

	/**
	* @brief First Phase default constructor
	*/
	FirstPhase() {}

	/**
	* @brief First Phase deconstructor
	*/
	~FirstPhase() {}

	/**
	* @brief First Phase default constructor with their auditionID, final grade, evaluation from the judges and the id of the contestants
	* @param auditionID an unsigned integer
	* @param final_grade a vector of unsigned integers
	* @param ev1 a vector of unsigned integers
	* @param ev2 a vector of unsigned integers
	* @param ld a vector of unsigned integers
	* @param contestants a vector of unsigned integers
	*/
	FirstPhase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld, std::vector<unsigned int> contestants);

	/**
	* @brief First Phase constructor by reading a line from the file
	* @param textLine a string
	*/
	FirstPhase(std::string textline);

	/**
	* @brief Grades all contestants from the second phase
	*/
	void overallGrading();
	//Operator overloading
	/**
	* Operator "<<" is overloaded to output the information about the First Phase into a file
	* @param os an Outstream Object
	* @param firstPhase a constant FirstPhase reference
	* @return the information of the First Phase in a specific format into a file
	*/
	friend std::ostream& operator<<(std::ostream& os, const FirstPhase & firstPhase);
};


#endif //_FIRSTPHASE_H
