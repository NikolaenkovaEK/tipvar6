#include "Street.h"

Street::Street() {
}

Street::Street(const Street & AnotherStreet) {
	Name = AnotherStreet.Name;
	HomeVector = AnotherStreet.HomeVector;
}

Street & Street::operator = (const Street & AnotherStreet) {
	if(this != &AnotherStreet) {
		Name = AnotherStreet.Name;
		HomeVector = AnotherStreet.HomeVector;
	}
	return *this;
}

Street::~Street() {
}

Home & Street::HomeAt(unsigned Index) {
	return HomeVector.at(Index);
}

const Home & Street::HomeAt(unsigned Index) const {
	return HomeVector.at(Index);
}

void Street::SetName(const std::string & NameValue) {
	Name = NameValue;
}

const std::string & Street::GetName() const {
	return Name;
}

void Street::Add(const Home & HomeValue) {
	HomeVector.push_back(HomeValue);
}	

void Street::Delete(unsigned int Index) {
	if(Index < HomeVector.size()) {
		HomeVector.erase(HomeVector.begin() + Index);
	}
}

unsigned int Street::GetHomeCount() const {
	return HomeVector.size();
}

unsigned int Street::GetPersonsCount() const {
	unsigned int Result = 0;
	for(unsigned int i = 0; i < HomeVector.size(); i++) {
		Result += HomeVector[i].GetPersonCount();
	}
	return Result;
}

unsigned int Street::GetPersonsCountWhoCanVote() const {
	unsigned int Result = 0;
	for(unsigned int i = 0; i < HomeVector.size(); i++) {
		Result += HomeVector[i].GetPersonCountWhoCanVote();
	}
	return Result;
}

Street Street::FilterPersonsWhoCanVote() const {
	Street Result;
	Result.Name = Name;

	for(unsigned int i = 0; i < HomeVector.size(); i++) {
		Result.Add(HomeVector[i].FilterPersonsWhoCanVote());
	}

	return Result;
}

void Street::Print(std::ostream & Stream) {
	if(HomeVector.empty()) {
		Stream << Name << " street, home list empty\n";
	} else for(unsigned int i = 0; i < HomeVector.size(); i++) {
		Stream << Name << " street, ";
		HomeAt(i).Print(Stream);
		Stream << '\n';
	}
}
