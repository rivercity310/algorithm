#include <iostream>
#include <map>

using std::string;
using std::map;

class Program_UI {
private:
	map<string, int> m;
	void insert();
	void select();
	void finish();
public:
	void run();
};

void Program_UI::insert() {
	std::cout << "�̸��� ���� >> ";
	string name;
	int score;
	std::cin >> name >> score;
	m.insert(make_pair(name, score));
}

void Program_UI::select() {
	std::cout << "�̸�: ";
	string name; std::cin >> name;

	if (m.find(name) == m.end()) {
		std::cout << "����" << std::endl;
	}
	else {
		std::cout << m[name] << std::endl;
	}
}

void Program_UI::finish() {
	std::cout << "���α׷��� �����մϴ�..." << std::endl;
}

void Program_UI::run() {
	std::cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****" << std::endl;

	
	while (true) {
		std::cout << "�Է�(1), ��ȸ(2), ����(3)  :";
		int select; std::cin >> select;

		switch (select) {
		case 1:
			Program_UI::insert();
			break;
		case 2:
			Program_UI::select();
			break;
		case 3:
			Program_UI::finish();
			exit(0);
		default:
			std::cout << "�߸��� �����Դϴ�." << std::endl;
			std::cout << "�ٽ� �������ּ���." << std::endl;
			break;
		}
	}
}


void chap10_Ex13() {
	Program_UI* prog = new Program_UI();
	prog->run();

	delete prog;
}