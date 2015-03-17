#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>

class Person {
public:
	Person();
	Person(const std::string & NameValue, unsigned int AgeValue);
	Person(const Person & AnotherPerson);
	Person & operator = (const Person & AnotherPerson);
	~Person();

	const std::string & GetName() const;
	void SetName(const std::string & NameValue);

	unsigned int GetAge() const;
	void SetAge(unsigned int AgeValue);

	void Print(std::ostream & Stream) const;

	bool CanVote() const;

private:
	std::string Name;
	unsigned int Age;
};

#endif // PERSON_H