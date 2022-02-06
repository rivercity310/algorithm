#include <iostream>
#include <string>

#include "Person.h"

using namespace std;

void Ex9() {
	cout << "��ȭ��ȣ�θ� �����մϴ�... " << endl;
	cout << "����� �����Ͻðھ��? ";
	int length;
	cin >> length;

	Person* personPtr = new Person[length];
	for (int i = 0; i < length; i++) {
		string name, tel;
		cout << "��� " << i << " >> ";
		cin >> name >> tel;

		(personPtr + i)->set(name, tel);
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < length; i++) {
		cout << (personPtr + i)->getName() << " ";
	}
	cout << endl;

	cout << "��ȭ��ȣ�� �˻��մϴ�. �̸���? ";
	string searching;
	cin >> searching;
	for (int i = 0; i < length; i++)
		if ((personPtr + i)->getName() == searching)
			cout << "��ȭ��ȣ�� " << (personPtr + i)->getTel() << endl;


	delete[] personPtr;
}