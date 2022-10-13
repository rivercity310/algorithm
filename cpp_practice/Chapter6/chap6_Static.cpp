#include <iostream>
using namespace std;

class Chap6_Person {
	int money;    // ���� ������ ��
public:
	Chap6_Person(int money) { this->money = money; }
	void addMoney(int money) { this->money += money; }
	int getMoney() { return this->money; }
	static int sharedMoney;  // ����
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static ��� ������ �ܺο� ���� ������ ����Ǿ�� �Ѵ�.
int Chap6_Person::sharedMoney = 100;

void St() {
	Chap6_Person han(100);
	han.addMoney(300);    // han�� ���� ��
	han.sharedMoney = 200;  // ����
	Chap6_Person::addShared(1000);    // ::�� �̿��ؼ��� ���� ����

	Chap6_Person lee(500);
	lee.addMoney(550);
	lee.addShared(1000);

	cout << "han's money: " << han.getMoney() << endl;
	cout << "lee's money: " << lee.getMoney() << endl;
	cout << "Shared Money: " << Chap6_Person::sharedMoney << endl;
}