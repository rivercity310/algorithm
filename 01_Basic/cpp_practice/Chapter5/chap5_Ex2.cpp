#include <iostream>
using namespace std;

/*
������ ���� ȣ�� ������� �־��� n�� �ݰ��� ���� n�� �ٲٴ� half() �Լ��� �ۼ��϶�
*/

void half(double& n) {
	n = n / 2;
}

void Ex2() {
	double n = 20;
	cout << n << endl;
	half(n);
	cout << n << endl;
}