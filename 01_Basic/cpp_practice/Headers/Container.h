#pragma once

class Container {
private:
	int size;        // ���� ���差, �ִ� ���差�� 10
public:
	Container();
	void fill();     // 10���� ä���
	void consume(int n);  // 1��ŭ �Ҹ�
	int getSize();   // ���� ũ�� ����
};