/**
 * Project Untitled
 */

#ifndef _FASE_H
#define _FASE_H

#include <vector>
#include <string>

class Fase {
protected:
	unsigned int auditionId;
	std::vector<double> finalGrade;
	std::vector<unsigned int> judge1;
	std::vector<unsigned int> judge2;
	std::vector <unsigned int> chiefJudge;
	std::vector<unsigned int> contestants;
public:
	Fase(){}
	virtual ~Fase(){};
	Fase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> judge1, std::vector<unsigned int> judge2, std::vector<unsigned int> chiefJudge, std::vector<unsigned int> contestants);
	Fase(std::string textline);
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

#endif //_FASE_H
