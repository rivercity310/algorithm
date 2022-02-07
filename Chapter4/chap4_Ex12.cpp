#include <iostream>
#include <string>

#include "CircleManager.h"
using namespace std;

void namedCircle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}

double namedCircle::getArea() {
	return 3.14 * pow(radius, 2);
}

string namedCircle::getName() {
	return name;
}




CircleManager::CircleManager(int size) {
	this->size = size;
	circlePtr = new namedCircle[size];
}

CircleManager::~CircleManager() {
	cout << "CircleManager �Ҹ�!!" << endl;
}

void CircleManager::initCircle() {
	for (int i = 0; i < size; i++) {
		string name;
		int radius;
		cout << "�� " << i + 1 << "�� �̸��� ������: ";
		cin >> name >> radius;
		(circlePtr + i)->setCircle(name, radius);
	}
}


void CircleManager::searchByName() {
	cout << "�˻��ϰ��� �ϴ� ���� �̸�: ";
	string inputStr;
	cin >> inputStr;

	for (int i = 0; i < size; i++) {
		string circleName = (circlePtr + i)->getName();
		if (circleName == inputStr) {
			cout << inputStr << "�� ������ " << (circlePtr + i)->getArea() << endl;
			return;
		}
	}

	cout << "��ϵ��� ���� ���Դϴ�." << endl;
	return;
}

void CircleManager::searchByArea() {
	cout << "�ּ� ������ ������ �Է��ϼ���: ";
	int minArea;
	cin >> minArea;

	cout << minArea << "���� ū ���� �˻��մϴ�." << endl;
	for (int i = 0; i < size; i++) {
		double area = (circlePtr + i)->getArea();
		if (minArea <= area) {
			string circleName = (circlePtr + i)->getName();
			cout << circleName << "�� ������ " << area << ", ";
		}
	}
	cout << endl;
	return;
}

void Ex12() {
	cout << "���� ���� >> ";
	int size;
	cin >> size;
	CircleManager CM(size);
	CM.initCircle();

	while (true) {
		CM.searchByName();
		CM.searchByArea();
	}
}