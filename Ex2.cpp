#include <iostream>

using namespace std;

void bubbleSort(float* k, int size);
void maxInteger();
void maxFloat();

/*
1. Ű����κ��� �� ���� ������ �о� ū ���� ȭ�鿡 ���
2. �Ҽ����� ������ 5���� �Ǽ��� �Է� �޾� ���� ū ���� ȭ�鿡 ���
*/

void maxInteger() {
	cout << "�� ���� �Է��϶�: ";
	int x, y;
	cin >> x >> y;

	int result = x > y ? x : y;
	cout << "ū �� = " << result << endl;
}

void maxFloat() {
	cout << "5���� �Ǽ��� �Է��϶�: ";
	
	float k[5];
	for (int i = 0; i < sizeof(k) / sizeof(k[0]); i++) cin >> k[i];

	cout << "�Է¹��� �迭: \n";
	for (int i = 0; i < 5; i++) cout << k[i] << "  ";
	cout << endl;

	bubbleSort(k, 5);
	cout << "���� ���� �� �迭: \n";
	for (int i = 0; i < 5; i++) cout << k[i] << "  ";
	cout << endl;

	cout << "���� ū �� = " << k[4] << endl;
}

void bubbleSort(float *k, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (k[j] > k[j + 1]) {
				float temp = k[j + 1];
				k[j + 1] = k[j];
				k[j] = temp;
			}
		}
	}
}
