/**
* Project Untitled
*/

#ifndef _PHASE_H
#define _PHASE_H

#include <vector>
#include <string>

class Phase {
protected:
	unsigned int auditionId;
	std::vector<double> finalGrade;
	std::vector<unsigned int> judge1;
	std::vector<unsigned int> judge2;
	std::vector <unsigned int> chiefJudge;
	std::vector<unsigned int> contestants;
public:

	/**
	* @brief Phase default constructor
	*/
	Phase() {}

	/**
	* @brief Phase deconstructor
	*/
	virtual ~Phase() {};

	/**
	* @brief Phase default constructor with their auditionID, final grade, evaluation from the judges and the id of the contestants
	* @param auditionID an unsigned integer
	* @param final_grade a vector of unsigned integers
	* @param ev1 a vector of unsigned integers
	* @param ev2 a vector of unsigned integers
	* @param ld a vector of unsigned integers
	* @param contestants a vector of unsigned integers
	*/
	Phase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> judge1, std::vector<unsigned int> judge2, std::vector<unsigned int> chiefJudge, std::vector<unsigned int> contestants);

	/**
	* @brief Phase constructor by reading a line from the file
	* @param textLine a string
	*/
	Phase(std::string textline);
	//Get Methods
	unsigned int getAuditionId() const;
	std::vector<double> getFinalGrade() const;
	std::vector<unsigned int> getJudge1() const;
	std::vector<unsigned int> getJudge2() const;
	std::vector<unsigned int> getChiefJudge() const;
	std::vector<unsigned int> getContestants() const;
	//Set Methods
	void setAuditionId(unsigned int auditionId);
	void setContestants(std::vector<unsigned int> contestants);
	//other methods
	void evaluate();
	virtual void overallGrading() = 0;
};

#endif //_PHASE_H
