/**
 * Project Untitled
 */


#include "Contestant.h"

/**
 * Contestant implementationsssss
 */

Contestant::Contestant(unsigned int id, string name, string address, unsigned int mobile, unsigned int dob, string specialty, std::vector<unsigned int> participation): Person(name, address, mobile, dob, specialty), id(id), participation(participation) {

}
