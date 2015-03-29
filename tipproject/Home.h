#pragma pack(push,1)

#include <string>
#include <list>
#include <ostream>
using namespace std;

#include "Person.h"

// Home - ��������� ��� Person
class Home {
public:
	// ����������� �� ���������
	Home();

	// ����������� �� ������ ����
	Home(int no);

	// ����������� �����
	Home(const Home& another);

	// ����������� �� ������ � ����� ����
	Home(int no, const string& name);

	// �������� ������������
	Home& operator = (const Home& another);

	// ����������
	~Home();

	// ���������� ����� ����
	void SetHomeNo(int no);

	// �������� ����� ����
	int GetHomeNo() const;

	// �������� ������
	void AddPerson(const Person& person);

	// ������ ������ person
	// ���� ������ ��� - ����� ������� ����������
	void RemovePerson(const Person& person);

	// ������ ������ �� ��� �������
	void RemovePerson(unsigned int index);

	// �������� ������ �� ��� �������
	const Person& GetPerson(unsigned int index) const;

	// �������� ������ �� person �� ��� �������
	void SetPerson(unsigned int index, const Person& person);

	// ������� ���������� ������� ����
	unsigned int GetPersonCount() const;

	// ������� ���������� ������� ����, ������� ����� ����������
	unsigned int GetPersonCountWhoCanVote() const;

	// ������ ��� ����
	void SetHomeName(const string& name);

	// �������� ��� ����
	const string& GetHomeName() const;

	// ���������� ��� � stream
	void Print(ostream& stream) const;

	// ������� ����� ������ ���� � ���� ��������, ������� ����� ����������
	Home FilterPersonsWhoCanVote() const;

	// �������� � ���� ������ person
	Home& operator += (const Person& person);

	// ������� ��� � ����������� ������� person
	Home operator + (const Person& person) const;

	// ��������� �����, ������� ��� ������ ������ ��� ������������
	bool operator == (const Home& home) const;
	bool operator != (const Home& home) const;

private:
	// ����� ����
	int no;

	// ��� ����
	string name;

	// ������ ������� ����
	list<Person> persons;
};
#pragma pack(pop)
