#include "Home.h"

Home::Home() {
	HomeNo = 0;
}

Home::Home(int HomeNoValue) {
	HomeNo = HomeNoValue;
}

Home::Home(const Home & AnotherHome) {
	HomeNo = AnotherHome.HomeNo;
	HomeName = AnotherHome.HomeName;
	Persons = AnotherHome.Persons;
}

Home & Home::operator = (const Home & AnotherHome) {
	if(this != &AnotherHome) {
		HomeNo = AnotherHome.HomeNo;
		HomeName = AnotherHome.HomeName;
		Persons = AnotherHome.Persons;
	}
	return *this;
}

Home::~Home() {
}

void Home::SetHomeNo(int HomeNoValue) {
	// Обработка ошибок
	HomeNo = HomeNoValue;
}

int Home::GetHomeNo() const {
	return HomeNo;
}

void Home::AddPerson(const Person & PersonValue) {
	Persons.push_back(PersonValue);
}

void Home::RemovePerson(unsigned int Index) {
	if(Index < Persons.size()) {
		Persons.erase(Persons.begin() + Index);
	}
}

const Person & Home::GetPerson(unsigned int Index) const {
	return Persons[Index];
}

unsigned int Home::GetPersonCount() const {
	return Persons.size();
}

unsigned int Home::GetPersonCountWhoCanVote() const {
	unsigned Result = 0;
	for(unsigned int i = 0; i < Persons.size(); i++) {
		if(GetPerson(i).CanVote()) {
			Result++;
		}
	}
	return Result;
}

void Home::SetHomeName(const std::string & HomeNameValue) {
	HomeName = HomeNameValue;
}

const std::string & Home::GetHomeName() const {
	return HomeName;
}

void Home::Print(std::ostream & Stream) {
	Stream << "Home no " << HomeNo;
	if(!HomeName.empty()) {
		Stream << ", " << HomeName;
	}
	if(Persons.empty()) {
		Stream << ", empty\n";
	} else {
		Stream << ", persons, who are living here:\n";
		for(unsigned int i = 0; i < Persons.size(); i++) {
			GetPerson(i).Print(Stream);
			Stream << '\n';
		}
	}
}

Home Home::FilterPersonsWhoCanVote() const {
	Home Result;
	Result.HomeNo = HomeNo;
	Result.HomeName = HomeName;
	for(unsigned int i = 0; i < GetPersonCount(); i++) {
		if(Persons[i].CanVote()) {
			Result.AddPerson(Persons[i]);
		}
	}
	return Result;
}


Home & Home::operator += (const Person & SomePerson) {
	AddPerson(SomePerson);
	return *this;
}

Home Home::operator + (const Person & SomePerson) const {
	Home result = *this;
	result.AddPerson(SomePerson);
	return result;
}
