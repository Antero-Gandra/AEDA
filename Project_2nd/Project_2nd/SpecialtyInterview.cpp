#include "SpecialtyInterview.h"

using namespace std;

Interview::Interview(unsigned int idInt, unsigned int contesID, unsigned int audID) :
	id(idInt), contestantID(contesID), auditionID(audID) {}

unsigned int Interview::getID() const {
	return id;
}

unsigned int Interview::getContestantID() const {
	return contestantID;
}

unsigned int Interview::getAuditionID() const {
	return auditionID;
}