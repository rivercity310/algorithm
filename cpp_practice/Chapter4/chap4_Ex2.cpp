#include <iostream>

using namespace std;

/*
���� ���� 5���� �迭�� ���� �Ҵ�ް�, ������ 5�� �Է¹޾� ����� ����� �� �迭�� �Ҹ��Ű���� �ۼ�
*/

void Ex2() {
	int* dIntAry = new int[5];
	int sum = 0;

	cout << "���� 5�� �Է�: ";
	for (int i = 0; i < 5; i++) {
		int inputVal;
		cin >> inputVal;
		dIntAry[i] = inputVal;

		sum += dIntAry[i];
	}

	double aver = (double)sum / 5;
	cout << "�����: " << aver << "�Դϴ�." << endl;
	delete[] dIntAry;
}