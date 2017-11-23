#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Calendar.h"


class Application {
public:
	Calendar date;
	unsigned int contestantId;
	/**
	* @brief Application Contructor
	*/
	Application(Calendar date, unsigned int contestantId);
	/**
	* @brief Check which Application object is smaller
	* @param application an Application Object constant reference
	* @return true if Object is smaller than application, false otherwise
	*/
	bool operator <(const Application & application);
};

#endif //_AUDITION_H
