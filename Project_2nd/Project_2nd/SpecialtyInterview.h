#ifndef _SPECIALTYINTERVIEW_H
#define _SPECIALTYINTERVIEW_H

#include <string>
#include <stack>
#include <queue>

class Interview {
private:
	unsigned int id;
	unsigned int contestantID;
	unsigned int auditionID;
public:
	Interview(unsigned int idInt, unsigned int contesID, unsigned int audID);
	unsigned int getID() const;
	unsigned int getContestantID() const;
	unsigned int getAuditionID() const;
};


typedef priority_queue<Interview> HEAP_INTRVW;

class SpecialtyInterview {
private:
	std::string specialty;
	HEAP_INTRVW interviews;
	
public:
	SpecialtyInterview(std::string specialty, HEAP_INTRVW interviews);

	std::string getSpecialty() const;
	HEAP_INTRVW getInterviews() const;

	void addInterview(unsigned int id, unsigned int contestantID, unsigned int auditionID) 

};

#endif //_INTERVIEW_H