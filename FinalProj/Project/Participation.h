class Participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int chiefJudgeGrade;
	/**
	* @brief Participation Contructor with their audition id, plce and the resposible judge grade
	* @param auditionId an unsigned integer
	* @param place an unsigned integer
	* @param chiefJudgeGrade an unsigned integer
	*/
public:
	Participation(unsigned int auditionId, unsigned int place, unsigned int chiefJudgeGrade);
	unsigned int getAuditionId() const;
	unsigned int getPlace() const;
	unsigned int getChiedJudgeGrade() const;

	void setAuditionId(unsigned int auditionId);
	void setPlace(unsigned int place);
	void setChiefJudgeGrade(unsigned int chiefJudgeGrade);
};
