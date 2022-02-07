#include <iostream>
#include "Circle.h"

using namespace std;

inline Circle::Circle() {
	cout << "���� ���������� �����Ǿ����ϴ�." << endl;
}

inline Circle::~Circle() {
	cout << "������ " << radius << "�� �� �Ҹ�!" << endl;
}

inline void Circle::setRadius(int radius) {
	this->radius = radius;
}

inline double Circle::getArea() {
	return 3.14 * pow(radius, 2);
}

void Ex7() {
	cout << "�� ��� �����ұ��? ";
	int length;
	cin >> length;

	Circle* circlePtr = new Circle[length];
	int areaCheck = 0;
	for (int i = 0; i < length; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		int radius;
		cin >> radius;
		(circlePtr + i)->setRadius(radius);

		double circleArea = (circlePtr + i)->getArea();
		if (circleArea >= 100) areaCheck++;
	}

	cout << "������ 100���� ū ���� " << areaCheck << "�� �Դϴ�." << endl;
	delete[] circlePtr;
}