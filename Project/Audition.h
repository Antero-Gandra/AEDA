#ifndef _AUDITION_H
#define _AUDITION_H

#include "FirstFase.h"
#include "SecondFase.h"
#include <string>
#include <vector>
#include "Calendar.h"
#include <ios>

class Audition {
private: 
    unsigned int id;
    Calendar start;
	Calendar end;
    std::string specialty;
	std::vector<unsigned int> judgesId;
	unsigned int chiefJudgeId;
	FirstFase* firstFase;
	SecondFase* secondFase;
public:
	Audition(unsigned int id, Calendar start, Calendar end, std::string specialty, std::vector<unsigned int> judgesId, unsigned int chiefJudgeId, std::vector<unsigned int> contestants);
	Audition(std::string textline);
	~Audition();
	//get Methods
	unsigned int getId() const;
	Calendar getStart() const;
	Calendar getEnd() const;
	std::string getSpecialty() const;
	std::vector<unsigned int> getJudgesId() const;
	unsigned int getChiefJudgeId() const;
	FirstFase* getFirstFase() const;
	SecondFase* getSecondFase() const;

	//set Methods
	void setId(unsigned int id);
	void setStart(Calendar start);
	void setEnd(Calendar end);
	void setSpecialty(std::string specialty);
	void setJudgesId(std::vector<unsigned int> evaluators);
	void setChiefJudgeId(unsigned int chiefJudgeId);
	void setFirstFase(FirstFase * firstFase);
	void setSecondFase(SecondFase *  secondFase);

	//operator overloading
	friend std::ostream& operator<<(std::ostream& os, const Audition & contestant);

	//Other Methods
	*/
	std::vector<unsigned int> gradeFirstFase();
	*/
	std::vector<unsigned int> gradeSecondFase();
	void show();
};

#endif //_AUDITION_H
