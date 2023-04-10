#include <iostream>
using std::string;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	std::cout << name << std::endl;
	std::cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� : ";
	std::cin >> x >> y;
}

void LoopAdder::write() {
	std::cout << x << "���� " << y << "������ ���� " << sum << "�Դϴ�." << std::endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder {
protected:
	int calculate() {
		int x = getX();
		int y = getY();
		int sum = 0;
		for (int i = x; i <= y; i++) sum += i;

		return sum;
	}
public:
	ForLoopAdder(string name) : LoopAdder(name) {}
};

void chap9_Ex3() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}

class WhileLoopAdder : public LoopAdder {
protected:
	int calculate() {
		int x = getX();
		int y = getY();
		int sum = 0;
		while (true) {
			if (x > y) break;
			sum += x;
			x++;
		}

		return sum;
	}
public:
	WhileLoopAdder(string name) : LoopAdder(name) {}
};

class DoWhileLoopAdder : public LoopAdder {
protected:
	int calculate() {
		int x = getX();
		int y = getY();
		int sum = 0;

		do {
			sum += x;
			x++;
		} while (x <= y);

		return sum;
	}
public:
	DoWhileLoopAdder(string name) : LoopAdder(name) {}
};

void chap9_Ex4() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");

	whileLoop.run();
	doWhileLoop.run();
}