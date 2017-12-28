#ifndef _UNAVAILABLECONTESTANT_H
#define  _UNAVAILABLECONTESTANT_H

#include "Contestant.h"
#include <fstream>
#include "Calendar.h"

class UnavailableContestant : public Contestant {
	Calendar unavailabilityBegin;
	Calendar unavailabilityEnd;
	std::string reason;
public:
	Calendar getUnavailabilityEnd() const;
	UnavailableContestant(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<Participation*> participation, Calendar unavailabilityBegin, Calendar unavailabilityEnd, std::string reason);
	UnavailableContestant(std::string textLine);
	UnavailableContestant(Contestant * contestant, Calendar unavailabilityBegin, Calendar unavailabilityEnd, std::string reason);
	void show();
	friend std::ostream& operator<<(std::ostream& os, const UnavailableContestant & contestant);
};
struct UContestantPtr {
	UnavailableContestant * uCont;
};

#endif //_UNAVAILABLECONTESTANT_H