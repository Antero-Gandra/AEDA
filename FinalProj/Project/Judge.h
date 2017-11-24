#ifndef _JUDGE_H
#define _JUDGE_H

#include "Person.h"
#include <vector>

#include "Calendar.h"

class Judge : public Person {
private:
	unsigned int id;
	std::vector<unsigned int> participations;
public:
	/**
	* @brief Judge Default Contructor
	*/
	Judge() {}

	/**
	* @brief Judge Contructor with their id, name, address, mobile phone number, date of birth, specialiy and list of participations by id
	* @param id an unsigined integer
	* @param name a string
	* @param address a string
	* @param mobile an unsigined integer
	* @param dob a Calendar Object
	* @param specialiy a string
	* @param participation a vector of unsigined integer
	*/
	Judge(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<unsigned int> participation);

	/**
	* @brief Judge Contructor by reading a line from Judge file
	* @param textline a string
	*/
	Judge(std::string textline);

	/**
	* @brief Manages to access the Judge's ID value
	* @return Judge's ID
	*/
	unsigned int getId() const;

	/**
	* @brief Manages to access all participations that the specified Judge has had
	* @return a constant vector of participations from the specified Judge
	*/
	std::vector<unsigned int> getParticipations() const;

	/**
	* @brief Changes Judge's ID
	* @param id an unsigined integers
	*/
	void setId(unsigned int id);

	/**
	* @brief Changes the participations the judge was in
	* @param participation a vector of unsigined integers
	*/
	void setParticipations(std::vector<unsigned int> participation);

	/**
	* @brief Operator "<" is overloaded to compare the ID value of the Object with a specific Judge
	* @param judge1 a constant Judge reference
	* @return true if the Object is greater than judge1 and false if the Object is lesser than judge1
	*/
	bool operator<(const Judge & judge1) const;

	/**
	* @bfief Operator "==" is overloaded to check if the Object Judge is equal to another given Judge in case they share the same properties
	* @param judge1 a constant Judge reference
	* @return true if the Object is equal to judge1's properties and false if the Object is not equal to judge1's properties
	*/
	bool operator==(const Judge & judge1) const;

	/**
	* @bfief Operator "<<" is overloaded to output the information about the Judge into a file
	* @param os an Output Stream Object referece
	* @param judge a constant Judge reference
	*/
	friend std::ostream& operator<<(std::ostream& os, const Judge& judge);

	/**
	* @brief Prints the Judge's full information on the screen
	*/
	void show();
};

#endif //_JUDGE_H
