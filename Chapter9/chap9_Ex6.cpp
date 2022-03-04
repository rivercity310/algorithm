#include <iostream>

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int getSize() = 0;
};

class IntStack : public AbstractStack {
private:
	int capacity;
	int size;
	int* mem;
public:
	IntStack(int capacity = 100);
	~IntStack();
	bool push(int n);      // ���ÿ� n�� Ǫ���Ѵ�. ������ Ǯ�̸� false ����
	bool pop(int& n);      // ���ÿ��� ���� ������ n�� �����ϰ�, ������ empty�̸� false ����
	int getSize() { return this->size; }   // ���� ���ÿ� ����� ������ ���� ����
};

IntStack::IntStack(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->mem = new int[capacity];
}

IntStack::~IntStack() { 
	delete[] mem;
}

bool IntStack::push(int n) {
	if (size <= capacity) {
		*(mem + size) = n;
		size++;
		return true;
	}
	else {
		std::cout << "Stack Full!" << std::endl;
		return false;
	}
}

bool IntStack::pop(int& n) {
	if (size <= 0) {
		std::cout << "Stack Empty!!" << std::endl;
		return false;
	}
	else {
		size--;
		n = *(mem + size);
		return true;
	}
}

void chap9_Ex6() {
	IntStack intStack;

	std::cout << "10���� ������ �Է��ϼ���: ";
	for (int i = 0; i < 10; i++) {
		int input; std::cin >> input;
		intStack.push(input);
	}

	int n;
	while (true) {
		if (!intStack.pop(n)) break;
		std::cout << n << " ";
	}
}