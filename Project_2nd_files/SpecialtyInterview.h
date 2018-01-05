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


typedef std::priority_queue<Interview> HEAP_INTRVW;

class SpecialtyInterview {
private:
	unsigned int id;
	std::string specialty;
	HEAP_INTRVW interViews;

public:
	SpecialtyInterview(unsigned int id, std::string specialty, HEAP_INTRVW interViews);

	std::string getSpecialty() const;
	HEAP_INTRVW getInterviews() const;

};

#endif //_INTERVIEW_H