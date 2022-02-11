#include <iostream>
using namespace std;

class Rect_6;        // forward reference(���� ����)�� ���� ���� ����

class RectManager {
public:
	bool equals(Rect_6 r, Rect_6 s);
	void copy(Rect_6& dest, Rect_6& src);
};

class Rect_6 {
	int width, height;
public:
	Rect_6(int width, int height) { this->width = width; this->height = height; }
	friend RectManager;    // RectManager Ŭ������ ��� �Լ��� ������ �Լ��� ����
};

bool RectManager::equals(Rect_6 r, Rect_6 s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void RectManager::copy(Rect_6& dest, Rect_6& src) {
	dest.width = src.width;
	dest.height = src.height;
}

void Friend() {
	Rect_6 a(3, 4), b(5, 6);
	RectManager man;

	if (man.equals(a, b)) cout << "Equal!" << endl;
	else cout << "Not Equal!" << endl;

	man.copy(b, a);
	if (man.equals(a, b)) cout << "Equal!" << endl;
	else cout << "Not Equal!" << endl;
}