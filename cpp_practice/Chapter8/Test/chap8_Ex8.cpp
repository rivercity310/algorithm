#include <iostream>
using std::string;

class Printer {
	string model, menufacturer;
	int printedCount, availableCount;
protected:
	Printer(string model, string menufacturer) {
		this->model = model;
		this->menufacturer = menufacturer;
		this->printedCount = 0;
	}
	string getModel() { return this->model; }
	string getMenufacturer() { return this->menufacturer; }
	int getAvailableCount() { return this->availableCount; }
	void setAvailableCount(int availableCount) { this->availableCount = availableCount; }
};

class InkjetPrinter : public Printer {
	int availableInk;
public:
	InkjetPrinter(string model, string menufacturer, int availableInk) : Printer(model, menufacturer) {
		this->availableInk = availableInk;
		setAvailableCount(10);
	}
	void printInkjet(int pages);
	void show() {
		std::cout << "��ũ��: " << getModel() << ", " << getMenufacturer() << ", ���� ���� " << getAvailableCount();
		std::cout << " ���� ��ũ " << this->availableInk << std::endl;
	};
};

void InkjetPrinter::printInkjet(int pages) {
	if (getAvailableCount() >= pages && availableInk >= pages) {
		setAvailableCount(getAvailableCount() - pages);
		availableInk -= pages;
		std::cout << "����Ʈ�Ͽ����ϴ�." << std::endl;
	}
	else {
		std::cout << "���� �Ǵ� ��ũ�� �����մϴ�." << std::endl;
	}
}

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string menufacturer, int availableToner) : Printer(model, menufacturer) {
		this->availableToner = availableToner;
		setAvailableCount(10);
	}
	void printLaser(int pages);
	void show() {
		std::cout << "��ũ��: " << getModel() << ", " << getMenufacturer() << ", ���� ���� " << getAvailableCount();
		std::cout << " ���� ��� " << this->availableToner << std::endl;
	};
};

void LaserPrinter::printLaser(int pages) {
	if (getAvailableCount() >= pages && availableToner >= pages / 2) {
		setAvailableCount(getAvailableCount() - pages);
		availableToner -= pages / 2;
		std::cout << "����Ʈ�Ͽ����ϴ�." << std::endl;
	}
	else {
		std::cout << "���� �Ǵ� ��ũ�� �����մϴ�." << std::endl;
	}
}


void chap8_Ex8() {
	InkjetPrinter InkPrinter("Officejet V40", "HP", 10);
	LaserPrinter LaserPrinter("SCX-6x45", "Samsung Electronics", 20);
	
	std::cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����." << std::endl;
	InkPrinter.show();
	LaserPrinter.show();

	while (true) {
		std::cout << "������ (1: ��ũ��, 2: ������)�� �ż� �Է�: ";
		int selected, pages;
		std::cin >> selected >> pages;

		switch (selected) {
		case 1:
			InkPrinter.printInkjet(pages);
			break;
		case 2:
			LaserPrinter.printLaser(pages);
			break;
		default:
			std::cout << "�߸��� �Է��Դϴ�" << std::endl;
			break;
		}
		InkPrinter.show();
		LaserPrinter.show();

		char retry;
		std::cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n): ";
		std::cin >> retry;
		if (retry == 'n') break;
	}
}
