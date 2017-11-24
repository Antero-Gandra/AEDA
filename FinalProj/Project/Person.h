/**
* Project Untitled
*/


#ifndef _PERSON_H
#define _PERSON_H

#include "Calendar.h"


class Person {
protected:
	std::string name;
	std::string address;
	unsigned int mobile;
	Calendar dob;
	std::string specialty;
public:
	/**
	* @brief Person Default Contructor
	*/
	Person() {};

	/**
	* @brief Person Contructor with their id, name, address, mobile phone number, date of birth and specialiy
	* @param id an unsigned integer
	* @param name a string
	* @param address a string
	* @param mobile an unsigned int
	* @param dob a Calendar Object
	* @param specialiy a string
	*/
	Person(std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty);

	/**
	* @brief Manages to access the Person's name
	* @return string Person's name
	*/
	std::string getName() const;

	/**
	* @brief Manages to access the Person's address
	* @return string Person's adress
	*/
	std::string getAddress() const;

	/**
	* @brief Manages to access the Person's mobile
	* @return unsigned integer Person's mobile
	*/
	unsigned int getMobile() const;

	/**
	* @brief Manages to access the Person's date of birth
	* @return Calendar Object Person's date of birth
	*/
	Calendar getDob() const;

	/**
	* @brief Manages to access the Person's specialiy
	* @return string Person's specialiy
	*/
	std::string getSpecialty() const;

	/**
	* @brief Changes Judge's name
	* @param name a string
	*/
	void setName(std::string name);

	/**
	* @brief Changes Judge's address
	* @param address a string
	*/
	void setAddress(std::string address);

	/**
	* @brief Changes Judge's mobile
	* @param mobile an unsigned integer
	*/
	void setMobile(unsigned int mobile);

	/**
	* @brief Changes Judge's date of birth
	* @param dob a Calendar Object
	*/
	void setDob(Calendar dob);

	/**
	* @brief Changes Judge's specialty
	* @param specialty a string
	*/
	void setSpecialty(std::string specialty);

	/**
	* @brief Randomly generates a mobile number
	* @return unsigned int of the mobile number
	*/
	unsigned int mobileGenerator();
};

#endif //_PERSON_H
