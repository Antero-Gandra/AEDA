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
		final_grade[i] = (judge1[i] + judge2[i] + chiefJudge[i])/3;
	}
}
