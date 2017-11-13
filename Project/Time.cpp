#include <sstream>
#include "Time.h"

/**
 * Time implementation
 */

vector<unsigned int> daysOfMonth= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Constructor
Time::Time() { year = 0; month = 0; day = 0; hour = 0; minute = 0; }
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
Time & Time::operator+(const Time & time1)
{
	unsigned int minutes, hours, days, months, years;
	//Setting the minutes
	minutes = minute + time1.minute;
	minute = minutes % 60;
	//Setting the hours
	hours = (minute + time1.minute) / 60 + (hour + time1.hour);
	hour = hours % 24;
	//Setting the days, months and years
	days = day + time1.day + hours / 24;
	months = month + time1.month;
	years = year + time1.year;
	if (years % 4 == 0 && (years % 400 == 0 || years % 100 != 0))
		daysOfMonth[1] = 29;
	else daysOfMonth[1] = 28;
	while (days > daysOfMonth[(months%12)-1])
	{
		days -= daysOfMonth[(months%12)-1];
		if (months++ > 12) {
			months -= 12; years++;
		}
		if (years % 4 == 0 && (years % 400 == 0 || years % 100 != 0))
			daysOfMonth[1] = 29;
		else daysOfMonth[1] = 28;
	}
	day = days;
	month = months;
	year = years;
	return *this;
}
bool Time::operator==(const Time & time1) const
{
	return (minute == time1.minute && hour == time1.hour && day == time1.day && month == time1.month && year == time1.year);
}
bool Time::operator<(const Time & time1) const
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
ostream& operator<<(ostream& os, const Time& time) {
	os << time.date() << "   " << time.time();
	return os;
}
//Other Methods
bool Time::isValidDate() {
	if (month >= 1 && month <= 12) //so that we can search the maximum days of that month without range problems
		return (minute <= 59 && hour <= 23 && day >= 1 && day <= daysOfMonth[month - 1]);
	else return false;
}
string Time::date() const {
	ostringstream date;
	date << year << '/' << month << '/' << day;
	return date.str();
}
string Time::time() const {
	ostringstream time;
	time << hour << ':' << minute;
	return time.str();
}
