/**
 * Project Untitled
 */


#ifndef _TIME_H
#define _TIME_H

#include <vector>
using namespace std;

class Time {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
public:
	//Constructor
	Time();
	Time(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute);
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
	Time & operator+(const Time & time1);
	bool operator==(const Time & time1) const;
	bool operator<(const Time & time1) const;
	friend ostream& operator<<(ostream& os, const Time& time);
	//Other Methods
	bool isValidDate();
	string Time::date() const;
	string Time::time() const;
};

#endif //_TIME_H
