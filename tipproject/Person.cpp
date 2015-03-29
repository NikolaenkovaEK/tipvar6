#include "Person.h"
using namespace std;

Person::Person() {
	// Имя само инициализируется пустым
	age = 0;
}

Person::Person(const string& name, unsigned int age) {
	// Т.к. у нас name и age имеются как поля в классе, то, чтобы
	// отличить их от аргументов, нужно на них сослаться через this
	this->name = name;
	this->age = age;
}

Person::Person(const Person& another) {
	// Задаем имя и возраст такими же, как и у another
	name = another.name;
	age = another.age;
}

Person& Person::operator = (const Person& another) {
	// Если указатель на this такой же, как и на another, то мы 
	// пытаемся присвоить себя себе же
	if(this != &another) {
		name = another.name;
		age = another.age;
	}
	// Возвращаем ссылку на себя
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
	// Печатаем "NoName", если имя не задано, т.е. пустая строка
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
		// Если string.compare(string) возвращает 0, то строки одинаковые
		0 == p1.name.compare(p2.name);
}

bool operator != (const Person& p1, const Person& p2) {
	// Инвертируем значение оператора == для получения результата
	return !(p1 == p2);
}
