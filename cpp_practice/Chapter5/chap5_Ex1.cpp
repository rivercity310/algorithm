#include <iostream>
using namespace std;

/*
1. �� ���� Circle ��ü�� ��ȯ�ϴ� swap() �Լ��� ������ ���� ȣ���� �ǵ��� �ۼ�
*/

class Ex1_Circle {
private:
	int radius;
public:
	Ex1_Circle() : Ex1_Circle(1) {}
	Ex1_Circle(int r) { this->radius = r; }
	int getRadius() {
		return this->radius;
	}
};

void swap(Ex1_Circle& a, Ex1_Circle& b) {
	Ex1_Circle temp = a;
	a = b;
	b = temp;
}

void Ex1() {
	Ex1_Circle first(5);
	Ex1_Circle second(10);
	cout << "first�� ������: " << first.getRadius() << endl;
	cout << "second�� ������: " << second.getRadius() << endl;

	swap(first, second);
	cout << "first�� ������: " << first.getRadius() << endl;
	cout << "second�� ������: " << second.getRadius() << endl;
}