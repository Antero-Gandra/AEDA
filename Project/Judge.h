#ifndef _JUDGE_H
#define _JUDGE_H

#include "Person.h"

class Judge: public Person {
private:
    unsigned int id;
    vector<unsigned int> participations;
public:
	//Constructors
	Judge() {}
	Judge(unsigned int id, string name, string address, unsigned int mobile, Time dob, string specialty, vector<unsigned int> participation);
	Judge(string textline);
	//Get Methods
	unsigned int getId() const;
	vector<unsigned int> getParticipations() const;
	//Set Methods
	void setId(unsigned int id);
	void setParticipations(vector<unsigned int> participation);

	//Operator overloading
	bool operator<(const Judge & judge1) const ;
	bool operator==(const Judge & judge1) const;
	friend ostream& operator<<(ostream& os, const Judge& person);

	//Other Methods
	void show();
};

#endif //_JUDGE_H
