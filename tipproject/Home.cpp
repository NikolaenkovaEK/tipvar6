#include "Home.h"
using namespace std;

Home::Home() {
	// ��� � ������� ������� ���������������� �������
	no = 0;
}

Home::Home(int no) {
	// ��� � � ������ � Person, ���� no ����������� � ����������,
	// ������� ��������� ���� �������� � ������� ������ ��������� � this
	this->no = no;
}

Home::Home(const Home& another) {
	// �������� ��� ����
	no = another.no;
	name = another.name;
	persons = another.persons;
}

Home::Home(int no, const string& name) {
	// ���������� no � name ����������� � ������������ ������, 
	// ������� ���������� this
	this->no = no;
	this->name = name;
}

Home& Home::operator = (const Home& another) {
	// �������� ������� ��������� ���� ����
	if(this != &another) {
		no = another.no;
		name = another.name;
		persons = another.persons;
	}
	// ���������� ������ �� ����
	return *this;
}

Home::~Home() {
}

void Home::SetHomeNo(int no) {
	// ����� ���� �� ����� ���� ������ ��� ������ ����, �������
	// ��������� � ������� ����������
	if(no < 1) {
		throw exception("invalid home no");
	}
	// ����� �������� ���� ����������� ����� this->
	this->no = no;
}

int Home::GetHomeNo() const {
	return no;
}

void Home::AddPerson(const Person& person) {
	// ��������� ������ ������ � ����� ������
	persons.push_back(person);
}

void Home::RemovePerson(const Person& person) {
	// ������, ��� ������� ������, ����� ��� ������� �����.
	// ��� ����� ���������� ������� �������� �����.
	// ��������� � ��� �� ������� ������������ ������, � �� ������, 
	// �� �� �� ����� ������ �������� �� �������� �� 0 �� persons.size(),
	// ������� ���������� ���������.
	// persons.begin() ���������� �������� �� ������ ������,
	// persons.end() - �� ��������� �� ��������� ������� ������, � �����
	// *iterator �� �������� ������ � �������� ������.
	for(list<Person>::const_iterator iterator = persons.begin();
		iterator != persons.end(); iterator++) {
		// ��� ����������� ������� ������������ ��������������� ����������
		// ���� �������� ��������� 
		if(*iterator == person) {
			// ����� �� ����� ������� ������, �� ������� ��� � ������������
			// �� ������
			persons.erase(iterator);
			return;
		}
	}
	// ���� �� ����� ����, �� ������ ������ �� ����������
	throw exception("no such person");
}

void Home::RemovePerson(unsigned int index) {
	// ��������� ������������ �������, ������� ���������� � ������ ��� 
	// ��������������
	if(index >= persons.size()) {
		throw exception("index out of range");
	}
	// �������� �������� �� ������ ������
	list<Person>::const_iterator iterator = persons.begin();
	// ����������� �������� �� index �������
	advance(iterator, index);
	// ������� �������, �� ������� ��������� ��������
	persons.erase(iterator);
}

const Person& Home::GetPerson(unsigned int index) const {
	// ��������� ������������ �������, ������� ���������� � ������ ��� 
	// ��������������
	if(index >= persons.size()) {
		throw exception("index out of range");
	}
	// �������� �������� �� ������ ������
	list<Person>::const_iterator iterator = persons.begin();
	// ����������� �������� �� index �������
	advance(iterator, index);
	// ���������� ������ ������, �� �������� ��������� ��������
	return *iterator;
}

void Home::SetPerson(unsigned int index, const Person& person) {
	// ��������� ������������ �������, ������� ���������� � ������ ��� 
	// ��������������
	if(index >= persons.size()) {
		throw exception("index out of range");
	}
	// �������� �������� �� ������ ������
	list<Person>::iterator iterator = persons.begin();
	// ����������� �������� �� index �������
	advance(iterator, index);
	// ������ ���������� ������ ������ person
	*iterator = person;
}

unsigned int Home::GetPersonCount() const {
	return persons.size();
}

unsigned int Home::GetPersonCountWhoCanVote() const {
	unsigned int Result = 0;
	// ����������� �� ����� ������ ������� � ����������� ������� ��
	// 1, ���� ����� ����� ����������
	for(list<Person>::const_iterator iterator = persons.begin();
		iterator != persons.end(); iterator++) {
		if((*iterator).CanVote()) {
			Result++;
		}
	}
	return Result;
}

void Home::SetHomeName(const string& name) {
	this->name = name;
}

const string& Home::GetHomeName() const {
	return name;
}

void Home::Print(ostream& stream) const {
	stream << "Home no " << no;
	if(!name.empty()) {
		stream << ", " << name;
	}
	if(persons.empty()) {
		stream << ", empty\n";
	} else {
		stream << ", persons, who are living here:\n";
		for(list<Person>::const_iterator iterator = persons.begin();
			iterator != persons.end(); iterator++) {
			(*iterator).Print(stream);
			stream << '\n';
		}
	}
}

Home Home::FilterPersonsWhoCanVote() const {
	// ������� ���, ������� ������ ����� � ���
	// ������ ����� ��������� ����� ����������
	Home Result(no, name);
	// ��������� � ������ ������� ���� Result ������ ���, ��� ����� ����������
	for(std::list<Person>::const_iterator iterator = persons.begin();
		iterator != persons.cend(); iterator++) {
		if((*iterator).CanVote()) {
			Result.AddPerson(*iterator);
		}
	}
	// ���������� ���������� ������
	return Result;
}


Home& Home::operator += (const Person& person) {
	AddPerson(person);
	return *this;
}

Home Home::operator + (const Person& person) const {
	Home result = *this;
	result.AddPerson(person);
	return result;
}

bool Home::operator == (const Home& home) const {
	// ��������� �������� ���������. ���� ��� �������, �� �� 
	// ���������� ��� � ����� ����� � ������ ������� true
	if(this == &home) {
		return true;
	}

	// ������� ���������� �� ������, �������, ������ �����, �����
	// ����������
	if(no != home.no || 0 != name.compare(home.name)) {
		return false;
	}
	// ��������� ���� ������� �������� ��������, �������
	// ������ ������� �� �������
	if(persons.size() != home.persons.size()) {
		return false;
	}

	// ����������� �� ������� ������� ����� ����� �� ������
	// �� �����, ��������� ������� ������.
	// ������������ ����� ����� ������� ���� �������� ����
	std::list<Person>::const_iterator
		iterator1 = persons.begin(),
		iterator2 = home.persons.begin();

	while(iterator1 != persons.end()) {
		// ���� ���� �� ���� �� ������� �� ������ � ���������������
		// � ������ ������, �� ���� �� ���������
		if(*iterator1 != *iterator2) {
			return false;
		}
		iterator1++;
		iterator2++;
	}
	// �� ��������, ���������� true
	return true;
}

bool Home::operator != (const Home& home) const {
	// ����� �� ������ �� ��, ��� �������� � ��������� ==, 
	// ������ ���������� ��� ��������������� �������� ��� 
	// ���������
	return !(*this == home);
}
