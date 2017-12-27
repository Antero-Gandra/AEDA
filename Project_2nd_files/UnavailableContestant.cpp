#include "UnavailableContestant.h"
#include "Contestant.h"
#include "Util.h"
#include <limits>

using namespace std;

UnavailableContestant::UnavailableContestant(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<Participation*> participation, Calendar unavailablePeriodBegin, Calendar unavailablePeriodEnd, string reason) : Contestant(id, name, address, mobile, dob, specialty, participation) {
	this->unavailablePeriodBegin = unavailablePeriodBegin;
	this->unavailbalePeriodEnd = unavailablePeriodEnd;
	this->reason = reason;
}


