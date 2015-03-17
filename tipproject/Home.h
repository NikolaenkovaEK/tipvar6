#ifndef HOME_H
#define HOME_H

#include <string>
#include <vector>
#include <ostream>

#include "Person.h"

class Home {
public:
	// Home - контейнер для Person
	Home();
	Home(int HomeNoValue);
	Home(const Home & AnotherHome);
	Home & operator = (const Home & AnotherHome);
	~Home();

	void SetHomeNo(int HomeNoValue);
	int GetHomeNo() const;

	void AddPerson(const Person & PersonValue);
	void RemovePerson(unsigned int Index);
	const Person & GetPerson(unsigned int Index) const;

	unsigned int GetPersonCount() const;
	unsigned int GetPersonCountWhoCanVote() const;

	void SetHomeName(const std::string & HomeNameValue);
	const std::string & GetHomeName() const;

	void Print(std::ostream & Stream);

	Home FilterPersonsWhoCanVote() const;

	Home & operator += (const Person & SomePerson);
	Home operator + (const Person & SomePerson) const;

private:
	int HomeNo;
	std::string HomeName;

	std::vector<Person> Persons;
};

#endif // HOME_H