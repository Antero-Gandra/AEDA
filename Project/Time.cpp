#include "Time.h"
#include <vector>

/**
 * Time implementation
 */
std::vector<int> daysOfMonth= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
using namespace std;

//Constructor
Time::Time(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute) {
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
}
//Get Methods
unsigned int Time::getYear() const { return year; }
unsigned int Time::getMonth() const { return month; }
unsigned int Time::getDay() const { return day; }
unsigned int Time::getHour() const { return hour; }
unsigned int Time::getMinute() const { return minute; }
//Set Methods
void Time::setYear(unsigned int year) { this->year = year; }
void Time::setMonth(unsigned int month) { this->month = month; }
void Time::setDay(unsigned int day) { this->day = day; }
void Time::setHour(unsigned int hour) { this->hour = hour; }
void Time::setMinute(unsigned int minute) { this->minute = minute; }

//Operator Overloading
//operator + incomplete
Time & Time::operator+(Time & time1) {
	unsigned int aux;
	minute = (minute + time1.minute) % 60;
	aux = ((hour + time1.hour) / 24 + day + time1.day);
	hour = ((minute + time1.minute) / 60 + (hour + time1.hour)) % 24;
	while ( aux >= daysOfMonth[month - 1]) {
		aux -= daysOfMonth[month-1];
		month++;
	}
	day = aux;
	month = (month + time1.month) % 12;
	year = (month + time1.month) / 12 + (year + time1.year);
	return *this;
}
bool Time::operator==(Time & time1)
{
	return (minute == time1.minute && hour == time1.hour && day == time1.day && month == time1.month && year == time1.year);
}
bool Time::operator<(Time & time1)
{
	if (year > time1.year) return false;
	else if (year < time1.year) return true;
	//equal year
	else if (month > time1.month) return false;
	else if (month < time1.month) return true;
	//equal year and month
	else if (day > time1.day) return false;
	else if (day < time1.day) return true;
	//equal year, month and day
	else if (hour > time1.hour) return false;
	else if (hour < time1.hour) return false;
	//equal year, month, day and hour
	else if (minute >= time1.hour) return false;
	else return true;
}