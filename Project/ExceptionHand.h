
class RepeatedContestant {
	unsigned int id;
public:
	RepeatedContestant(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};

class ContestantIdNotFound {
	unsigned int id;
public:
	ContestantIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }

};

class RepeatedJudge {
	unsigned int id;
public:
	RepeatedJudge(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};

class JudgeIdNotFound {
	unsigned int id;
public:
	JudgeIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }

};