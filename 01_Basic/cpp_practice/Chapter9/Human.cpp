#include <iostream>
#include "Human.h"


Human::Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) {}
void Human::move() {
	std::cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
	char userInput; std::cin >> userInput;

	switch (userInput) {
	case 'a': 
	{
		if (this->y == 0) this->y = 0;
		else this->y--;
		break;
	}
	case 's': 
	{
		if (this->x == 9) this->x = 9;
		else this->x++;
		break;
	}
	case 'd':
	{
		if (this->x == 0) this->x = 0;
		else this->x--;
		break;
	}
	case 'f': 
	{
		if (this->y == 19) this->y = 19;
		else this->y++;
		break;
	}
	default:
		std::cout << "�߸� �Է��ϼ̽��ϴ�..." << std::endl;
		break;
	}
}

char Human::getShape() {
	return 'H';
}
