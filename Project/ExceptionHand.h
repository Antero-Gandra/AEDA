
class ContestantInfoNotFound {
};

class ContestantIdNotFound {
	unsigned int id;
public:
	ContestantIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};
class JudgeInfoNotFound {
};

class JudgeIdNotFound {
	unsigned int id;
public:
	JudgeIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }

};

class InvalidOption {

};

class EmptyOption {

};

class OptionOutOfRange {

};