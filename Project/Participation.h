struct Participation {
	unsigned int auditionId;
	unsigned int place;
	unsigned int chiefJudgeGrade;
	/**
	* @brief Participation Contructor with their audition id, plce and the resposible judge grade
	* @param auditionId an unsigned integer
	* @param place an unsigned integer
	* @param chiefJudgeGrade an unsigned integer
	*/
	Participation(unsigned int auditionId, unsigned int place, unsigned int chiefJudgeGrade);
};
