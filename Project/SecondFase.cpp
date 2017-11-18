/**
 * Project Untitled
 */


#include "SecondFase.h"
#include "Fase.h"

using namespace std;

SecondFase::SecondFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld, vector<unsigned int> contestants) :Fase(auditionId, final_grade, ev1, ev2, ld, contestants) {
}

SecondFase::SecondFase(string textLine) : Fase(textLine) {

}
void SecondFase::overallGrading() {
	for (size_t i = 0; i < contestants.size(); i++) {
		finalGrade[i] = (judge1[i] + judge2[i] + 2*chiefJudge[i]) / 3;
	}
}

//Operator overloading
ostream& operator<<(ostream& os, const SecondFase & secondFase) {

	os << secondFase.getAuditionId() << " ; ";
	vector<double> finalGrade = secondFase.getFinalGrade();
	vector<unsigned int> judge1 = secondFase.getJudge1();
	vector<unsigned int> judge2 = secondFase.getJudge2();
	vector<unsigned int> chiefJudge = secondFase.getChiefJudge();
	vector<unsigned int> contestants = secondFase.getContestants();

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


