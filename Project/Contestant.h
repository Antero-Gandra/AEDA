/**
* Project Untitled
*/


#ifndef _CONTESTANT_H
#define _CONTESTANT_H

#include "Person.h"
#include <fstream>
#include "Participation.h"
#include "Calendar.h"

class Contestant : public Person {
	unsigned int id;
	std::vector<Participation*> participations;

public:
	/**
	* @brief Contestant Contructor with their id, name, address, mobile phone number, date of birth, specialiy and list of participations by id
	* @param id an unsigined integer
	* @param name a string
	* @param address a string
	* @param mobile an unsigined int
	* @param dob a Calendar Object
	* @param specialiy a string
	* @param participation a vector of unsigined int
	*/
	Contestant(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<unsigned int> participation);

	/**
	* @brief Contestant Contructor by reading a line from Contestant file
	*/
	Contestant(std::string textLine);

	/**
	* @brief Manages to access the Contestant's ID value
	* @return unsigned integer of the Contestant's ID
	*/
	unsigned int getId() const;

	/**
	* @brief Manages to access all participations that the specified Contestant has had
	* @return a contestant vector of participations pointers from the specified Contestant
	*/
	std::vector<Participation*> getParticipations() const;

	/**
	* @brief Changes the ID of a current Contestant
	* @param id an unsigned integer argument
	*/
	void setId(unsigned int id);
	/**
	* @brief Changes the participations of a current Contestant
	* @param participation a vector of Participation pointers
	*/
	void setParticipations(std::vector<Participation*> participation);
	/**
	* @brief Prints the Contestant's full information on the screen
	*/
	void show() const;

	/**
	* Operator "<" is overloaded to compare the ID value of the Object Contestant with a specific Contestant
	* @param contestant1 a constant Contestant reference
	* @return true if the Object is greater than contestant1's id and false if the Object is lesser than contestant1's id
	*/
	bool operator<(const Contestant & contestant1) const;

	/**
	* @bfief Operator "==" is overloaded to check if the Object Contestant is equal to another given Contestant in case they share the same properties
	* @param contestant1 a constant Contestant reference
	* @return true if the Object is equal to contestant1's properties and false if the Object is not equal to contestant1's properties
	*/
	bool operator==(const Contestant & contestant1) const;

	/**
	* @bfief Operator "<<" is overloaded to output the information about the Contestant into a file
	* @param contestant1 a constant Contestant reference
	* @return ostream reference
	*/
	friend std::ostream& operator<<(std::ostream& os, const Contestant & contestant);
};

#endif //_CONTESTANT_H
