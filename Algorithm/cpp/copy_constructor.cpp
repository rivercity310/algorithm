#include <iostream>
using namespace std;

/*
���� �������� �Ű� ������ �ڱ� Ŭ������ ���� ������ �����Ѵ�.

����Ʈ ���� �������� ��� ���� ���簡 �Ͼ�� ������ ������ Ÿ���� ��� ������ ���� ���
������ ������ �߻��� �� �ִ�.

���� �׷� ��쿡�� ���� �����ڸ� �ۼ��Ͽ� ���� ���簡 �Ͼ�� ������־�� �Ѵ�.
*/

class Person {
private:
	char* name;
	int id;

public:
	Person(int id, const char* name);
	
	Person(const Person& person);
	
	~Person();
	
	void changeName(const char* name);

	void show() {
		cout << id << ", " << name << endl;
	}
};

Person::Person(int id, const char* name) {
	this->id = id;
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

Person::Person(const Person& person) {
	this->id = person.id;
	int len = strlen(person.name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, person.name);
	cout << "���� ������ ����! ���� ��ü�� �̸�: " << this->name << endl;
}

Person::~Person() {
	if (name) delete[] name;
}

void Person::changeName(const char* name) {
	if (strlen(name) > strlen(this->name)) return;
	strcpy_s(this->name, strlen(name) + 1, name);
}

void copy_constructor() {
	Person father(1, "Kitae");
	Person daughter(father);        // ��ü ���� ���� -> ���� ������ ȣ��

	cout << "daughter ��ü ���� ���� --- " << endl;
	father.show();
	daughter.show();

	daughter.changeName("Grace");
	cout << "daughter �̸� ���� �� --- " << endl;
	father.show();
	daughter.show();

	Person newPerson = daughter;	// ��ü ���� ���� -> ���� ������ ȣ��
	daughter.show();
	newPerson.show();
	newPerson.changeName("chged");

	cout << "����� ������ �̸� ���� ��" << endl;
	daughter.show();
	newPerson.show();
}