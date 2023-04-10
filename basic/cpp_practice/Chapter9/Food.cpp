#include <iostream>
#include <ctime>

#include "Food.h"


Food::Food(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}

void Food::move() {
	srand(time(NULL));
	int rInt = rand() % 5;

	// 60%�� Ȯ��
	if (rInt < 3) {
		int randomMove = rand() % 4;

		// 0���� ���ʴ�� ���� �Ʒ� �� ���������� ��ĭ�� �̵��Ѵ�.
		switch (randomMove) {
		case 0:
		{
			if (this->y == 0) this->y = 0;
			else this->y--;
			break;
		}
		case 1:
		{
			if (this->x == 9) this->x = 9;
			else this->x++;
			break;
		}
		case 2:
		{
			if (this->x == 0) this->x = 0;
			else this->x--;
			break;
		}
		case 3:
		{
			if (this->y == 19) this->y = 19;
			else this->y++;
			break;
		}
		}
	}
}

char Food::getShape() {
	return '@';
}