#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

class Player {
	std::string name;
public:
	Player() : Player("ȫ�浿") {}
	Player(std::string name) { this->setName(name); }
	std::string getName() { return this->name; }
	void setName(std::string name) { this->name = name; }
};

class UpAndDownGame {
	static int randomInt;
public:
	static int gameInit(int r);
	static void run(Player* players, int size);
};

int UpAndDownGame::randomInt = UpAndDownGame::gameInit(100);

int UpAndDownGame::gameInit(int r) {
	srand(time(NULL));
	return rand() % r;
}

void UpAndDownGame::run(Player* players, int size) {
	UpAndDownGame::randomInt = UpAndDownGame::gameInit(100);
	std::cout << "Up & Down ������ �����մϴ�." << std::endl;
	std::cout << "[����]: " << randomInt << std::endl;
	
	int i = 0;
	int left = 0, right = 99;
	while (true) {
		if (i >= size) i = 0;
		std::string pName = (players + i)->getName();
		std::cout << "���� " << left << "�� " << right << "���̿� �ֽ��ϴ�." << std::endl;
		
		int userInput;
		std::cout << pName << ": ";
		std::cin >> userInput;

		if (left < right && userInput > randomInt && userInput < right) right = userInput;
		if (left < right && userInput < randomInt && userInput > left) left = userInput;
		
		if (userInput == randomInt) {
			std::cout << pName << "���� �¸��Ͽ����ϴ�." << std::endl;
			
			std::cout << "�ٽ��ϱ�(1), ����(0): ";
			int retry;
			std::cin >> retry;

			if (retry == 1) run(players, size);
			return;
		}

		i++;
	}
}

void chap6_challenge() {
	std::cout << "���� �ο��� �Է����ּ���: ";
	int size;
	std::cin >> size;
	std::cin.ignore();

	Player* players = new Player[size];
	for (int i = 0; i < size; i++) {
		std::cout << "�÷��̾� " << i + 1 << " �̸�: ";
		std::string name;
		std::getline(std::cin, name, '\n');
		(players + i)->setName(name);
	}

	std::cout << "�÷��̾� ����� �Ϸ�Ǿ����ϴ�." << std::endl;

	UpAndDownGame::run(players, size);

	delete[] players;
} 