#ifndef STREET_H
#define STREET_H

#include <ostream>
#include <vector>

#include "Home.h"

class Street {
public:
	// Street - контейнер для Home
	Street();
	Street(const Street & AnotherStreet);
	Street & operator = (const Street & AnotherStreet);
	~Street();

	Home & HomeAt(unsigned Index);
	const Home & HomeAt(unsigned Index) const;

	void SetName(const std::string & NameValue);
	const std::string & GetName() const;

	void Add(const Home & HomeValue);
	void Delete(unsigned int Index);

	unsigned int GetHomeCount() const;
	unsigned int GetPersonsCount() const;
	unsigned int GetPersonsCountWhoCanVote() const;

	Street FilterPersonsWhoCanVote() const;

	void Print(std::ostream & Stream);

private:
	std::string Name;
	std::vector<Home> HomeVector;
};

#endif // STREET_H