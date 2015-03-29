#pragma pack(push,1)

#include <string>
#include <ostream>
using namespace std;

class Person {
public:
	// ����������� ��� ����������
	Person();

	// ����������� �� ����� � ��������
	Person(const string& name, unsigned int age);

	// ����������� �����
	Person(const Person& another);

	// �������� ������������
	Person& operator = (const Person& another);

	// ����������
	~Person();

	// �������� ��� 
	const string& GetName() const;

	// ���������� ���
	void SetName(const string& name);

	// �������� �������
	unsigned int GetAge() const;

	// ���������� �������
	void SetAge(unsigned int age);

	// ���������� � ����� stream
	void Print(ostream& stream) const;

	// ���������� true, ���� ������� ����� ����������
	bool CanVote() const;

	// �������� ��������� ������, � ������� �� Home, ������� 
	// �������������� ���������� ��� ������������
	friend bool operator == (const Person& p1, const Person& p2);
	friend bool operator != (const Person& p1, const Person& p2);

private:
	// ���
	string name;

	// �������
	unsigned int age;
};
#pragma pack(pop)
