#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) {
		big = a;
		return true;
	}

	big = a > b ? a : b;
	return false;
}

void Ex4() {
	cout << "���� 2�� �Է�: ";
	int a, b;
	cin >> a >> b;

	int big;
	if (!bigger(a, b, big)) cout << "�� ū���� " << big << "�Դϴ�." << endl;
	else cout << "�� ���� �����ϴ�." << endl;
}