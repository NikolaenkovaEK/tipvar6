#include "Street.h"
using namespace std;

Street::Street() {
}

Street::Street(const Street& another) {
	// Задаем имя и дома такими же, как и у another
	name = another.name;
	homes = another.homes;
}

Street::Street(const string& name) {
	// Разрешаем конфликт имени аргумента и имени поля name
	// с помощью явного обращения через this->
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
	// Проверяем правильность индекса и бросаем исключение, если индекс вне диапазона
	if(index >= homes.size()) {
		throw exception("index out of range");
	}
	// Получаем итератор на первый элемент списка
	// Тут итератор константный, который дает менять данные, на которые он указывает
	list<Home>::iterator iterator = homes.begin();
	// Сдвигаем итератор на index позиций
	advance(iterator, index);
	// Возвращаем данные, на которые указывает итератор
	return *iterator;
}

const Home& Street::HomeAt(unsigned index) const {
	// Проверяем правильность индекса и бросаем исключение, если индекс вне диапазона
	if(index >= homes.size()) {
		throw exception("index out of range");
	}
	// Получаем итератор на первый элемент списка
	// Тут итератор константный, который не дает менять данные, на которые он указывает
	list<Home>::const_iterator iterator = homes.begin();
	// Сдвигаем итератор на index позиций
	advance(iterator, index);
	// Возвращаем данные, на которые указывает итератор
	return *iterator;
}

void Street::SetName(const string& name) {
	this->name = name;
}

const string& Street::GetName() const {
	return name;
}

void Street::Add(const Home& home) {
	// Добавляем новый дом в конец списка
	homes.push_back(home);
}	

void Street::Remove(unsigned int index) {
	// Проверяем правильность индекса и бросаем исключение, если индекс вне диапазона
	if(index >= homes.size()) {
		throw exception("index out of range");
	}
	// Получаем итератор на первый элемент списка
	// Нам не нужно менять данные в списке, поэтому const_iterator
	list<Home>::const_iterator iterator = homes.begin();
	// Сдвигаем итератор на index позиций
	advance(iterator, index);
	// Удаляем жильца, на которого указывает итератор
	homes.erase(iterator);
}

void Street::Remove(const Home& home) {
	// Итерируем через все дома, сравнивая каждый с home
	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.cend(); iterator++) {
		// Нашли такой же дом - удаляем и возвращаемся из метода
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
	unsigned int Result = 0;

	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.end(); iterator++) {
		// У каждого дома есть метод, возвращающий количество жильцов, 
		// которые могут голосовать, воспользуемся им для подсчета
		Result += (*iterator).GetPersonCountWhoCanVote();
	}

	return Result;
}

Street Street::FilterPersonsWhoCanVote() const {
	// Воспользуемся конструктором из имени для создания новой улицы
	Street Result(name);

	for(list<Home>::const_iterator iterator = homes.begin();
		iterator != homes.end(); iterator++) {
		// Добавляем к улице Result дома с отфильтрованным списком жильцов
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
