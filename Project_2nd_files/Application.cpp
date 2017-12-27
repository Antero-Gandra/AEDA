#include "Application.h"

Application::Application(Calendar date, unsigned int contestantId) {
		this->date = date;
		this->contestantId = contestantId;
	}

bool Application::operator <(const Application & application) {
	return date < application.date;
}

Calendar Application::getDate() const {
	return date;
}
unsigned int Application::getContestantId() const {
	return contestantId;
}

void Application::setDate(Calendar date) {
	this->date = date;
}

void Application::setContestantId(unsigned int contestantId) {
	this->contestantId = contestantId;
}
