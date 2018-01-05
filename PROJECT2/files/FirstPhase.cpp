/**
 * Project Untitled
 */


#include "FirstPhase.h"
#include "Phase.h"
#include <sstream>
#include "Util.h"

using namespace std;

FirstPhase::FirstPhase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld, vector<unsigned int> contestants) :Phase(auditionId, final_grade, ev1, ev2, ld, contestants) {
}
FirstPhase::FirstPhase(string textLine) : Phase(textLine) {
}

void FirstPhase::overallGrading() {
	for (size_t i = 0; i < contestants.size(); i++) {
		finalGrade.push_back((double)(judge1[i] + judge2[i] + chiefJudge[i])/3);
	}
}

//Operator overloading
ostream& operator<<(ostream& os, const FirstPhase & firstPhase) {

	os << firstPhase.getAuditionId() << " ; ";
	vector<double> finalGrade = firstPhase.getFinalGrade();
	vector<unsigned int> judge1 = firstPhase.getJudge1();
	vector<unsigned int> judge2 = firstPhase.getJudge2();
	vector<unsigned int> chiefJudge = firstPhase.getChiefJudge();
	vector<unsigned int> contestants = firstPhase.getContestants();

	for (size_t i = 0; i < contestants.size(); i++) {
		os << contestants[i] << " , ";
	}
	os << " ; ";
	for (size_t i = 0; i < judge1.size(); i++) {
		os << judge1[i] << " , " ;
	}
	os << " ; ";
	for (size_t i = 0; i < judge2.size(); i++) {
		os << judge2[i] << " , ";
	}
	os << " ; ";
	for (size_t i = 0; i < chiefJudge.size(); i++) {
		os << chiefJudge[i] << " , ";
	}
	os << " ; ";
	for (size_t i = 0; i < finalGrade.size() ; i++) {
		os << finalGrade[i] << " , ";
	}
	os << " ; ";
	return os;
}
