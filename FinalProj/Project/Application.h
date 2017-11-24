#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Calendar.h"


class Application {

	Calendar date;
	unsigned int contestantId;
public:
	/**
	* @brief Application Contructor
	* @param date a Calendar Object
	* @param contestantId an unsigned integer
	*/
	Application(Calendar date, unsigned int contestantId);
	
	/**
	* @brief Overloads operator "<" to check the most recent date from two Application Objects
	* @param application an Application Object constant reference
	* @return true if Application Object date is the most recent compared to application's date, false otherwise
	*/
	bool operator <(const Application & application);
	
	/**
	* @brief Manages to provide the date
	* @return Calendar Object from the application
	*/
	Calendar getDate() const;
	
	/**
	* @brief Manages to provide the id of the contestant
	* @return unsigned int that is id of the contestant the application belongs to
	*/
	unsigned int getContestantId() const;

	/**
	* @brief Changes the date of the application
	* @param date a Calendar Object
	*/
	void setDate(Calendar date);

	/**
	* @brief Changes the id of the contestant the application belongs to
	* @param contestantId an unsigned integer
	*/
	void setContestantId(unsigned int contestantId);
};

#endif //_AUDITION_H
