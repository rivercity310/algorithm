#include <iostream>
#include <vector>
#include <ctime>

using std::vector;
using std::string;

class Word {
	string kor;
	string eng;
public:
	Word(string kor, string eng) { this->kor = kor; this->eng = eng; }
	string getKor() { return this->kor; }
	string getEng() { return this->eng; }
};

class Game {
	vector<Word> v;
	int r[4];
public:
	void initVector();
	void run();
	void insert();
	void test();
	void finish();
	void shuffle();
};

void Game::shuffle() {

	srand((unsigned)time(NULL));
	while (true) {
		for (int i = 0; i < 4; i++)
			r[i] = rand() % v.size();

		bool check = false;
		for (int i = 0; i < 3; i++)
			for (int j = 3; j > i; j--)
				if (r[i] == r[j]) check = true;
		

		for (int i = 0; i < 4; i++) std::cout << r[i] << " ";
		std::cout << std::endl;
		if (!check) break;
	}
}

void Game::initVector() {
	v.push_back(Word("��", "Circle"));
	v.push_back(Word("����", "Birthday"));
	v.push_back(Word("�غ�", "Prepare"));
	v.push_back(Word("���", "Flag"));
	v.push_back(Word("�ڳ���", "Elephant"));
}

void Game::insert() {
	std::cout << "���� �ܾ exit�� �Է��ϸ� �Է��� �����ϴ�." << std::endl;
	
	while (true) {
		string eng, kor;
		std::cout << "����: "; std::cin >> eng;
		if (eng == "exit") Game::run();
		std::cout << "�ѱ�: "; std::cin >> kor;

		v.push_back(Word(kor, eng));
	}
}

void Game::test() {

	while (true) {
		srand((unsigned)time(NULL));

		Game::shuffle();
		int rIdx = rand() % 4;
		std::cout << v[r[rIdx]].getEng() << "?" << std::endl;
		for (int i = 0; i < 4; i++) std::cout << "(" << i + 1 << ")" << v[r[i]].getKor() << "   ";
		std::cout << " : ";
		
		int input; std::cin >> input;
		if (input == -1) Game::run();

		if (v[r[input - 1]].getEng() == v[r[rIdx]].getEng()) std::cout << "Excellent!" << std::endl;
		else std::cout << "No!" << std::endl;
	}
	
}

void Game::finish() {
	std::cout << "���α׷��� �����մϴ�..." << std::endl;
}

void Game::run() {
	Game::initVector();
	std::cout << "***** ���� ���� �׽�Ʈ�� �����մϴ� *****" << std::endl;
	std::cout << "���� ����(1), ���� �׽�Ʈ(2), ���α׷� ����(others) : ";
	int input; std::cin >> input;

	switch (input) {
	case 1: Game::insert(); break;
	case 2: Game::test(); break;
	default: Game::finish(); return;
	}
}


void chap10_Ex12() {
	Game* game = new Game();
	game->run();

	delete game;
}