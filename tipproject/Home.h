#pragma pack(push,1)

#include <string>
#include <list>
#include <ostream>
using namespace std;

#include "Person.h"

// Home - контейнер для Person
class Home {
public:
	// Конструктор по умолчанию
	Home();

	// Конструктор из номера дома
	Home(int no);

	// Конструктор копии
	Home(const Home& another);

	// Конструктор из номера и имени дома
	Home(int no, const string& name);

	// Оператор присваивания
	Home& operator = (const Home& another);

	// Деструктор
	~Home();

	// Установить номер дома
	void SetHomeNo(int no);

	// Получить номер дома
	int GetHomeNo() const;

	// Добавить жильца
	void AddPerson(const Person& person);

	// Убрать жильца person
	// Если такого нет - будет брошено исключение
	void RemovePerson(const Person& person);

	// Убрать жильца по его индексу
	void RemovePerson(unsigned int index);

	// Получить жильца по его индексу
	const Person& GetPerson(unsigned int index) const;

	// Поменять жильца на person по его индексу
	void SetPerson(unsigned int index, const Person& person);

	// Вернуть количество жильцов дома
	unsigned int GetPersonCount() const;

	// Вернуть количество жильцов дома, которые могут голосовать
	unsigned int GetPersonCountWhoCanVote() const;

	// Задать имя дому
	void SetHomeName(const string& name);

	// Получить имя дома
	const string& GetHomeName() const;

	// Напечатать дом в stream
	void Print(ostream& stream) const;

	// Вернуть новый объект дома с теми жильцами, которые могут голосовать
	Home FilterPersonsWhoCanVote() const;

	// Добавить к дому жильца person
	Home& operator += (const Person& person);

	// Вернуть дом с добавленным жильцом person
	Home operator + (const Person& person) const;

	// Сравнение домов, сделаны как методы класса для демонстрации
	bool operator == (const Home& home) const;
	bool operator != (const Home& home) const;

private:
	// Номер дома
	int no;

	// Имя дома
	string name;

	// Список жильцов дома
	list<Person> persons;
};
#pragma pack(pop)
