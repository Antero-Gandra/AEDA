#ifndef _COMPANYMS_H
#define _COMPANYMS_H


#include <cstdlib>
#include <vector>

#include "Calendar.h"
#include "Company.h"

class CompanyMS {
	static Calendar currentCalendar;
public:
	//Constructor
	/**
	* @brief CompanyMS constructor
	* @param company as Company Object pointer
	*/
	CompanyMS(Company * company);

	/**
	* @brief Ivokes the current time, reads and imports to the specific data structure
	*		all the required files (contestants, applications, judges and auditions)
	*		while invoking the main menu
	*/
	void run();

	/**
	* @brief Invokes the main menu so that the user selects what option to pick, either manage contestant, judge or audition
	*/
	void mainMenu();

	void saveMenu();

	/**
	* @brief Invokes the contestant menu with the CRUD option and also to read from a file to update the database;
	*		manages to either view all contestants, view contestants by specialty, or who won castings;
	*		manages to search contestant by id or name; remove a contestant's applications;
	*		reading applications from a file and to view all applications
	*/
	void contestantMenu();


	/**
	* @brief Invokes the judge menu with the CRUD option and also to read from a file to update the database;
	*		manages to either view all contestants, view contestants by specialty, or who won castings;
	*		manages to search contestant by id or name
	*/
	void judgeMenu();


	/**
	* @brief Invokes the audition menu, where schedule a simple audition or schedule the maximum number
	*		of auditions you can possibly get overall or by speciality; modify or disassemble an audition;
	*		evaluate one or all auditions, and evaluates the phases individually; prints all auditions
	*/
	void auditionMenu();


	//CONTESTANTS MENUS


	/**
	* @brief Invokes the contestant menu, where it asks if the contestant is already on the database by printing all the candidates;
	*		 if not, it will be enable to create a new contestant
	*/
	void enrollAContestantMenu();


	/**
	* @brief Invokes the menu where any information field of a given contestant can be modify. If the case is the contestant's speciality, then all applications
	*		 will be removed but the partitipatins kept
	*/
	void modifyContestantMenu();


	/**
	* @brief Invokes the menu where contestant from the database can be removed and intrinsically removing all their applications	
	*/
	void removeContestantMenu();

	/**
	*/
	void showContestantsByIdMenu();

	void showContestantsByNameMenu();

	void showContestantsOfSpecialtyMenu();

	/**
	* @brief Invokes the menu where it shows if the contestant's id exists and if so, show's it
	*/
	void searchContestantByIdMenu();

	/**
	*/
	void removeContestantsApplicationsMenu();

	/**
	* @brief Invokes the menu where it shows the applications from all candidates
	*/
	void showApplicationsMenu();


	//JUDGES MENUS

	/**
	* @brief Invokes the creation of a judge menu, if the judge already exists it will not add it to the database
	*/
	void employJudgeMenu();

	/**
	* @brief Invokes the menu where it information field of a given judge can be modify
	*/
	void modifyJudgeMenu();

	/**
	* @brief Invokes the menu where you can remove a judge from the database
	*/
	void fireJudgeMenu();

	/**
	*/
	void showJudgesByIdMenu();
	void showJudgesByNameMenu();
	void showJudgesOfSpecialtyMenu();

	/**
	* @brief Invokes a menu where it searches for a judge with a specific id
	*/
	void searchJudgeByIdMenu();


	//AUDITIONS

	/**
	* @brief Invokes a menu where an audition is scheduled by specifically inputing the speciality it will be about and
	*		 adding the contestants from that speciality with a minimum of 6 and maximum of 24 contestants, inputing a zero to end the enrolment on the audition
	*/
	void scheduleAuditionMenu();

	/**
	* @brief Invokes a menu where it will schedule the maximum auditions possible
	*/
	void scheduleMaxAuditionsMenu();

	/**
	* @brief Invokes a menu where it will schedule the maximum auditions, of a given specialty, possible
	*/
	void scheduleMaxAuditionsOfSpecialtyMenu();

	/**
	*/
	void disassembleAuditionMenu();
	
	/**
	* @brief Invokes a menu where it evaluates a given audition
	*/
	void evaluateAuditionMenu();

	/**
	* @brief Invokes a menu where it evaluates all possible auditions
	*/
	void evaluateAllAuditionsMenu();

	/**
	* @brief Invokes a menu where it prints all the auditions information
	*/
	void showAuditionsMenu();


	//CANDIDATES SHOW FUNCTIONS

	/**
	*/
	void showContestants();
	void showContestantsByName();

	void showPartialContestants(unsigned int limInf, unsigned int limSup);

	/**
	* @brief Prints the date that a contestant applied to an audition
	*/
	void showApplications();

	/**
	* @brief Prints the date that a contestant applied to an audition of a specified specialty
	*/
	void showApplicationsOfSpecialty(std::string specialty);

	/**
	*/
	void showJudges();

	void showPartialJudges(unsigned int limInf, unsigned int limSup);

	/**
	* @brief Prints the auditions from the specified id
	* @param id as unsigned int
	**/
	void showAudition(unsigned int id);
	void showAuditions();

	
	//INPUT HANDLING

	/**
	* @brief Check if an option given rests between an inferior and superior limit
	* @param option a string
	* @param infLim an unsigned integer
	* @param supLim an unsigned integer
	* @return true if the option is between infLim and supLim, false otherwise
	*/
	bool isValidOption(std::string option, unsigned int infLim, unsigned int supLim);

	/**
	* @brief Checks if the string inputed is either yes or no
	* @param answer a string
	* @return true if the string has either "y", "Y", "n", "N", false otherwise
	*/
	bool isYesOrNo(std::string answer);

	/**
	* @brief Checks if the string inputed is a valid contestant id
	* @param id a string
	* @return true if it is valid by checking the database, false otherwise
	*/
	bool isValidContestantId(std::string id);
	
	/**
	* @brief Checks if the string inputed is a valid judge id
	* @param id a string
	* @return true if it is valid by checking the database, false otherwise
	*/
	bool isValidJudgeId(std::string id);
	
	/**
	* @brief Checks if the string inputed is a valid contestant id
	* @param id a string
	* @return true if it is valid by checking the database, false otherwise
	*/
	bool isValidAuditionId(std::string id);

	bool isSpecialValidContestantId(std::string id);
	
	/**
	* @brief Checks if the string inputed is a valid
	* @param s a string
	* @return true if it is valid, false otherwise
	*/
	bool isValidString(std::string s);

	/**
	* @brief Checks if the date of birth is a valid output
	* @param dob a Calendar Object
	*/
	bool isValidDob(Calendar dob);

	/**
	* @brief Validates if the input is a number
	* @param number a string
	* @return true if number is valid, false otherwise
	*/
	bool isValidNumber(std::string number);

	/**
	@brief Prints if the option handled is valid or not by calling the function isValidOption
	@param infLim an unsigned integer
	@param supLim an unsigned integer
	@return a number different of zero if succeed, zero otherwise
	*/
	unsigned int optionHandler(unsigned int infLim, unsigned int supLim);

	/**
	* @brief Validates a yes or no question input
	* @return true if the input is either "y" or "Y" and false if the input is "n" or "N"
	*/
	bool yesNoHandler();

	/**
	* @return unsigned int
	*/
	unsigned int contestantIdHandler();
	unsigned int specialContestantIdHandler();
	
	/**
	* @return unsigned int
	*/
	unsigned int judgeIdHandler();

	/**
	* @brief Checks if the input string is valid and not empty
	* @param type as string
	* @return string
	*/
	std::string stringHandler(std::string type);

	/**
	* @brief Validates if the date of birth input is valid
	* @return Calendar Object
	*/
	Calendar dobHandler();

	/**
	* @brief Validates if the input is a valid speciality
	* @return string
	*/
	std::string specialtyHandler();

	/**
	* @brief Checks is the input is not empty and if it is a numerical value
	* @param type as string
	* @return unsigned integer
	*/
	unsigned int numberHandler(std::string type);

	//FILE SYNC

	/**
	* @brief Updates the changes on the data structure to the files
	*/
	void updateFilesHandler();

	//APPEARANCE

	/**
	* @param text as string
	* @param colour as unsigned int
	* @param dark as bool
	*/
	void printInColour(std::string text, unsigned  int colour, bool dark);

	/**
	* @brief Clears the screen when calling other menus
	*/
	void clearScreen();

	void mainTitle();

private:
	Company * company;
};

#endif //_COMPANYMS_H
