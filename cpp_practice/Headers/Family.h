#pragma once
#include "Person.h"

class Family {
private:
	Person* p;   // Person �迭 ������
	int size;    // Person �迭�� ũ�� (���� ������ ��)
	string familyName;
public:
	Family(string familyName, int size);
	~Family();
	string getFamilyName() { return this->familyName; }
	void show();     // ��� ���� ������ ���
	void setInfo(int idx, string name, string tel);
};