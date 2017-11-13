/**
 * Project Untitled
 */


#include "FirstFase.h"
#include <sstream>
#include "Util.h"

 /**
  * FirstFase implementation
  */

FirstFase::FirstFase(unsigned int auditionId, vector<unsigned int> final_grade, vector<unsigned int> ev1, vector<unsigned int> ev2, vector<unsigned int> ld) :Fase(auditionId, final_grade, ev1, ev2, ld) {
}
FirstFase::FirstFase(string textLine) : Fase(textLine) {

}