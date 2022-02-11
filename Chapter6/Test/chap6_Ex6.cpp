#include <iostream>

class ArrayUtil6_2 {
public:
	// s1�� s2�� ������ ���ο� �迭�� ���� �����ϰ� ������ ����
	static int* concat(int* s1, int* s2, int size = 5);

	// s1���� s2�� �ִ� ���ڸ� ��� ���� (������, s1 - s2) �� ���ο� �迭�� ���� �����Ͽ� ����
	// retSize�� �����ϴ� �迭�� ũ��, retSize�� 0�� ��� NULL ����
	static int* remove(int* s1, int* s2, int size, int& retSize);
};

int* ArrayUtil6_2::concat(int* s1, int* s2, int size) {
	int* concated = new int[size * 2];

	for (int i = 0; i < size; i++) {
		*(concated + i) = *(s1 + i);
		*(concated + size + i) = *(s2 + i);
	}

	return concated;
}

int* ArrayUtil6_2::remove(int* s1, int* s2, int size, int& retSize) {
	int* removed = new int[size];

	int rIdx = 0;
	for (int i = 0; i < size; i++) {
		bool check = false;
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) {
				check = true;
				break;
			}
		}

		if (!check) {
			*(removed + rIdx) = s1[i];
			rIdx++;
		}
	}

	retSize = rIdx;
	if (retSize == 0) return NULL;
	else return removed;
}


void chap6_Ex6() {
	std::cout << "(x) ���� 5�� �Է�: ";
	int x[5];
	for (int i = 0; i < 5; i++) {
		int input;
		std::cin >> input;
		x[i] = input;
	}

	std::cout << "(y) ���� 5�� �Է�: ";
	int y[5];
	for (int i = 0; i < 5; i++) {
		int input;
		std::cin >> input;
		y[i] = input;
	}

	std::cout << std::endl << "��ģ ���� �迭�� ����Ѵ�..." << std::endl;
	int* concated = ArrayUtil6_2::concat(x, y);
	for (int i = 0; i < 10; i++) std::cout << *(concated + i) << " ";
	std::cout << std::endl;

	std::cout << std::endl << "�迭 x���� y�� �� ����� ����Ѵ�...." << std::endl;
	int retSize;
	int* removed = ArrayUtil6_2::remove(x, y, 5, retSize);
	for (int i = 0; i < retSize; i++) std::cout << *(removed + i) << " ";
	std::cout << std::endl << std::endl << "���� �� �迭�� ���̴� " << retSize << std::endl;

	delete[] concated;
	delete[] removed;
}