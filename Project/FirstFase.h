/**
* Project Untitled
*/


#ifndef _FIRSTFASE_H
#define _FIRSTFASE_H

#include "Fase.h"
#include <ostream>


class FirstFase : public Fase {
public:

	/**
	* @brief First Phase default constructor
	*/
	FirstFase() {}

	/**
	* @brief First Phase deconstructor
	*/
	~FirstFase() {}

	/**
	* @brief First Phase default constructor with their auditionID, final grade, evaluation from the judges and the id of the contestants
	* @param auditionID an unsigned integer
	* @param final_grade a vector of unsigned integers
	* @param ev1 a vector of unsigned integers
	* @param ev2 a vector of unsigned integers
	* @param ld a vector of unsigned integers
	* @param contestants a vector of unsigned integers
	*/
	FirstFase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld, std::vector<unsigned int> contestants);

	/**
	* @brief First Phase constructor by reading a line from the file
	* @param textLine a string
	*/
	FirstFase(std::string textline);

	/**
	* @brief Grades all contestants from the second phase
	*/
	void overallGrading();
	//Operator overloading
	/**
	* Operator "<<" is overloaded to output the information about the First Phase into a file
	* @param os an Outstream Object
	* @param firstFase a constant FirstFase reference
	* @return the information of the First Phase in a specific format into a file
	*/
	friend std::ostream& operator<<(std::ostream& os, const FirstFase & firstFase);
};


#endif //_FIRSTFASE_H
