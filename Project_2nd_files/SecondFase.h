/**
* Project Untitled
*/


#ifndef _SECONDFASE_H
#define _SECONDFASE_H

#include "Fase.h"


class SecondFase : public Fase {
public:
	/**
	* @brief Second Phase default constructor
	*/
	SecondFase() {}

	/**
	* @brief Second Phase deconstructor
	*/
	~SecondFase() {}

	/**
	* @brief Second Phase default constructor with their auditionID, final grade, evaluation from the judges and the id of the contestants
	* @param auditionID an unsigned integer
	* @param final_grade a vector of unsigned integers
	* @param ev1 a vector of unsigned integers
	* @param ev2 a vector of unsigned integers
	* @param ld a vector of unsigned integers
	* @param contestants a vector of unsigned integers
	*/
	SecondFase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld, std::vector<unsigned int> contestants);

	/**
	* @brief Second Phase constructor by reading a line from the file
	* @param textLine a string
	*/
	SecondFase(std::string textLine);
	/**
	* @brief Grades all contestants from the second phase
	*/
	virtual void overallGrading();

	//Operator overloading
	/**
	* Operator "<<" is overloaded to output the information about the Second Phase into a file
	* @param os an Outstream Object
	* @param secondFase a constant SecondFase reference
	* @return the information of the Second Phase in a specific format into a file
	*/
	friend std::ostream& operator<<(std::ostream& os, const SecondFase & secondFase);
};

#endif //_SECONDFASE_H
