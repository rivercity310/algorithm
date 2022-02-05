#include <iostream>

using namespace std;

class Tower {
private:
	int height;
public:
	Tower();
	Tower(int height);
	~Tower();
	int getHeight();
};

Tower::Tower() : Tower(1) {}
Tower::Tower(int height) {
	this->height = height;
}
Tower::~Tower() {
	cout << "���� " << this->height << "Ÿ�� �Ҹ�" << endl;
}

int Tower::getHeight() {
	return this->height;
}

/*
int main() {
	Tower myTower;
	Tower seoulTower(100);

	cout << "���̴� " << myTower.getHeight() << "����" << endl;
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
}
*/