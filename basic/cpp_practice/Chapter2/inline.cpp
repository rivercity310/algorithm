#include <iostream>

using namespace std;

class Person {
private:
	string name;
public:
	Person() { this->name = "ȫ�浿"; }
	~Person() {
		cout << this->name << " �Ҹ�" << endl;;
	}

	// ��� �Լ��� Ŭ���� ����ο� ���� ����
	// �����Ϸ��� ���� inline���� �ڵ� ó����
	void setName(string c) { this->name = c; }
	string getName() { return this->name; }

	void introduce();
};

// inline ����
inline void Person::introduce() {
	cout << "�ȳ��ϼ���! �� �̸��� " << this->name << "�Դϴ�." << endl;;
}

/*
int main() {
	Person p1;
	p1.introduce();

	p1.setName("Ȳ�¼�");
	p1.introduce();
}
*/