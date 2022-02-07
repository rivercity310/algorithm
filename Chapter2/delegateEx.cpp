#include <iostream>

using namespace std;

class Point {
private:
	// �ʵ忡 ���� �����Ͽ� �ʱ�ȭ ����
	// ex) int x = 0; int y = 1;
	int x, y;
public:
	Point();
	Point(int x, int y);
	~Point();
	void show();
};

Point::Point() : Point(0, 0) {}
Point::Point(int a, int b) : x(a), y(b) {}   // �̷��� �����ص� ��

Point::~Point() {
	
	cout << "�� " << x << ", " << y << " �Ҹ�" << endl;
}

void Point::show() {
	cout << "(" << x << ", " << y << ")" << endl;
}

/*
int main() {
	Point k1;
	k1.show();

	Point k2(5, 6);
	k2.show();
}
*/