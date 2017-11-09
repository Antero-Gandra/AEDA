#include "Judge.h"


Judge::Judge(unsigned int id, vector<unsigned int> participation) : Person() {
	this->id = id;
	this->participation = participation;
}
Judge::Judge(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation): Person(name, address, mobile, dob, specialty), id(id), participation(participation) {}


//Set Methods
unsigned int Judge::getId() const {return id;}
vector<unsigned int> Judge::getParticipation() const { return participation; }


//Get Methods
void Judge::setId(unsigned int id){this->id=id;}
void Judge::setParticipation(vector<unsigned int> participation) { this->participation = participation; };
