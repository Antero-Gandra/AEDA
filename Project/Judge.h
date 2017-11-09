#ifndef _JUDGE_H
#define _JUDGE_H

#include "Person.h"


class Judge: public Person {
private: 
private:
    unsigned int id;
    vector<unsigned int> participation;
public:
	Judge() {}
	Judge(unsigned int id, vector<unsigned int> participation);
	Judge(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation);
	//Get Methods
	unsigned int getId() const;
	vector<unsigned int> getParticipation() const;
	//Set Methods
	void setId(unsigned int id);
	void setParticipation(vector<unsigned int> participation);
};

#endif //_JUDGE_H#endif //_JUDGE_H
