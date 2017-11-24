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
	* @param application an Application Object constant reference
	*/
	bool operator <(const Application & application);
	Calendar getDate() const;
	unsigned int getContestantId() const;

	void setDate(Calendar date);
	void setContestantId(unsigned int contestantId);
};

#endif //_AUDITION_H
