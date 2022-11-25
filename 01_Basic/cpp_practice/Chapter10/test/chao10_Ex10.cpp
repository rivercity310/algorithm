#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using std::string;

class Nation {
	string nation;
	string capital;
public:
	Nation(string nation, string capital) {
		this->nation = nation;
		this->capital = capital;
	}
	string getNation() { return this->nation; }
	string getCapital() { return this->capital; }
};

class GameUI {
	std::vector<Nation> v;
public:
	void run();
	void inputInfos();
	void quiz();
	void finish();
};

void GameUI::inputInfos() {
	std::cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << std::endl;
	std::cout << v.size() + 1 << " : ";
	string nat, cap;
	std::cin >> nat >> cap;

	v.push_back(Nation(nat, cap));
}

void GameUI::quiz() {
	srand((unsigned)time(NULL));
	int r = rand() % v.size();

	std::cout << v[r].getNation() << "�� ������ ? ";
	string answer; std::cin >> answer;

	if (answer == v[r].getCapital()) std::cout << "Correct!!" << std::endl;
	else std::cout << "No!!" << std::endl;
}

void GameUI::finish() {
	std::cout << "���α׷��� �����մϴ�!" << std::endl;
}

void GameUI::run() {
	std::cout << "***** ������ ���� ���߱� ���� ����! *****" << std::endl;
	while (true) {
		std::cout << "���� �Է�(1), ����(2), ����(3) : ";
		int input; std::cin >> input;

		switch (input) {
		case 1:
			GameUI::inputInfos();
			break;
		case 2:
			GameUI::quiz();
			break;
		case 3:
			GameUI::finish();
			return;
		default:
			std::cout << "�߸��� �Է��Դϴ�.." << std::endl;
			break;
		}
	}
}

void chap10_Ex10() {
	GameUI* game = new GameUI();
	game->run();

	delete game;
}