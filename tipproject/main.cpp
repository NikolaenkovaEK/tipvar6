/*
3)
#ifndef HOME_H
#define HOME_H
Это устаревший способ.Используйте #pragma pack

#pragma pack - это упаковка данных в структуре. 
#pragma once - нестандартное расширение.

5)
Home(const Home & AnotherHome);
Home & operator = (const Home & AnotherHome);
Символь & прижимайте к типу, так же как и с указателем : Home*, Home&.
имя переменных и аргументов называйте с маленькой буквы, чтобы отличать от типов.

Home* a, b, c; -читается три указателя на Home.


8)
std::string HomeName;
std::vector<Person> Persons;
Чтобы не писать все время std::, можно написать на самом верху using namespace std;

Если в заголовочном файле написать using namespace std, то это распространится 
на другие включающие его заголовочные файлы, что может поломать программу 
из - за конфликтов имен из std.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
//int srand(time(NULL)); 

#include "Street.h"

using namespace std;

int main(int argc, char* argv[]) {
	try {
		cout << "creating street\n";
		Street s("Rocky Turn");

		cout << "---------------\n";

		// Добавляем дом
		try {
			cout << "adding home 1\n";
			Home h1(1);
			h1.AddPerson(Person("Bryan Hines", 5));
			h1.AddPerson(Person("Gerald Holland", 15));
			h1.AddPerson(Person("Jody Love", 25));
			s.Add(h1);
		} catch(const exception& e) {
			cout << "adding home 1 failed: " << e.what() << "\n";
		}

		cout << "---------------\n";

		// Добавляем еще один дом
		try {
			cout << "adding home 2\n";
			Home h2(2);
			h2.AddPerson(Person("Irving Schneider", 10));
			h2.AddPerson(Person("Curtis Erickson", 20));
			s.Add(h2);
		} catch(const exception& e) {
			cout << "adding home 2 failed: " << e.what() << "\n";
		}

		cout << "---------------\n";

		// Выводим полученную улицу
		cout << "initial street:\n";
		s.Print(cout);

		cout << "---------------\n";

		// Удаляем существующий дом
		try {
			cout << "removing home 1:\n";
			s.Remove(s.HomeAt(0));
		} catch(const exception& e) {
			cout << "removing home 1 failed: " << e.what() << "\n";
		}

		cout << "---------------\n";

		cout << "street after removing home 1:\n";
		s.Print(cout);

		cout << "---------------\n";

		// Удаляем несуществующий дом
		try {
			cout << "removing home at index 31:\n";
			s.Remove(31);
		} catch(const exception& e) {
			cout << "removing home 31 failed: " << e.what() << "\n";
		}

		cout << "---------------\n";

		// Удаляем другой несуществующий дом
		try {
			cout << "removing empty home:\n";
			s.Remove(Home());
		} catch(const exception& e) {
			cout << "removing empty home failed: " << e.what() << "\n";
		}

		cout << "---------------\n";

		// Фильтруем и выводим тех, кто может голосовать
		try {
			cout << "list of persons who can vote:\n";
			Street f = s.FilterPersonsWhoCanVote();
			cout << f.GetPersonsCount() << " persons can vote\n";
			f.Print(cout);
		} catch(const exception& e) {
			cout << "enlist persons who can vote failed: " << e.what() << "\n";
		}
		system("pause");
		return 0;
	} catch(const exception& e) {
		cout << "error: " << e.what() << "\n\n";
	}
}
