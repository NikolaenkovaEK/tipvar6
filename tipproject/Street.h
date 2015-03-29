#pragma pack(push,1)

#include <ostream>
#include <list>
using namespace std;

#include "Home.h"

// Street - контейнер для Home
class Street {
public:
	// Конструктор по умолчанию
	Street();

	// Конструктор улицы из другой улицы
	Street(const Street& another);

	// Конструктор улицы из её имени
	Street(const string& name);

	// Оператор присваивания
	Street& operator = (const Street& another);

	// Деструктор
	~Street();


	// Получить дом по его индексу
	// Неконстантная версия, которая позволяет изменять дом
	// по возвращенной ссылке
	Home& HomeAt(unsigned index);

	// Получить дом по его индексу
	// Константная версия, которая не позволяет изменять дом
	// по возвращенной ссылке, сделано для того, чтобы 
	// можно было читать данные дома у константной улицы
	const Home& HomeAt(unsigned index) const;

	// Задать улице название
	void SetName(const string& name);

	// Получить название улицы
	const string& GetName() const;

	// Добавить к улице дом
	void Add(const Home& home);

	// Удалить дом улицы по индексу
	void Remove(unsigned int index);

	// Удалить дом улицы
	void Remove(const Home& home);
	


	// Вернуть количество домов
	unsigned int GetHomeCount() const;

	// Вернуть общее количество жителей улицы
	unsigned int GetPersonsCount() const;

	// Вернуть количество жителей улицы, которые могут голосовать
	unsigned int GetPersonsCountWhoCanVote() const;

	// Вернуть новый объект улицы только с теми людьми, кто может голосовать
	Street FilterPersonsWhoCanVote() const;

	// Напечатать улицу в stream
	void Print(ostream& stream) const;

private:

	// Название улицы
	string name;

	// Дома на улице
	list<Home> homes;
};
#pragma pack(pop)