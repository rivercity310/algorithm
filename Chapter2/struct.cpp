#include <iostream>

using namespace std;

struct stCircle {
	// ����ü�� ����Ʈ ���� ������ public
	stCircle();
	stCircle(int r);
	~stCircle();
	double getArea();

private:
	int radius;
};

stCircle::stCircle() : stCircle(1) {}
stCircle::stCircle(int r) {
	this->radius = r;
}
stCircle::~stCircle() {
	cout << radius << " �� �Ҹ�";
}

double stCircle::getArea() {
	return 3.14 * radius * radius;
}

class classCircle {
	// Ŭ������ ����Ʈ ���� ������ private
	int radius;
public:
	classCircle();
	classCircle(int r);
	double getArea();
}; 

/*
int main() {
	stCircle st1;
	cout << st1.getArea() << endl;
}
*/