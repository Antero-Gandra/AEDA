#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Calendar.h"


class Application {
public:
	Calendar date;
	unsigned int contestantId;
	Application(Calendar date, unsigned int contestantId);
	bool operator <(const Application & application);
};

#endif //_AUDITION_H
