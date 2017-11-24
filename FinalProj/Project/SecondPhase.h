/**
* Project Untitled
*/


#ifndef _SECONDPHASE_H
#define _SECONDPHASE_H

#include "Phase.h"


class SecondPhase : public Phase {
public:
	/**
	* @brief Second Phase default constructor
	*/
	SecondPhase() {}

	/**
	* @brief Second Phase deconstructor
	*/
	~SecondPhase() {}

	/**
	* @brief Second Phase default constructor with their auditionID, final grade, evaluation from the judges and the id of the contestants
	* @param auditionID an unsigned integer
	* @param final_grade a vector of unsigned integers
	* @param ev1 a vector of unsigned integers
	* @param ev2 a vector of unsigned integers
	* @param ld a vector of unsigned integers
	* @param contestants a vector of unsigned integers
	*/
	SecondPhase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld, std::vector<unsigned int> contestants);

	/**
	* @brief Second Phase constructor by reading a line from the file
	* @param textLine a string
	*/
	SecondPhase(std::string textLine);
	
	/**
	* @brief Grades all contestants from the second phase
	*/
	virtual void overallGrading();

	//Operator overloading
	/**
	* Operator "<<" is overloaded to output the information about the Second Phase into a file
	* @param os an Outstream Object
	* @param secondPhase a constant SecondPhase reference
	* @return the information of the Second Phase in a specific format into a file
	*/
	friend std::ostream& operator<<(std::ostream& os, const SecondPhase & secondPhase);
};

#endif //_SECONDPHASE_H
