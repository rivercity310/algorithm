#pragma once
#include <string>

using namespace std;

class namedCircle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

class CircleManager {
	namedCircle* circlePtr;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	void initCircle();       // Circle ��ü �迭 �ʱ�ȭ
	void searchByName();     // ����ڷκ��� ���� �̸��� �Է¹޾� ���� ���
	void searchByArea();     // ����ڷκ��� ������ �Է¹޾� �������� ū �� ���
};