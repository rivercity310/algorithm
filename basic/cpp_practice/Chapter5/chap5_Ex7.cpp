#include <iostream>
using namespace std;

class MyIntStack {
	int* p;      // �ִ� 10���� ���� ����
	int tos;     // ������ ����⸦ ����Ű�� �ε���
	int size;    // ������ �ִ� ũ��
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);   // ���� ������
	~MyIntStack();
	bool push(int n);      // ���� n Ǫ��, �� �������� false, �ƴϸ� true
	bool pop(int& n);      // ���Ͽ� n�� ����, ��������� false, �ƴϸ� true
};

MyIntStack::MyIntStack() : MyIntStack(10) {}
MyIntStack::MyIntStack(int size) {
	this->size = size;
	p = new int[size];
	tos = 0;
}
MyIntStack::MyIntStack(const MyIntStack& s) {
	this->size = s.size;
	this->tos = s.tos;
	this->p = new int[size];
	
}

MyIntStack::~MyIntStack() {
	cout << "������ " << size << " stack �Ҹ�!" << endl;
}

bool MyIntStack::push(int n) {
	if (tos < 10) {
		*(p + tos) = n;
		tos++;
		return true;
	}

	return false;
}

bool MyIntStack::pop(int& n) {
	if (tos > 0) {
		tos--;
		n = *(p + tos);
		return true;
	}

	return false;
}


void Ex7() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << " ";
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}

	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << " ";
		else cout << endl << i + 1 << " ��° stack empty" << endl;
	}
}

void Ex8() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;   // ���� ����
	b.push(30);

	int n;
	a.pop(n);
	cout << "���� a���� ���� �� " << n << endl;
	
	b.pop(n);
	cout << "���� b���� ���� �� " << n << endl;
}