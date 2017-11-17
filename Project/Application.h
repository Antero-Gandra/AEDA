#ifndef _APPLICATION_H
#define _APPLICATION_H

#include "Calendar.h"


class Application {
public:
	Calendar date;
	unsigned int contestantId;
	Application(Calendar date, unsigned int contestantId);
};

#endif //_AUDITION_H
