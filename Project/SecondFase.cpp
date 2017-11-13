/**
 * Project Untitled
 */


#include "SecondFase.h"

/**
 * SecondFase implementation
 */
SecondFase::SecondFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld) :Fase(auditionId, final_grade, ev1, ev2, ld) {
}

SecondFase::SecondFase(string textLine) : Fase(textLine) {

}