#include "UnavailableContestant.h"
#include "Contestant.h"
#include "Util.h"
#include <sstream>
#include <limits>

using namespace std;

UnavailableContestant::UnavailableContestant(unsigned int id, std::string name, std::string address, unsigned int mobile, Calendar dob, std::string specialty, std::vector<Participation*> participation, Calendar unavailabilityBegin, Calendar unavailabilityEnd, string reason) : Contestant(id, name, address, mobile, dob, specialty, participation) {
	this->unavailabilityBegin = unavailabilityBegin;
	this->unavailabilityEnd = unavailabilityEnd;
	this->reason = reason;
}
UnavailableContestant::UnavailableContestant(string textLine) : Contestant(textLine){
	const streamsize max = numeric_limits<streamsize>::max();
	istringstream contestantLine(textLine);

	unsigned int id;
	string name, address;
	unsigned int mobile;
	Calendar dob;
	unsigned int year, month, day, hour, minute;
	string prtcpations, prtcpation, aux_num, unavailability, calendarBegin, calendarEnd, reason;
	vector<Participation*> participations;
	unsigned int auditionId, place, chiefJudgeGrade;

	//get id
	getline(contestantLine, aux_num, ';');
	removeSpaces(aux_num);
	istringstream id_num(aux_num);
	id_num >> id;

	//get name
	getline(contestantLine, name, ';');
	removeSpaces(name);

	//get dob

	//year
	getline(contestantLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream year_num(aux_num);
	year_num >> year;

	//month
	getline(contestantLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream month_num(aux_num);
	month_num >> month;

	//day
	getline(contestantLine, aux_num, ';');
	removeSpaces(aux_num);
	istringstream day_num(aux_num);
	day_num >> day;


	dob.setYear(year);
	dob.setMonth(month);
	dob.setDay(day);

	//get mobile
	getline(contestantLine, aux_num, ';');
	removeSpaces(aux_num);
	istringstream mobile_num(aux_num);
	mobile_num >> mobile;

	//get address
	getline(contestantLine, address, ';');
	removeSpaces(address);

	//get specialty
	getline(contestantLine, specialty, ';');
	removeSpaces(specialty);

	//get participations
	getline(contestantLine, prtcpations, ';');
	removeSpaces(prtcpations);

	istringstream participationsLine;
	participationsLine.str(prtcpations);

	//Reading each participation
	getline(participationsLine, prtcpation, '.');
	removeSpaces(prtcpation);
	istringstream participationLine(prtcpation);
	while (prtcpation != "")
	{
		participationLine >> auditionId;
		participationLine.ignore(max, ',');
		participationLine >> place;
		participationLine.ignore(max, ',');
		participationLine >> chiefJudgeGrade;

		Participation * p = new Participation(auditionId, place, chiefJudgeGrade);
		participations.push_back(p);
		getline(participationsLine, prtcpation, '.');
		istringstream participationLine(prtcpation);
	}

	//Unavailability
	getline(contestantLine, unavailability, ';');
	removeSpaces(unavailability);
	istringstream unavailabilityLine(unavailability);

	//UNAVAILABILITY BEGIN

	//year
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream year_n(aux_num);
	year_n >> year;

	//month
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream month_n(aux_num);
	month_n >> month;

	//day
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream day_n(aux_num);
	day_n >> day;

	//hour
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream hour_n(aux_num);
	hour_n >> hour;

	//minute
	getline(unavailabilityLine, aux_num, ',');
	removeSpaces(aux_num);
	istringstream minute_n(aux_num);
	minute_n >> minute;

	this->unavailabilityBegin = Calendar(year, month, day, hour, minute);

	//UNAVAILABILITY END

	//year
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream year_n2(aux_num);
	year_n2 >> year;

	//month
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream month_n2(aux_num);
	month_n2 >> month;

	//day
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream day_n2(aux_num);
	day_n2 >> day;

	//hour
	getline(unavailabilityLine, aux_num, '/');
	removeSpaces(aux_num);
	istringstream hour_n2(aux_num);
	hour_n2 >> hour;

	//minute
	getline(unavailabilityLine, aux_num, ',');
	removeSpaces(aux_num);
	istringstream minute_n2(aux_num);
	minute_n2 >> minute;

	this->unavailabilityEnd = Calendar(year, month, day, hour, minute);

	getline(unavailabilityLine, reason, ';');
	this->reason = reason;


	//set attributes
	this->id = id;
	this->name = name;
	this->mobile = mobile;
	this->address = address;
	this->dob = dob;
	this->specialty = specialty;
	this->participations = participations;
}
UnavailableContestant::UnavailableContestant(Contestant * contestant, Calendar unavailabilityBegin, Calendar unavailabilityEnd, string reason) : Contestant(contestant->getId(), contestant->getName(), contestant->getAddress(), contestant->getMobile(), contestant->getDob(), contestant->getSpecialty(), contestant->getParticipations()) {
	this->unavailabilityBegin = unavailabilityBegin;
	this->unavailabilityEnd = unavailabilityEnd;
	this->reason = reason;
	delete contestant;
}
void UnavailableContestant::show() {
	Contestant::show();
	cout << "-> Unavailable Period: " << unavailabilityBegin.date() << " at " << unavailabilityBegin.time() << " --- " << unavailabilityEnd.date() << " at " << unavailabilityEnd.time() << endl;
	cout << "       Reason: " << reason;
}
ostream& operator<<(ostream& os, const UnavailableContestant & contestant) {

	os << contestant.getId() << " ; " << contestant.getName() << " ; " << contestant.getDob().date() << " ; " << contestant.getMobile() << " ; " << contestant.getAddress() << " ; " << contestant.getSpecialty() << " ; ";
	//print participations
	auto participations = contestant.getParticipations();

	for (size_t i = 0; i < participations.size(); i++)
	{
		os << participations[i]->getAuditionId() << " , ";
		os << participations[i]->getPlace() << " , ";
		os << participations[i]->getChiedJudgeGrade() << ". ";
	}
	os << " ;";

	os << contestant.unavailabilityBegin.full() << " ,";
	os << contestant.unavailabilityEnd.full() << " ,";
	os << contestant.reason << " ;";

	return os;
}
Calendar UnavailableContestant::getUnavailabilityEnd() const {
	return unavailabilityEnd;
}