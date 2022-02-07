#include <iostream>
#include "Rect.h"

using namespace std;

Rect::Rect() : Rect(1, 1) {}
Rect::Rect(int w, int h) : width(w), height(h) {}
Rect::~Rect() { cout << "Rect ��ü �Ҹ�..." << endl; }

void Rect::setWidth(int w) { width = w; }
void Rect::setHeight(int h) { height = h; }
int Rect::getArea() {
	return width * height;
}

/*
int main() {
	Rect rectArray[3];      // Rect ��ü �迭 ����
	
	for (int i = 0; i < 3; i++) {
		cout << "width�� height �Է�: ";
		int w, h;
		cin >> w >> h;
		rectArray[i].setWidth(w);
		rectArray[i].setHeight(h);
	}

	for (int i = 0; i < 3; i++)
		cout << "rectArray[" << i << "]�� ������: " << rectArray[i].getArea() << endl;

	// ��ü �����ͷ� �迭 ����
	Rect* rectPtr;
	rectPtr = rectArray;
	for (int i = 0; i < 3; i++) {
		cout << "rectArray[" << i << "]�� ������: " << rectPtr->getArea() << endl;
		rectPtr++;
	}
}
*/