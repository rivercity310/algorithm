#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
int Ÿ���� ������ ��üȭ�� Integer Ŭ������ �ۼ��϶�
��� ��� �Լ��� �ڵ� �ζ������� �ۼ�
*/

class Integer {
private:
	int integerInt;
public:
	Integer(string str) {
		/*
		char strbuf[100];
		strcpy_s(strbuf, str.c_str());
		this->integerInt = atoi(strbuf);
		*/

		this->integerInt = stoi(str);
	}
	Integer(int integer) { this->integerInt = integer; }
	int get() { return this->integerInt; }
	void set(int r) { this->integerInt = r; }
	bool isEven() {
		if (integerInt % 2 == 0) return true;
		else return false;
	}
};

/*
int main() {
	Integer n(30);
	cout << n.get() << " ";
	n.set(50);
	cout << n.get() << " ";

	Integer m("300");
	cout << m.get() << " ";
	cout << m.isEven() << endl;
}
*/