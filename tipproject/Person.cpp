#include "Person.h"
using namespace std;

Person::Person() {
	// ��� ���� ���������������� ������
	age = 0;
}

Person::Person(const string& name, unsigned int age) {
	// �.�. � ��� name � age ������� ��� ���� � ������, ��, �����
	// �������� �� �� ����������, ����� �� ��� ��������� ����� this
	this->name = name;
	this->age = age;
}

Person::Person(const Person& another) {
	// ������ ��� � ������� ������ ��, ��� � � another
	name = another.name;
	age = another.age;
}

Person& Person::operator = (const Person& another) {
	// ���� ��������� �� this ����� ��, ��� � �� another, �� �� 
	// �������� ��������� ���� ���� ��
	if(this != &another) {
		name = another.name;
		age = another.age;
	}
	// ���������� ������ �� ����
	return *this;
}

Person::~Person() {
}

const string& Person::GetName() const {
	return name;
}

void Person::SetName(const string& name) {
	this->name = name;
}

unsigned int Person::GetAge() const {
	return age;
}

void Person::SetAge(unsigned int age) {
	this->age = age;
}

void Person::Print(ostream& stream) const {
	// �������� "NoName", ���� ��� �� ������, �.�. ������ ������
	if(name.empty()) {
		stream << "NoName";
	} else {
		stream << name;
	}
	stream << ", age: " << age;
}

bool Person::CanVote() const {
	return age >= 18;
}

bool operator == (const Person& p1, const Person& p2) {
	return p1.age == p2.age && 
		// ���� string.compare(string) ���������� 0, �� ������ ����������
		0 == p1.name.compare(p2.name);
}

bool operator != (const Person& p1, const Person& p2) {
	// ����������� �������� ��������� == ��� ��������� ����������
	return !(p1 == p2);
}
