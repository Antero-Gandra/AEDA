/**
* Project Untitled
*/


#ifndef _CALENDAR_H
#define _CALENDAR_H

#include <vector>
#include <ostream>
#include <string>

class Calendar {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
public:
	/**
	* @brief Calendar Default Contructor
	*/
	Calendar();

	/**
	* @brief Calendar Contructor with the date and time
	* @param year an unsigned integer
	* @param month an unsigned integer
	* @param day an unsigned integer
	* @param hour an unsigned integer
	* @param minute an unsigned integer
	*/
	Calendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute);

	/**
	* @brief Manages to get the year's value
	* @return constant unsigned integer
	*/
	unsigned int getYear() const;

	/**
	* @brief Manages to get the month's value
	* @return constant unsigned integer
	*/
	unsigned int getMonth() const;

	/**
	* @brief Manages to get the day's value
	* @return constant unsigned integer
	*/
	unsigned int getDay() const;

	/**
	* @brief Manages to get the hour's value
	* @return constant unsigned integer
	*/
	unsigned int getHour() const;

	/**
	* @brief Manages to get the minute's value
	* @return constant unsigned integer
	*/
	unsigned int getMinute() const;

	/**
	* @brief Changes the year's value
	* @param year an unsigned integer
	*/
	void setYear(unsigned int year);

	/**
	* @brief Changes the month's value
	* @param month an unsigned integer
	*/
	void setMonth(unsigned int month);

	/**
	* @brief Changes the day's value
	* @param day an unsigned integer
	*/
	void setDay(unsigned int day);

	/**
	* @brief Changes the hour's value
	* @param hour an unsigned integer
	*/
	void setHour(unsigned int hour);

	/**
	* @brief Changes the minute's value
	* @param minute an unsigned integer
	*/
	void setMinute(unsigned int minute);

	/**
	* @brief Operator overloads "+" adding the values of two calendar dates
	* @param calendar1 a Calendar Object Reference
	* @return Calendar Object Reference
	*/
	Calendar & operator+(const Calendar & calendar1);

	/**
	* @brief Operator overloads "==" to check the value of two calendar dates
	* @param calendar1 a Calendar Object Reference
	* @return true if Calendar Object is equal to calendar1, false otherwise
	*/
	bool operator==(const Calendar & calendar1) const;

	/**
	* @brief Operator overloads "<" yo check if the Object is smaller than calendar1
	* @param calendar1 a Calendar Object Reference
	* @return true if Calendar Object is smaller than calendar1, false otherwise
	*/
	bool operator<(const Calendar & calendar1) const;

	/**
	* @brief Converts the object's time in minutes
	* @return unsigned integer of the time in minutes
	*/
	operator unsigned int() const;

	/**
	* @brief Operator "<<" is overloaded to output the information about the Calendar information
	* @param os an Outstream Object
	* @param calendar a constant Calendar reference
	* @return ostream reference
	*/
	friend std::ostream& operator<<(std::ostream& os, const Calendar& calendar);

	/**
	* @brief Checks the veracity of a date
	* @return true if a date if valid, false otherwise
	*/
	bool isValidDate();

	/**
	* @brief Manages to get the date (year/month/day)
	* @return constant string
	*/
	std::string date() const;

	/**
	* @brief Manages to get the time (hour:minute)
	* @return constant string
	*/
	std::string time() const;

	/**
	* @brief Manages to get the full date (year/month/day/hour/minute)
	* @return constant string
	*/
	std::string full() const;
};

#endif
