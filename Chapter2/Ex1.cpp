#include <iostream>

using namespace std;

/*
1. 1���� 100���� ������ �� �ٿ� 10���� ���, �� ������ ������ ����
2. �������� ����ϴ� ���α׷� �ۼ�, ������ ����
*/

void printInteger() {
	int count = 1;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << count++ << "\t";
		}

		cout << endl;
	}
}

void printMultiplication() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)
			cout << i << "x" << j << "=" << i * j << '\t';

		cout << endl;
	}
}
