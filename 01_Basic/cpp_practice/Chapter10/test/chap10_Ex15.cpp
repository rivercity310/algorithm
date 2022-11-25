#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class Program15_UI {
private:
	vector<Circle*> v;

	void makeCircle();
	void deleteCircle();
	void showAllCircles();
public:
	void run() {
		std::cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�." << std::endl;

		while (true) {
			std::cout << "����(1), ����(2), ��κ���(3), ����(4) >> ";
			int select; std::cin >> select;

			switch (select) {
			case 1:
				Program15_UI::makeCircle();
				break;
			case 2:
				Program15_UI::deleteCircle();
				break;
			case 3:
				Program15_UI::showAllCircles();
				break;
			case 4:
				std::cout << "���α׷��� �����մϴ�....." << std::endl;
				exit(0);
			}
		}
	}
};

void Program15_UI::makeCircle() {
	std::cout << "�����ϰ��� �ϴ� ���� �������� �̸� >> ";
	int r;
	string name;
	std::cin >> r >> name;
	
	v.push_back(new Circle(r, name));
}

void Program15_UI::deleteCircle() {
	std::cout << "�����ϰ��� �ϴ� ���� �̸� >> ";
	string name; std::cin >> name;

	vector<Circle*>::iterator it = v.begin();
	while (it != v.end()) {
		Circle* p = *it;
		if (p->getName() == name) {
			it = v.erase(it);
			delete p;
		}
		else it++;
	}
}

void Program15_UI::showAllCircles() {
	for (auto it = v.begin(); it != v.end(); it++) {
		std::cout << (*it)->getName() << " " << (*it)->getArea() << std::endl;
	}
}

void chap10_Ex15() {
	auto prog = new Program15_UI();
	prog->run();

	delete prog;
}