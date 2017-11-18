#include "Application.h"

Application::Application(Calendar date, unsigned int contestantId) {
		this->date = date;
		this->contestantId = contestantId;
	}

bool Application::operator <(const Application & application) {
	return date < application.date;
}
