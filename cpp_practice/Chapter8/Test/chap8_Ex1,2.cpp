#include <iostream>
using std::string;

class chap8_Circle {
	int radius;
public:
	chap8_Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return this->radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public chap8_Circle {
	string name;
public:
	NamedCircle(int radius = 1, string name = "anonymous") : chap8_Circle(radius) {
		this->name = name;
	}
	string getName() {
		return this->name;
	}
	void show() {
		std::cout << "�������� " << this->getRadius() << "�� " << name << std::endl;
	}
	static string biggest(NamedCircle circles[], int size, double& area);
};

string NamedCircle::biggest(NamedCircle circles[], int size, double& area) {
	string name;
	for (int i = 0; i < size; i++) 
		if (area < circles[i].getArea()) {
			area = circles[i].getArea();
			name = circles[i].getName();
		}

	return name;
}

void chap8_Ex1() {
	NamedCircle waffle(3, "Waffle");
	waffle.show();
}

void chap8_Ex2() {
	NamedCircle pizza[5];

	std::cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << ": ";
		int radius;
		string name;
		std::cin >> radius >> name;
		pizza[i] = NamedCircle(radius, name);
	}

	double area;
	string name = NamedCircle::biggest(pizza, 5, area);

	std::cout << "���� ������ ū ���ڴ� " << name << std::endl;
	std::cout << "������: " << area << std::endl;
}