/**
 * Project Untitled
 */


#include "FirstFase.h"
#include "Fase.h"
#include <sstream>
#include "Util.h"

using namespace std;

FirstFase::FirstFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld, vector<unsigned int> contestants) :Fase(auditionId, final_grade, ev1, ev2, ld, contestants) {
}
FirstFase::FirstFase(string textLine) : Fase(textLine) {
}

void FirstFase::overallGrading() {
	for (size_t i = 0; i < contestants.size(); i++) {
		finalGrade.push_back((double)(judge1[i] + judge2[i] + chiefJudge[i])/3);
	}
}

//Operator overloading
ostream& operator<<(ostream& os, const FirstFase & firstFase) {

	os << firstFase.getAuditionId() << " ; ";
	vector<double> finalGrade = firstFase.getFinalGrade();
	vector<unsigned int> judge1 = firstFase.getJudge1();
	vector<unsigned int> judge2 = firstFase.getJudge2();
	vector<unsigned int> chiefJudge = firstFase.getChiefJudge();
	vector<unsigned int> contestants = firstFase.getContestants();

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
