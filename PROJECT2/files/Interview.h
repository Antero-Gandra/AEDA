#ifndef _INTERVIEW_H
#define _INTERVIEW_H

#include "Contestant.h"
#include "Audition.h"
#include "Calendar.h"
#include <string>
#include <stack>
#include <queue>
#include "Company.h"

struct ContestantPTR {
	Contestant *contestant;
	Company *company;
};

struct ContestantPTRCompare{
	Company * company;
	bool operator()(const ContestantPTR& c1, const ContestantPTR& c2) const {
		Company temp = * this->company;
		auto participation1 = c1.contestant->getParticipations();
		auto participation2 = c2.contestant->getParticipations();
		auto auditionId1 = participation1[participation1.size()]->getAuditionId();
		auto auditionId2 = participation2[participation2.size()]->getAuditionId();
		auto audition1 = temp.getAuditionById(auditionId1);
		auto audition2 = temp.getAuditionById(auditionId2);
		auto calendar1 = audition1->getStart();
		auto calendar2 = audition2->getStart();
		return (calendar1 > calendar2) ? true: false;
	}
};

#endif //_INTERVIEW_H
