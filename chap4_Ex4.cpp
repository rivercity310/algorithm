#include <iostream>
#include "Sample.h"
using namespace std;

/*
Sample Ŭ������ �ۼ��ϰ� Ȱ���ϱ�
*/


void Sample::read() {
	cout << "���� " << size << "�� �Է�: ";
	for (int i = 0; i < size; i++) {
		int inputInt;
		cin >> inputInt;
		p[i] = inputInt;
	}

	cout << "�迭�� ���������� �����Ͽ����ϴ�." << endl;
}

void Sample::write() {
	cout << "�迭�� ����մϴ�... " << endl;
	for (int i = 0; i < size; i++) {
		cout << "*(p + " << i << ")�� ��: " << *(p + i) << endl;
	}
	cout << endl;
}

int Sample::big() {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (p[i] >= max) max = p[i];
	}

	return max;
}

void Ex4() {
	Sample s(10);
	s.read();
	s.write();
	cout << "�迭���� ���� ū ���� " << s.big() << endl;
}