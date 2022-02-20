#include <iostream>

class BaseArray {
private:
	int capacity;    // �迭�� ũ��
	int* mem;        // ���� �迭�� ����� ���� �޸��� ������
protected:
	BaseArray(int capacity = 100) {         // �����ڰ� protected��
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int idx, int val) { mem[idx] = val; }
	int get(int idx) { return mem[idx]; }
	int getCapacity() { return capacity; }
};

// BaseArray�� ��ӹ޾� ťó�� �۵��ϴ� MyQueue Ŭ���� �ۼ�
class MyQueue : public BaseArray {
private:
	int len, ptr;
public:
	MyQueue(int capacity) : BaseArray(capacity) { this->len = this->ptr = 0; }
	int capacity() { return getCapacity(); }
	int length() { return this->len; }
	void enqueue(int n);
	int dequeue();
};

void MyQueue::enqueue(int n) {
	if (len < getCapacity()) {
		put(len, n);
		len++;
	}
	else std::cout << "�뷮�� ������ ���� �Ұ�!" << std::endl;

	return;
}

int MyQueue::dequeue() {
	int data = get(ptr++);
	len--;

	return data;
}


class MyStack : public BaseArray {
	int len;
public:
	MyStack(int cap) : BaseArray(cap) { this->len = 0; }
	void push(int val);
	int pop();
	int capacity() { return getCapacity(); }
	int length() { return this->len; }
};

void MyStack::push(int val) {
	put(len++, val);
}

int MyStack::pop() {
	--len;
	int data = get(len);

	return data;
}

void chap8_Ex5() {
	MyQueue mq(100);
	int n;
	std::cout << "ť�� ������ 10���� ����: ";
	for (int i = 0; i < 10; i++) {
		std::cin >> n;
		mq.enqueue(n);
	}

	std::cout << "ť �뷮: " << mq.capacity() << ", ť ũ��: " << mq.length() << std::endl;
	std::cout << "ť�� ���Ҹ� ������� �����ϸ� ���: ";
	while (mq.length() != 0) std::cout << mq.dequeue() << " ";
	std::cout << std::endl << "ť�� ���� ũ��: " << mq.length() << std::endl;
}


void chap8_Ex6() {
	MyStack mStack(100);
	int n;
	std::cout << "���ÿ� ������ 5���� ����: ";
	for (int i = 0; i < 5; i++) {
		std::cin >> n;
		mStack.push(n);
	}

	std::cout << "���� �뷮: " << mStack.capacity() << ", ����ũ��: " << mStack.length() << std::endl;
	std::cout << "������ ��� ���� �� ";
	while (mStack.length() != 0) std::cout << mStack.pop() << " ";
	std::cout << std::endl << "������ ���� ũ��: " << mStack.length() << std::endl;
}

