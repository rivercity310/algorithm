#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() : Circle(1) {}
	Circle(int r) { this->radius = r; }
	Circle(const Circle& c) {          // ���� ������
		this->radius = c.radius;
		cout << "���� ������ ���� radius = " << radius << endl;
	}
	double getArea() { return 3.14 * pow(radius, 2); }
};

void copyConstructor() {
	Circle src(30);     // src ��ü�� ���� ������ ȣ��
	Circle dest(src);   // dest ��ü�� ���� ������ ȣ��

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;
}