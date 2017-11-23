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
	* @brief Check which Application object is smaller
	* @param application an Application Object constant reference
	* @return true if Object is smaller than application, false otherwise
	*/
	bool operator <(const Application & application);
	Calendar getDate() const;
	unsigned int getContestantId() const;

	void setDate(Calendar date);
	void setContestantId(unsigned int contestantId);
};

#endif //_AUDITION_H
