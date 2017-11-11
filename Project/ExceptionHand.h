
class RepeatedContestant {
	unsigned int id;
public:
	RepeatedContestant(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};

class NoJudgeFound {
	unsigned int id;
};

class RepeatedJudge {
	unsigned int id;
public:
	RepeatedJudge(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};
