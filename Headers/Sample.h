#pragma once
class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n;
		p = new int[n];
	}
	~Sample() {}

	void read();       // ���� �Ҵ���� ���� �迭 p�� ����ڷκ��� ������ �Է¹���
	void write();      // ���� �迭�� ȭ�鿡 ���
	int big();         // ���� �迭���� ���� ū �� ����
};
