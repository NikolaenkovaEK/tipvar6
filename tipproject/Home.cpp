#include "Home.h"
using namespace std;

Home::Home() {
	// Имя и спиосок жильцов инициализируются пустыми
	no = 0;
}

Home::Home(int no) {
	// Как и в случае с Person, поле no конфликтует с аргументом,
	// поэтому разрешаем этот конфликт с помощью явного обращения к this
	this->no = no;
}

Home::Home(const Home& another) {
	// Копируем все поля
	no = another.no;
	name = another.name;
	persons = another.persons;
}

Home::Home(int no, const string& name) {
	// Аналогично no и name конфликтуют с одноименными полями, 
	// поэтому используем this
	this->no = no;
	this->name = name;
}

Home& Home::operator = (const Home& another) {
	// Избегаем попытки присвоить себя себе
	if(this != &another) {
		no = another.no;
		name = another.name;
		persons = another.persons;
	}
	// Возвращаем ссылку на себя
	return *this;
}

Home::~Home() {
}

void Home::SetHomeNo(int no) {
	// Номер дома не может быть меньше или равным нулю, поэтому
	// проверяем и бросаем исключение
	if(no < 1) {
		throw exception("invalid home no");
	}
	// Снова конфликт имен разрешается через this->
	this->no = no;
}

int Home::GetHomeNo() const {
	return no;
}

void Home::AddPerson(const Person& person) {
	// Добавляем нового жильца в конец списка
	persons.push_back(person);
}

void Home::RemovePerson(const Person& person) {
	// Прежде, чем удалять жильца, нужно его сначала найти.
	// Для этого используем простой линейный поиск.
	// Поскольку у нас по заданию используется список, а не вектор, 
	// то мы не можем просто пройтись по индексам от 0 до persons.size(),
	// поэтому используем итераторы.
	// persons.begin() возвращает итератор на начало списка,
	// persons.end() - на следующий за последним элемент списка, а через
	// *iterator мы получаем доступ к элементу списка.
	for(list<Person>::const_iterator iterator = persons.begin();
		iterator != persons.end(); iterator++) {
		// Для сравнивания жильцов используется соответствующий написанный
		// нами оператор сравнения 
		if(*iterator == person) {
			// Когда мы нашли нужного жильца, то удаляем его и возвращаемся
			// из метода
			persons.erase(iterator);
			return;
		}
	}
	// Если мы дошли сюда, то такого жильца не обнаружено
	throw exception("no such person");
}

void Home::RemovePerson(unsigned int index) {
	// Проверяем корректность индекса, бросаем исключение в случае его 
	// некорректности
	if(index >= persons.size()) {
		throw exception("index out of range");
	}
	// Получаем итератор на начало списка
	list<Person>::const_iterator iterator = persons.begin();
	// Передвигаем итератор на index позиций
	advance(iterator, index);
	// Удаляем элемент, на который указывает итератор
	persons.erase(iterator);
}

const Person& Home::GetPerson(unsigned int index) const {
	// Проверяем корректность индекса, бросаем исключение в случае его 
	// некорректности
	if(index >= persons.size()) {
		throw exception("index out of range");
	}
	// Получаем итератор на начало списка
	list<Person>::const_iterator iterator = persons.begin();
	// Передвигаем итератор на index позиций
	advance(iterator, index);
	// Возвращаем данные жильца, на которого указывает итератор
	return *iterator;
}

void Home::SetPerson(unsigned int index, const Person& person) {
	// Проверяем корректность индекса, бросаем исключение в случае его 
	// некорректности
	if(index >= persons.size()) {
		throw exception("index out of range");
	}
	// Получаем итератор на начало списка
	list<Person>::iterator iterator = persons.begin();
	// Передвигаем итератор на index позиций
	advance(iterator, index);
	// Задаем найденному жильцу данные person
	*iterator = person;
}

unsigned int Home::GetPersonCount() const {
	return persons.size();
}

unsigned int Home::GetPersonCountWhoCanVote() const {
	unsigned int Result = 0;
	// Пробегаемся по всему списку жильцов и увеличиваем счетчик на
	// 1, если жилец может голосовать
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
	// Создаем дом, копируя только номер и имя
	// Жильцы будут заполнены после фильтрации
	Home Result(no, name);
	// Добавляем в список жильцов дома Result только тех, кто может голосовать
	for(std::list<Person>::const_iterator iterator = persons.begin();
		iterator != persons.cend(); iterator++) {
		if((*iterator).CanVote()) {
			Result.AddPerson(*iterator);
		}
	}
	// Возвращаем полученный список
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
	// Попробуем сравнить указатели. Если они совпали, то мы 
	// сравниваем дом с самим собой и должны вернуть true
	if(this == &home) {
		return true;
	}

	// Сначала сравниваем те данные, которые, скорее всего, будут
	// отличаться
	if(no != home.no || 0 != name.compare(home.name)) {
		return false;
	}
	// Сравнение двух списков довольно затратно, поэтому
	// сперва сравним их размеры
	if(persons.size() != home.persons.size()) {
		return false;
	}

	// Пробегаемся по спискам жильцов обоих домов от начала
	// до конца, сравнивая каждого жильца.
	// Одинаковость длины обоих списков была выяснена выше
	std::list<Person>::const_iterator
		iterator1 = persons.begin(),
		iterator2 = home.persons.begin();

	while(iterator1 != persons.end()) {
		// Если хотя бы один из жильцов не совпал с соответствующим
		// в другом списке, то дома не совпадают
		if(*iterator1 != *iterator2) {
			return false;
		}
		iterator1++;
		iterator2++;
	}
	// Всё сравнили, возвращаем true
	return true;
}

bool Home::operator != (const Home& home) const {
	// Чтобы не писать всё то, что написано в операторе ==, 
	// просто используем его инвертированное значение для 
	// сравнения
	return !(*this == home);
}
