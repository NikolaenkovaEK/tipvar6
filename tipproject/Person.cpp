#include "Person.h"


Person::Person() {
	Age = 0;
}

Person::Person(const std::string & NameValue, unsigned int AgeValue) {
	Name = NameValue;
	Age = AgeValue;
}

Person::Person(const Person & AnotherPerson) {
	Name = AnotherPerson.Name;
	Age = AnotherPerson.Age;
}

Person & Person::operator = (const Person & AnotherPerson) {
	if(this != &AnotherPerson) {
		Name = AnotherPerson.Name;
		Age = AnotherPerson.Age;
	}
	return *this;
}

Person::~Person() {
}

const std::string & Person::GetName() const {
	return Name;
}

void Person::SetName(const std::string & NameValue) {
	Name = NameValue;
}

unsigned int Person::GetAge() const {
	return Age;
}

void Person::SetAge(unsigned int AgeValue) {
	Age = AgeValue;
}

void Person::Print(std::ostream & Stream) const {
	if(Name.empty()) {
		Stream << "NoName";
	} else {
		Stream << Name;
	}
	Stream << ", Age: " << Age;
}

bool Person::CanVote() const {
	return Age >= 18;
}
