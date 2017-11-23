#ifndef _AUDITION_H
#define _AUDITION_H

#include "FirstFase.h"
#include "SecondFase.h"
#include <string>
#include <vector>
#include "Calendar.h"
#include <ios>

class Audition {
private: 
    unsigned int id;
    Calendar start;
	Calendar end;
    std::string specialty;
	std::vector<unsigned int> judgesId;
	unsigned int chiefJudgeId;
	FirstFase* firstFase;
	SecondFase* secondFase;
public:
	/**
	* @brief Audition contructor with its id, start and end date, speciality, judges' id and reposible judge's id.
	* @param id an unsigned integer
	* @param start a Calendar Object
	* @param end a Calendar Object
	* @param speciality a string
	* @param judgesID a vector of unsigned integers
	* @param chiefJudge an unsigned integer
	*/
	Audition(unsigned int id, Calendar start, Calendar end, std::string specialty, std::vector<unsigned int> judgesId, unsigned int chiefJudgeId, std::vector<unsigned int> contestants);
	/**
	* @brief Audition contructor by reading the file
	*/
	Audition(std::string textline);
	/**
	* @brief Audition Decontructor
	*/
	~Audition();
	
	/**
	* Retrieves the ID of the specific Audition
	* @return constant unsigned integer ID of the Audition
	*/
	unsigned int getId() const;

	/**
	* Retrieves the starting date of the specific Audition
	* @return constant Calendar of the Audition
	*/
	Calendar getStart() const;
	
	
	/**
	* Retrieves the ending date of the specific Audition
	* @return constant Calendar of the Audition
	*/
	Calendar getEnd() const;
	
	/**
	* Retrieves the speciality of the specific Audition
	* @return constant string speciality of the Audition
	*/
	std::string getSpecialty() const;
	
	/**
	* Retrieves the judges' ID of the specific Audition
	* @return constant vector of unsigned integers Judges' ID of the Audition
	*/
	std::vector<unsigned int> getJudgesId() const;
	
	/**
	* Retrieves the judge's in charge ID of the specific Audition
	* @return constant unsigned integer Judge's ID of the Audition
	*/
	unsigned int getChiefJudgeId() const;
	
	/**
	* Retrieves the First Phase of the specific Audition
	* @return constant First Phase pointer's object of the Audition
	*/
	FirstFase* getFirstFase() const;
	
	
	/**
	* Retrieves the Second Phase of the specific Audition
	* @return constant Second Phase pointer's object of the Audition
	*/SecondFase* getSecondFase() const;

	/**
	* Changes the ID of the Audition
	* @param id an unsigned integer
	*/
	void setId(unsigned int id);
	
	/**
	* Changes the starting date of the Audition
	* @param start a Calendar object
	*/
	void setStart(Calendar start);
	
	/**
	* Changes the ending date of the Audition
	* @param end a Calendar object
	*/
	void setEnd(Calendar end);
	
	/**
	* Changes the specialty of the Audition
	* @param speciality a string
	*/
	void setSpecialty(std::string specialty);
	
	/**
	* Changes the judge's ID of the Audition
	* @param evaluators a vector of unsigned integers
	*/
	void setJudgesId(std::vector<unsigned int> evaluators);
	
	/**
	* Changes the Judge's in charge ID of the Audition
	* @param chiefJudgeId an unsigned int
	*/
	void setChiefJudgeId(unsigned int chiefJudgeId);
	
	/**
	* Changes First Phase of the Audition
	* @param firstFase a FirstFase object pointer
	*/
	void setFirstFase(FirstFase * firstFase);
	
	/**
	* Changes Second Phase of the Audition
	* @param secondFase a SecondFase object pointer
	*/
	void setSecondFase(SecondFase *  secondFase);

	/**
	* Operator "<" is overloaded to compare the ID value of the Object Audition with a specific Audition
	* @param audition1 a constant Audition reference
	* @return true if the Object is greater than audition1's id and false if the Object is lesser than audition1's id
	*/
	bool operator<(const  Audition & audition1) const;

	/**
	* Operator "==" is overloaded to check if the Object Audition is equal to another given Audition in case they share the same properties
	* @param audition1 a constant Audition reference
	* @return true if the Object is equal to audition1's properties and false if the Object is not equal to audition1's properties
	*/
	bool operator==(const Audition & audition1) const;

	/**
	* Operator "<<" is overloaded to output the information about the Audition into a file
	* @param os an Outstream Object
	* @param audition1 a constant Audition reference
	* @return the information of the Audition in a specific format into a file
	*/
	friend std::ostream& operator<<(std::ostream& os, const Audition & audition1);

	/**
	* Grades the contestants of the Object Audition for the First Phase and sorts them by grade; splits the contestants who were and were not qualified
	* @return vector of unsigned integers of the contestants sorted by grade of those who didn't qualified to second phase
	*/
	std::vector<unsigned int> gradeFirstFase();

	/**
	* Grades the contestants of the Object Audition for the Second Phase and sorts them by grade
	* @return vector of unsigned integers of the contestants sorted by grade
	*/
	std::vector<unsigned int> gradeSecondFase();

	/**
	* @brief Prints the Audition's full information on the screen
	*/
	void show();
};

#endif //_AUDITION_H
