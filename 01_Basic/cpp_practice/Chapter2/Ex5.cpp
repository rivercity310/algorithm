#include <iostream>
#include <string>

using namespace std;

/*
1. �̸�, ����, �ּҸ� �Է¹ް� �ٽ� ���
2. ���ڿ��� �ϳ� �Է¹ް� �κ� ���ڿ��� ���
*/

void printInfo() {
	string name;
	string address;
	string age;

	cout << "�̸�? ";
	getline(cin, name);
	cout << "�ּ�? ";
	getline(cin, address);
	cout << "����? ";
	getline(cin, age);

	cout << name + ", " + address + ", " + age + "��" << endl;
}

void printSubStr() {
	string inputStr;
	cout << "���ڿ� �Է�: ";
	getline(cin, inputStr);

	for (int i = 0; i < inputStr.size(); i++)
		cout << inputStr.substr(0, i + 1) << endl;
}
