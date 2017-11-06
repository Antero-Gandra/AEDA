/**
 * Project Untitled
 */


#ifndef _FASE_H
#define _FASE_H

class Fase {
	unsigned int auditionId;
public:
	Fase() {}
	Fase(unsigned int auditionId);
	//Get Mehods
	unsigned int getAuditionId() const;
	//Set Methods
	void setAuditionId(unsigned int auditionId);
};

#endif //_FASE_H