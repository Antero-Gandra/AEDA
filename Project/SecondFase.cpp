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
		final_grade[i] = (judge1[i] + judge2[i] + 2*chiefJudge[i]) / 3;
	}
}


