class Participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int chiefJudgeGrade;
public:
	/**
	* @param auditionId an unsigned integer
	* @param place an unsigned integer
	* @param chiefJudgeGrade an unsigned integer
	*/
	Participation(unsigned int auditionId, unsigned int place, unsigned int chiefJudgeGrade);
	unsigned int getAuditionId() const;
	unsigned int getChiedJudgeGrade() const;

	void setAuditionId(unsigned int auditionId);
	void setPlace(unsigned int place);
	void setChiefJudgeGrade(unsigned int chiefJudgeGrade);
};
