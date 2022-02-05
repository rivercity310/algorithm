#include <iostream>
#include <string>

using namespace std;
int ID = 0;

/*
���� ���¸� ǥ���ϴ� Account Ŭ���� �ۼ�
- Ŭ���� �����: Account.h�� �ۼ�
- Ŭ���� ������: Account.cpp�� �ۼ�
- main(): main.cpp�� �ۼ�
*/

class Account {
private:
	string name;
	int money;
	int id;

public:
	Account();
	Account(string name, int id, int money);
	void withdraw(int sub);
	void deposit(int add);

	string getOwner() { return this->name; }
	int inquiry() { return this->money; }

	void setName(string name) { this->name = name; }
	void setId(int id) { this->id = id; }
	void setInitMoney(int initMoney) { this->money = initMoney; }
};

Account::Account() : Account("ȫ�浿", 0, 0) {}
Account::Account(string name, int id, int money) {
	this->name = name;
	this->id = id;
	this->money = money;
}

void Account::deposit(int add) {
	this->money += add;
	cout << add << "���� ���������� �ԱݵǾ����ϴ�." << endl;
}

void Account::withdraw(int sub) {
	if (this->money - sub < 0) {
		cout << "����� �Ұ��մϴ�." << endl;
		return;
	}

	this->money -= sub;
	cout << sub << "���� ���������� ��ݵǾ����ϴ�." << endl;
}


/*
int main() {
	Account a;

	while (true) {
		cout << "���� ����(1), �Ա�(2), ���(3), ����(4) : ";
		int selected;
		cin >> selected;

		// case �� ������ ������ �����Ϸ��� �߰�ȣ�� �����־�� �Ѵ�.
		switch (selected) {
		case 1:
		{
			cout << "�̸��� �Ա��� �ܾ��� ��ĭ���� �����Ͽ� �Է�: ";
			string name;
			int initMoney;
			cin >> name >> initMoney;
			a.setName(name);
			a.setInitMoney(initMoney);
			a.setId(ID++);
			cout << "���� ������ �����Ͽ����ϴ�..." << endl;
			break;
		}

		case 2:
		{
			cout << "�󸶸� �Ա��Ͻðھ��? ";
			int add;
			cin >> add;

			a.deposit(add);
			cout << "���� �ܾ�: " << a.inquiry() << endl;
			break;
		}
		case 3:
			cout << "�󸶸� ����Ͻðھ��? ";
			int sub;
			cin >> sub;

			a.withdraw(sub);
			cout << "���� �ܾ�: " << a.inquiry() << endl;
			break;

		case 4:
		{
			cout << "���α׷��� �����մϴ�..." << endl;
			return 0;
		}
		default:
			cout << "�߸��� �����Դϴ�!!!" << endl;
			break;
		}
	}
}
*/