#include <iostream>

// C/C++ ������ ���� �ڼ��� ����: https://modoocode.com/304
// �Ʒ� �� ���̺귯���� C ��Ÿ�� ���� �߻��� ���� ����Ѵ�.
#include <cstdlib>
#include <ctime>

// C++�� ���� �߻��� ���� ���̺귯��
#include <random>

using namespace std;

/*
���� ���� �߻���Ű�� Random Ŭ������ �����, ������ ������ 10�� ���
*/

class Random {
private:
	int randomInteger;
public:
	int next();
	int nextInRange(int left, int right);

	int getRandomInteger() { return this->randomInteger; }
};

// 0���� RAND_MAX(32767) ������ ������ ������ ����
int Random::next() {
	// C ��Ÿ���� ���� �߻� (���� ������)
	srand((unsigned)::time(0));
	this->randomInteger = rand();
	

	return this->randomInteger;
}

// left <= x <= right�� �����ϴ� x ����
int Random::nextInRange(int left, int right) {
	// C++�� random ���̺귯���� ���� ���� �߻�
	
	random_device rd;      // �õ尪�� ��� ���� random_device ����
	mt19937 gen(rd());     // random_device�� ���� ���� ���� ������ �ʱ�ȭ�Ѵ�

	// left���� right���� �յ��ϰ� ��Ÿ���� ������ �����ϱ� ���� �յ� ���� ����
	uniform_int_distribution<int> dis(left, right);   
	
	// ���� ȹ��
	this->randomInteger = dis(gen);
	
	return this->randomInteger;
}

/*
int main() {
	Random r;
	cout << "0���� " << RAND_MAX << "������ ������ ���� 10�� ���" << endl;
	for (int i = 0; i < 10; i++) cout << r.next() << " ";
	cout << endl;

	cout << "0���� 100������ ������ ���� 10�� ��� " << endl;
	for (int i = 0; i < 10; i++) cout << r.nextInRange(0, 100) << " ";
	cout << endl;

	cout << "0���� 100���� ¦�� ���� 10�� ���" << endl;
	int count = 0;
	while (count < 10) {
		int k = r.nextInRange(0, 100);
		if (k % 2 == 0) {
			cout << k << " ";
			count++;
		}
		else continue;
	}
	cout << endl;

	cout << "0���� 100���� Ȧ�� ���� 10�� ���" << endl;
	int count2 = 0;
	while (count2 < 10) {
		int k = r.nextInRange(0, 100);
		if (k % 2 != 0) {
			cout << k << " ";
			count2++;
		}
		else continue;
	}
	cout << endl;
}
*/