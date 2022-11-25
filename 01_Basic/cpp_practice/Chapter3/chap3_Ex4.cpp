#include <iostream>

using namespace std;
/*
CoffeeMachine Ŭ������ �ۼ��غ���.
[ ��Ģ ]
���������� �� �ܿ��� Ŀ�ǿ� ���� ���� 1�� �Һ�ȴ�.
�Ƹ޸�ī�� �� �ܿ��� Ŀ�ǿ� ���� ���� 1, 2�� �Һ�ȴ�.
���� Ŀ�Ǵ� Ŀ�� 1, �� 2, ���� 1�� �Һ�ȴ�.
*/

class CoffeeMachine {
private:
	int coffee;
	int water;
	int sugar;
public:
	CoffeeMachine();
	CoffeeMachine(int c, int w, int s);

	void fill();
	void show();
	void interfaces();

	void drinkEspresso(int servings);
	void drinkAmericano(int servings);
	void drinkSugarCoffee(int servings);
};

CoffeeMachine::CoffeeMachine() : CoffeeMachine(10, 10, 10) {}
CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	this->coffee = c;
	this->water = w;
	this->sugar = s;
}


// ���� Ŀ�� �ӽ��� ���¸� ���
void CoffeeMachine::show() {
	cout << "\n----------------------------------\n";
	cout << "[ Ŀ�� �ӽ� ���� ]\n";
	cout << "Ŀ��: " << this->coffee << "\n";
	cout << "��: " << this->water << "\n";
	cout << "����: " << this->sugar << "\n";
	cout << "-------------------------------------" << endl;
}

// Ŀ��, ��, ������ 10�� ä��� (�ִ� �뷮�� 10�̶�� ����)
void CoffeeMachine::fill() {
	this->coffee = 10;
	this->water = 10;
	this->sugar = 10;
}

void CoffeeMachine::interfaces() {
	cout << "��ᰡ �����ؿ�..." << endl;
	while (true) {
		cout << "���� ��� ����(1), ä���(2), ������(3) >> ";
		int selected;
		cin >> selected;

		switch (selected) {
		case 1:
			show();
			break;
		case 2:
			fill();
			continue;
		case 3:
			return;
		}
	}
}

// ����������, �Ƹ޸�ī��, ���� Ŀ�� ����
void CoffeeMachine::drinkEspresso(int servings) {
	for (int i = 0; i < servings; i++) {
		if (coffee > 0 && water > 0) {
			this->coffee -= 1;
			this->water -= 1;
		}
		else {
			interfaces();
		}
	}
}

void CoffeeMachine::drinkAmericano(int servings) {
	for (int i = 0; i < servings; i++) {
		if (coffee > 0 && water > 1) {
			this->coffee -= 1;
			this->water -= 2;
		}
		else {
			interfaces();
		}
	}
}

void CoffeeMachine::drinkSugarCoffee(int servings) {
	for (int i = 0; i < servings; i++) {
		if (coffee > 0 && water > 1 && sugar > 1) {
			this->coffee -= 1;
			this->water -= 2;
			this->sugar -= 2;
		}
		else {
			interfaces();
		}
	}
}

void operating(CoffeeMachine* c, int selected) {
	
	cout << "�� ��? ";
	int servings;
	cin >> servings;

	switch (selected) {
	case 1:
		c->drinkEspresso(servings);
		cout << "���������� " << servings << "�� ���Խ��ϴ�~\n" << endl;
		break;
	case 2:
		c->drinkAmericano(servings);
		cout << "�Ƹ޸�ī�� " << servings << "�� ���Խ��ϴ�~\n" << endl;
		break;
	case 3:
		c->drinkSugarCoffee(servings);
		cout << "���� Ŀ�� " << servings << "�� ���Խ��ϴ�~\n" << endl;
		break;
	}

	c->show();
}

/*
int main() {
	cout << "[ �¼� ī�信 ���� ���� ȯ���մϴ�! ]\n" << endl;
	CoffeeMachine myMachine;
	CoffeeMachine* p = &myMachine;
	while (true) {
		cout << "� Ŀ�Ǹ� �ֹ��Ͻðھ��? \n";
		cout << "����������(1), �Ƹ޸�ī��(2), ���� Ŀ��(3), ����(4) >> ";
		int selected;
		cin >> selected;
		if (selected == 4) {
			cout << "�ȳ��� ������!\n" << endl;
			return 0;
		}
		else if (selected > 4) {
			cout << "�� �� ���� ����̳׿�....\n" << endl;
			continue;
		}

		operating(p, selected);
	}
}
*/