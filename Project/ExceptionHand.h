
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

class AuditionIdNotFound{
	unsigned int id;
public:
	AuditionIdNotFound(unsigned int id) { this->id = id; }
	unsigned int getId() const { return id; }
};

class EmptyAnswer {

};

class InvalidOption {

};

class OptionOutOfRange {

};

class NotYesOrNo {

};

class InvalidId {

};

class NotANumber {

};