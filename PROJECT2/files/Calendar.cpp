#include <sstream>
#include <vector>
#include <limits>

#include "Calendar.h"

using namespace std;

const streamsize max = numeric_limits<streamsize>::max();
vector<unsigned int> daysOfMonth= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//Constructor
Calendar::Calendar() { year = 0; month = 0; day = 0; hour = 0; minute = 0; }
Calendar::Calendar(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute) {
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
}

//Get Methods
unsigned int Calendar::getYear() const { return year; }
unsigned int Calendar::getMonth() const { return month; }
unsigned int Calendar::getDay() const { return day; }
unsigned int Calendar::getHour() const { return hour; }
unsigned int Calendar::getMinute() const { return minute; }
//Set Methods
void Calendar::setYear(unsigned int year) { this->year = year; }
void Calendar::setMonth(unsigned int month) { this->month = month; }
void Calendar::setDay(unsigned int day) { this->day = day; }
void Calendar::setHour(unsigned int hour) { this->hour = hour; }
void Calendar::setMinute(unsigned int minute) { this->minute = minute; }

//Operator Overloading
Calendar & Calendar::operator+(const Calendar & calendar1)
{
	unsigned int minutes, hours, days, months, years;
	//Setting the minutes
	minutes = minute + calendar1.minute;
	minute = minutes % 60;
	//Setting the hours
	hours = (minute + calendar1.minute) / 60 + (hour + calendar1.hour);
	hour = hours % 24;
	if (month == 0) {
		this->minute = minutes;
		this->hour = hours;
		return *this;
	}
	//Setting the days, months and years
	days = day + calendar1.day + hours / 24;
	months = month + calendar1.month;
	years = year + calendar1.year;
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
bool Calendar::operator==(const Calendar & calendar1) const
{
	return (minute == calendar1.minute
		&& hour == calendar1.hour
		&& day == calendar1.day
		&& month == calendar1.month
		&& year == calendar1.year);
}
bool Calendar::operator<(const Calendar & calendar1) const
{
	if (year > calendar1.year) return false;
	else if (year < calendar1.year) return true;
	//equal year
	else if (month > calendar1.month) return false;
	else if (month < calendar1.month) return true;
	//equal year and month
	else if (day > calendar1.day) return false;
	else if (day < calendar1.day) return true;
	//equal year, month and day
	else if (hour > calendar1.hour) return false;
	else if (hour < calendar1.hour) return true;
	//equal year, month, day and hour
	else if (minute >= calendar1.hour) return false;
	else return true;
}
Calendar::operator unsigned int() const {
	unsigned int hoursInMinutes = hour * 60;
	return hoursInMinutes + minute;
}
ostream& operator<<(ostream& os, const Calendar& calendar) {
	os << calendar.date() << " " << calendar.time();
	return os;
}

//Other Methods
bool Calendar::isValidDate() {
	if (month >= 1 && month <= 12) //so that we can search the maximum days of that month without range problems
		return (minute <= 59 && hour <= 23 && day >= 1 && day <= daysOfMonth[month - 1]);
	else return false;
}
string Calendar::date() const {
	ostringstream date;
	date << year << '/' << month << '/' << day;
	return date.str();
}
string Calendar::time() const {
	ostringstream calendar;
	if (hour < 10)
		calendar << "0";
	calendar << hour << ':';
	if (minute < 10)
		calendar << "0";
	calendar << minute;
	return calendar.str();
}
string Calendar::full() const {
	ostringstream calendar;
	calendar << date() << '/' <<  hour << '/' << minute;
	return calendar.str();
}
