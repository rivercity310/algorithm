#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, const char* name);     // ������
	Person(const Person& person);         // ���� ������
	~Person();
	void changeName(const char* name);
	void show() {
		cout << id << ", " << name << endl;
	}
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];  // name ���ڿ� ���� �Ҵ�
	strcpy(this->name, name);        // name�� ���ڿ� ����
}

// ���� ���� ������
Person::Person(const Person& person) {
	this->id = person.id;
	int len = strlen(person.name);
	this->name = new char[len + 1];
	strcpy(this->name, person.name);
	cout << "���� ������ ����. ���� ��ü�� �̸� " << this->name << endl;
}

Person::~Person() {
	if (name)  // ���� name�� ���� �Ҵ�� �迭�� ������
		delete[] name;
}

void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name)) return;     // ���� name�� �Ҵ�� �޸𸮺��� �� �̸����� ���� �Ұ�
	strcpy(this->name, name);
}

void deepCopy() {
	Person father(1, "Kitae");
	Person daughter(father);

	cout << "daughter ��ü ���� ���� ---- " << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter�� �̸��� Grace�� ���� �� ---- " << endl;
	father.show();
	daughter.show();
}

// ���� ���� ȣ��� ��ü�� ���޵Ǵ� ��� person ��ü�� ���� ������ ȣ��
void f(Person person) {
	person.changeName("dummy");
}

// �Լ����� ��ü�� �����ϴ� ���, mother ��ü�� ���纻 ����, ���纻�� ���� ������ ȣ��
Person g() {
	Person mother(2, "Jane");
	return mother;
}

void impliedlyCall() {
	Person father(1, "Kitae");
	Person son = father;       // ��ü�� �ʱ�ȭ�Ͽ� ��ü�� ������ ��, son ��ü�� ���� ������ ȣ��
	f(father);
	g();
}