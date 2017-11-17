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
	//Constructor
	Calendar();
	Calendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute);
	//Get Methods
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	unsigned int getHour() const;
	unsigned int getMinute() const;
	//Set Methods
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setHour(unsigned int hour);
	void setMinute(unsigned int minute);
	//Operator Overloading
	Calendar & operator+(const Calendar & calendar1);
	bool operator==(const Calendar & calendar1) const;
	bool operator<(const Calendar & calendar1) const;
	operator unsigned int() const;
	friend std::ostream& operator<<(std::ostream& os, const Calendar& calendar);
	//Other Methods
	bool isValidDate();
	std::string date() const;
	std::string time() const;
	std::string full() const;
};

#endif
