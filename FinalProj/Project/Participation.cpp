#include "Participation.h"

Participation::Participation(unsigned int auditionId, unsigned int place, unsigned int chiefJudgeGrade) {
		this->auditionId = auditionId;
		this->place = place;
		this->chiefJudgeGrade = chiefJudgeGrade;
	}

unsigned int Participation::getAuditionId() const { return auditionId; }
unsigned int Participation::getPlace() const { return place; }
unsigned int Participation::getChiedJudgeGrade() const { return chiefJudgeGrade; }

void Participation::setAuditionId(unsigned int auditionId) { this->auditionId = auditionId; }
void Participation::setPlace(unsigned int place) { this->place = place; }
void Participation::setChiefJudgeGrade(unsigned int chiefJudgeGrade) { this->chiefJudgeGrade = chiefJudgeGrade; }
