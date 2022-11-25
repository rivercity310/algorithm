#include <iostream>

#include "Container.h"
#include "CoffeeVendingMachine.h"

using namespace std;

Container::Container() {
	size = 10;
}

void Container::fill() {
	size = 10;
}

void Container::consume(int n) {
	this->size -= n;
}

int Container::getSize() {
	return this->size;
}

CoffeeVendingMachine::CoffeeVendingMachine() {
	tank = new Container[3];
}

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++)
		(tank + i)->fill();
}

// 0�� Ŀ��, 1�� ��, 2�� ������
void CoffeeVendingMachine::checkTank(int selected) {
	int coffee = (tank + 0)->getSize();
	int water = (tank + 1)->getSize();
	int sugar = (tank + 2)->getSize();

	switch (selected) {
	case 1:
		if (coffee >= 1 && water >= 1) selectEspresso();
		else cout << "��ᰡ �����ؿ�!" << endl;
		break;
	case 2:
		if (coffee >= 1 && water >= 2) selectAmericano();
		else cout << "��ᰡ �����ؿ�!" << endl;
		break;
	case 3:
		if (coffee >= 1 && water >= 2 && sugar >= 1) selectSugarCoffee();
		else cout << "��ᰡ �����ؿ�!" << endl;
		break;
	}
}

void CoffeeVendingMachine::selectEspresso() {
	(tank + 0)->consume(1);
	(tank + 1)->consume(1);
	cout << "���������� ���Խ��ϴ�!" << endl;
}

void CoffeeVendingMachine::selectAmericano() {
	(tank + 0)->consume(1);
	(tank + 1)->consume(2);
	cout << "�Ƹ޸�ī�� ���Խ��ϴ�!" << endl;
}

void CoffeeVendingMachine::selectSugarCoffee() {
	(tank + 0)->consume(1);
	(tank + 1)->consume(2);
	(tank + 2)->consume(1);
	cout << "����Ŀ�� ���Խ��ϴ�!" << endl;
}

void CoffeeVendingMachine::show() {
	int coffee = (tank + 0)->getSize();
	int water = (tank + 1)->getSize();
	int sugar = (tank + 2)->getSize();

	cout << "Ŀ��: " << coffee << ", ��: " << water << ", ����: " << sugar << endl;
}

void CoffeeVendingMachine::run() {
	cout << "**** Ŀ�����Ǳ⸦ �۵��մϴ� ****" << endl;
	while (true) {
		cout << "�޴� (1: ����������, 2: �Ƹ޸�ī��, 3: ����Ŀ��, 4: �ܷ�����, 5: ä���)" << endl;
		int selected;
		cin >> selected;
		
		switch (selected) {
		case 1:
		case 2:
		case 3:
			checkTank(selected);
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			show();
			break;
		default:
			cout << "�߸��� �Է��̳׿�... " << endl;
			break;
		}
	}
}


void Ex11() {
	CoffeeVendingMachine CVM;
	CVM.run();
}