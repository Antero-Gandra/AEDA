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
	/**
	* @brief Manages to get the audition's id
	* @return unsigned integer
	*/
	unsigned int getAuditionId() const;
		
	/**
	* @brief Manages access all the final grades from the contestants of a certain phase
	* @return vector of doubles the final grade
	*/
	std::vector<double> getFinalGrade() const;
	
	/**
	* @brief Manages access the grades the first judge gave to all contestants of a certain phase
	* @return vector of unsigned integers the grade of the first judge
	*/
	std::vector<unsigned int> getJudge1() const;
	
	/**
	* @brief Manages access the grades the second judge gave to all contestants of a certain phase
	* @return vector of unsigned integers the grade of the second judge
	*/
	std::vector<unsigned int> getJudge2() const;
	
	/**
	* @brief Manages access the grades the reposible judge gave to all contestants of a certain phase
	* @return vector of unsigned integers the grade of the resposible judge
	*/
	std::vector<unsigned int> getChiefJudge() const;
	
	/**
	* @brief Manages access the id of all contestants of a certain phase
	* @return vector of unsigned integers
	*/
	std::vector<unsigned int> getContestants() const;
	
	
	//Set Methods
	
	/**
	* @brief Changes the id of an audition
	* @param auditionId unsigned integer 
	*/
	void setAuditionId(unsigned int auditionId);
	
	/**
	* @brief Changes the id of all contestants
	* @param contestants unsigned integer 
	*/
	void setContestants(std::vector<unsigned int> contestants);
	
	
	//other methods
	
	/**
	* @brief Randomly assigns the the individual grades of each judges to all contestants
	*/
	
	void evaluate();
	
	/**
	* @brief Virtual function to grade all contestants
	*/
	
	virtual void overallGrading() = 0;
};

#endif //_PHASE_H
