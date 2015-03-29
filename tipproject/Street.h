#pragma pack(push,1)

#include <ostream>
#include <list>
using namespace std;

#include "Home.h"

// Street - ��������� ��� Home
class Street {
public:
	// ����������� �� ���������
	Street();

	// ����������� ����� �� ������ �����
	Street(const Street& another);

	// ����������� ����� �� � �����
	Street(const string& name);

	// �������� ������������
	Street& operator = (const Street& another);

	// ����������
	~Street();


	// �������� ��� �� ��� �������
	// ������������� ������, ������� ��������� �������� ���
	// �� ������������ ������
	Home& HomeAt(unsigned index);

	// �������� ��� �� ��� �������
	// ����������� ������, ������� �� ��������� �������� ���
	// �� ������������ ������, ������� ��� ����, ����� 
	// ����� ���� ������ ������ ���� � ����������� �����
	const Home& HomeAt(unsigned index) const;

	// ������ ����� ��������
	void SetName(const string& name);

	// �������� �������� �����
	const string& GetName() const;

	// �������� � ����� ���
	void Add(const Home& home);

	// ������� ��� ����� �� �������
	void Remove(unsigned int index);

	// ������� ��� �����
	void Remove(const Home& home);
	


	// ������� ���������� �����
	unsigned int GetHomeCount() const;

	// ������� ����� ���������� ������� �����
	unsigned int GetPersonsCount() const;

	// ������� ���������� ������� �����, ������� ����� ����������
	unsigned int GetPersonsCountWhoCanVote() const;

	// ������� ����� ������ ����� ������ � ���� ������, ��� ����� ����������
	Street FilterPersonsWhoCanVote() const;

	// ���������� ����� � stream
	void Print(ostream& stream) const;

private:

	// �������� �����
	string name;

	// ���� �� �����
	list<Home> homes;
};
#pragma pack(pop)