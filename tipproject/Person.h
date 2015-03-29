#pragma pack(push,1)

#include <string>
#include <ostream>
using namespace std;

class Person {
public:
	// Конструктор без аргументов
	Person();

	// Конструктор из имени и возраста
	Person(const string& name, unsigned int age);

	// Конструктор копии
	Person(const Person& another);

	// Оператор присваивания
	Person& operator = (const Person& another);

	// Деструктор
	~Person();

	// Получить имя 
	const string& GetName() const;

	// Установить имя
	void SetName(const string& name);

	// Получить возраст
	unsigned int GetAge() const;

	// Установить возраст
	void SetAge(unsigned int age);

	// Напечатать в поток stream
	void Print(ostream& stream) const;

	// Возвращает true, если человек может голосовать
	bool CanVote() const;

	// Операции сравнения персон, в отличие от Home, сделаны 
	// дружественными операциями для демонстрации
	friend bool operator == (const Person& p1, const Person& p2);
	friend bool operator != (const Person& p1, const Person& p2);

private:
	// Имя
	string name;

	// Возраст
	unsigned int age;
};
#pragma pack(pop)
