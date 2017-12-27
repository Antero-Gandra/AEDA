#ifndef _UNAVAILABLE_CONTESTANT_H
#define  _UNAVAILABLE_CONTESTANT_H

#include "Contestant.h"
#include <fstream>
#include "Calendar.h"

class UnavailableContestant : public Contestant {
	Calendar unavailablePeriodBegin;
	Calendar unavailbalePeriodEnd;
	std::string reason;
public:
	UnavailableContestant(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<Participation*> participation, Calendar unavailablePeriodBegin, Calendar unavailablePeriodEnd, std::string reason);
	//No need for destructor since there is no memory allocated
};
struct UContestantPtr {
	UnavailableContestant * uCont;
};

#endif //_UNAVAILABLECONTESTANT_H
