#include <iostream>
#include <cstring>

using namespace std;

void restaurant() {
	cout << "�߽Ĵ翡 ���� ���� ȯ���մϴ�." << endl;

	while (true) {
		cout << "«��: 1, ¥��:2, ������:3, ����:4 >> ";
		int selected;
		cin >> selected;
		if (selected == 4) {
			cout << "���� ������ �������ϴ�." << endl;
			break;
		}

		cout << "�� �κ�? ";
		int servings;
		cin >> servings;
		
		switch (selected) {
		case 1:
			cout << "«�� " << servings << "�κ� ���Խ��ϴ�." << endl;
			break;
		case 2:
			cout << "¥�� " << servings << "�κ� ���Խ��ϴ�." << endl;
			break;
		case 3:
			cout << "������ " << servings << "�κ� ���Խ��ϴ�." << endl;
			break;
		default:
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
			break;
		}
	}
}

void cafe() {
	int total = 0;
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�." << endl;
	
	while (true) {
		if (total >= 20000) {
			cout << "���� ������ ����! " << total << endl;
			break;
		}

		cout << "�ֹ�: ";
		string beverage;
		int servings;
		cin >> beverage >> servings;

		if (beverage == "espresso") total += 2000 * servings;
		else if (beverage == "americano") total += 2300 * servings;
		else if (beverage == "cafuccino") total += 2500 * servings;
		else {
			cout << "�߸��� �Է��Դϴ�...." << endl;
			continue;
		}

		cout << beverage << " " << servings << "�� ���Խ��ϴ�." << endl;
	}
}
