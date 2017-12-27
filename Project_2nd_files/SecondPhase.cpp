/**
 * Project Untitled
 */


#include "SecondPhase.h"
#include "Phase.h"

using namespace std;

SecondPhase::SecondPhase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld, vector<unsigned int> contestants) :Phase(auditionId, final_grade, ev1, ev2, ld, contestants) {
}

SecondPhase::SecondPhase(string textLine) : Phase(textLine) {

}
void SecondPhase::overallGrading() {
	for (size_t i = 0; i < contestants.size(); i++) {
		finalGrade.push_back((double)(judge1[i] + judge2[i] + 2*chiefJudge[i]) / 4);
	}
}

//Operator overloading
ostream& operator<<(ostream& os, const SecondPhase & secondPhase) {

	os << secondPhase.getAuditionId() << " ; ";
	vector<double> finalGrade = secondPhase.getFinalGrade();
	vector<unsigned int> judge1 = secondPhase.getJudge1();
	vector<unsigned int> judge2 = secondPhase.getJudge2();
	vector<unsigned int> chiefJudge = secondPhase.getChiefJudge();
	vector<unsigned int> contestants = secondPhase.getContestants();

	for (size_t i = 0; i < contestants.size(); i++) {
		os << contestants[i] << " , ";
	}
	os << " ; ";
	for (size_t i = 0; i < judge1.size(); i++) {
		os << judge1[i] << " , ";
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
	for (size_t i = 0; i < finalGrade.size(); i++) {
		os << finalGrade[i] << " , ";
	}
	os << " ; ";
	return os;
}


