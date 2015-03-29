#include "Street.h"
using namespace std;

Street::Street() {
}

Street::Street(const Street& another) {
	// ������ ��� � ���� ������ ��, ��� � � another
	name = another.name;
	homes = another.homes;
}

Street::Street(const string& name) {
	// ��������� �������� ����� ��������� � ����� ���� name
	// � ������� ������ ��������� ����� this->
	this->name = name;
}

Street& Street::operator = (const Street& another) {
	if(this != &another) {
		name = another.name;
		homes = another.homes;
	}
	return *this;
}

Street::~Street() {
}

Home& Street::HomeAt(unsigned index) {
	// ��������� ������������ ������� � ������� ����������, ���� ������ ��� ���������
	if(index >= homes.size()) {
		throw exception("index out of range");
	}
	// �������� �������� �� ������ ������� ������
	// ��� �������� �����������, ������� ���� ������ ������, �� ������� �� ���������
	list<Home>::iterator iterator = homes.begin();
	// �������� �������� �� index �������
	advance(iterator, index);
	// ���������� ������, �� ������� ��������� ��������
	return *iterator;
}

const Home& Street::HomeAt(unsigned index) const {
	// ��������� ������������ ������� � ������� ����������, ���� ������ ��� ���������
	if(index >= homes.size()) {
		throw exception("index out of range");
	}
	// �������� �������� �� ������ ������� ������
	// ��� �������� �����������, ������� �� ���� ������ ������, �� ������� �� ���������
	list<Home>::const_iterator iterator = homes.begin();
	// �������� �������� �� index �������
	advance(iterator, index);
	// ���������� ������, �� ������� ��������� ��������
	return *iterator;
}

void Street::SetName(const string& name) {
	this->name = name;
}

const string& Street::GetName() const {
	return name;
}

void Street::Add(const Home& home) {
	// ��������� ����� ��� � ����� ������
	homes.push_back(home);
}	

void Street::Remove(unsigned int index) {
	// ��������� ������������ ������� � ������� ����������, ���� ������ ��� ���������
	if(index >= homes.size()) {
		throw exception("index out of range");
	}
	// �������� �������� �� ������ ������� ������
	// ��� �� ����� ������ ������ � ������, ������� const_iterator
	list<Home>::const_iterator iterator = homes.begin();
	// �������� �������� �� index �������
	advance(iterator, index);
	// ������� ������, �� �������� ��������� ��������
	homes.erase(iterator);
}

void Street::Remove(const Home& home) {
	// ��������� ����� ��� ����, ��������� ������ � home
	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.cend(); iterator++) {
		// ����� ����� �� ��� - ������� � ������������ �� ������
		if(*iterator == home) {
			homes.erase(iterator);
			return;
		}
	}
	throw exception("no such home");
}

unsigned int Street::GetHomeCount() const {
	return homes.size();
}

unsigned int Street::GetPersonsCount() const {
	unsigned int Result = 0;
	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.end(); iterator++) {
		Result += (*iterator).GetPersonCount();
	}
	return Result;
}

unsigned int Street::GetPersonsCountWhoCanVote() const {
	// ��� ����� ���� ��������������� ������� FilterPersonsWhoCanVote(),
	// � ������� ��� ���������� �������, �� �������� ����� - 
	// ��������� ��������, ������� ������� ������ ������ ���
	unsigned int Result = 0;

	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.end(); iterator++) {
		// � ������� ���� ���� �����, ������������ ���������� �������, 
		// ������� ����� ����������, ������������� �� ��� ��������
		Result += (*iterator).GetPersonCountWhoCanVote();
	}

	return Result;
}

Street Street::FilterPersonsWhoCanVote() const {
	// ������������� ������������� �� ����� ��� �������� ����� �����
	Street Result(name);

	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.end(); iterator++) {
		// ��������� � ����� Result ���� � ��������������� ������� �������
		Result.Add((*iterator).FilterPersonsWhoCanVote());
	}

	return Result;
}

void Street::Print(ostream& stream) const {
	if(homes.empty()) {
		stream << name << " street, home list empty\n";
	} else {
		for(list<Home>::const_iterator iterator = homes.begin();
			iterator != homes.end(); iterator++) {
			stream << name << " street, ";
			(*iterator).Print(stream);
		}
	}
}
