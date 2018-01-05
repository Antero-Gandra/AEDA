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


SpecialtyInterview::SpecialtyInterview(unsigned int id, std::string specialty, HEAP_INTRVW interinterViewsviews) :
	specialty(specialty), interViews(interViews) {}


void addInterview(unsigned int id, unsigned int contestantID, unsigned int auditionID) {


}