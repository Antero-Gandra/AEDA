/**
* Project Untitled
*/


#ifndef _PERSON_H
#define _PERSON_H

#include "Calendar.h"


class Person {
public:
	/**
	* @brief Person Default Contructor
	*/
	Person() {};

	/**
	* @brief Person Contructor with their id, name, address, mobile phone number, date of birth and specialiy
	*/
	Person(std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty);

	/**
	* @brief Manages to access the Person's name
	* @return string Person's name
	*/
	/**
	* @brief Manages to access the Person's address
	* @return string Person's adress
	*/
	/**
	* @brief Manages to access the Person's mobile
	*/
	/**
	* @brief Manages to access the Person's date of birth
	* @return Calendar Object Person's date of birth
	*/
	/**
	* @brief Manages to access the Person's specialiy
	* @return string Person's specialiy
	*/
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
	*/

	unsigned int mobileGenerator();
};

#endif //_PERSON_H
