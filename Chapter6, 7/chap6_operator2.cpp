#include <iostream>
using namespace std;

class Power2 {
	int kick;
	int punch;
public:
	Power2(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show() {
		cout << "Kick: " << kick << ", " << "Punch: " << punch << endl;
	}
	Power2 operator++(int x);     // ���� �����ڿ��� ������ ���� �ǹ̾��� �Ű����� x�� �������� �����ؾ� �Ѵ�.
};

Power2 Power2::operator++(int x) {
	Power2 temp = *this;       // ���� ���� ��ü ���¸� ����
	kick++;
	punch++;
	return temp; 
}

void oper2() {
	Power2 a(3, 5), b;
	a.show();
	b.show();
	b = a++;
	a.show();
	b.show();
}