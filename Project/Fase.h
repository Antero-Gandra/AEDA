/**
 * Project Untitled
 */

#ifndef _FASE_H
#define _FASE_H

#include <vector>
#include <string>

class Fase {
	unsigned int auditionId;
	std::vector<unsigned int> final_grade;
	std::vector<unsigned int> ev1;
	std::vector<unsigned int> ev2;
	std::vector <unsigned int> ld;
	std::vector<unsigned int> contestants;
public:
	Fase() {}
	Fase(unsigned int auditionId, std::vector<unsigned int> final_grade, std::vector<unsigned int> ev1, std::vector<unsigned int> ev2, std::vector<unsigned int> ld);
	Fase(std::string textline);
	//Get Methods
	unsigned int getAuditionId() const;
	//Set Methods
	void setAuditionId(unsigned int auditionId);
};

#endif //_FASE_H
