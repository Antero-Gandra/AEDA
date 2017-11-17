#ifndef _JUDGE_H
#define _JUDGE_H

#include "Person.h"
#include <vector>

#include "Calendar.h"

class Judge: public Person {
private:
    unsigned int id;
    std::vector<unsigned int> participations;
public:
	//Constructors
	Judge() {}
	Judge(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<unsigned int> participation);
	Judge(std::string textline);
	//Get Methods
	unsigned int getId() const;
	std::vector<unsigned int> getParticipations() const;
	//Set Methods
	void setId(unsigned int id);
	void setParticipations(std::vector<unsigned int> participation);

	//Operator overloading
	bool operator<(const Judge & judge1) const ;
	bool operator==(const Judge & judge1) const;
	friend std::ostream& operator<<(std::ostream& os, const Judge& judge);

	//Other Methods
	void show();
};

#endif //_JUDGE_H
