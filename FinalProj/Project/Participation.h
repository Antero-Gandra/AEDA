class Participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int chiefJudgeGrade;
public:
	/**
	* @brief Participation Contructor with their audition id, place and the resposible judge's grade
	* @param auditionId an unsigned integer
	* @param place an unsigned integer
	* @param chiefJudgeGrade an unsigned integer
	*/
	Participation(unsigned int auditionId, unsigned int place, unsigned int chiefJudgeGrade);
	
	/**
	* @brief Manages to access the Audition's ID the contestant was in
	* @return unsigned integer of the Audition's ID
	*/
	unsigned int getAuditionId() const;
	
	/**
	* @brief Manages to access the ranking the contestant got
	* @return unsigned integer of the ranking of the contestant
	*/unsigned int getPlace() const;
	
	/**
	* @brief Manages to access the value that the responsible judge grade the contestant
	* @return unsigned integer of the grade
	*/
	unsigned int getChiedJudgeGrade() const;

	/**
	* @brief Changes the audition's id
	* @param auditionId unsigned integer
	*/
	void setAuditionId(unsigned int auditionId);
	
	/**
	* @brief Changes the contestant's ranking
	* @param place unsigned integer
	*/
	void setPlace(unsigned int place);
	
	/**
	* @brief Changes the reposible judge's grade
	* @param chiefJudgeGrade unsigned integer
	*/
	void setChiefJudgeGrade(unsigned int chiefJudgeGrade);
};
