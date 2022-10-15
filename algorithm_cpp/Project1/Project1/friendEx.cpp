#include <iostream>
using namespace std;

/*
friend: Ŭ���� ��� �Լ��δ� �������� ������, Ŭ������ private, protected ����� �����ؾ� �ϴ� ���
���� Ŭ������ ��� �Լ��� �ƴϹǷ� ��ӵ����� �ʴ´�.
*/

class RectManager;

class Rect {
private:
	int width, height;
public:
	Rect(int a, int b) : width(a), height(b) {};
	friend RectManager;
};

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void friendEx() {
	Rect a(3, 4), b(4, 5), c(4, 5);
	RectManager manager;

	if (manager.equals(b, c)) cout << "Equal!" << endl;
	else cout << "Not Equal!!" << endl;
}