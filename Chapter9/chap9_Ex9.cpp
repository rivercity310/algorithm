#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Printer {
protected:
	string model, manufacturer;
	int printedCount, availableCount;
public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	virtual bool print(int pages) = 0;
	virtual void show() = 0;
};

class InkjetPrinter : public Printer {
	int availableInk;
public:
	InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk)
		: Printer(model, manufacturer, availableCount) {
		this->availableInk = availableInk;
	}
	bool print(int pages) {
		if (availableInk >= pages && availableCount >= pages) {
			availableCount -= pages;
			availableInk -= pages;
			return true;
		}
		
		return false;
	}

	void show() {
		cout << "��ũ�� : " << model << ", " << manufacturer << ", ���� ���� " <<
			availableCount << "��, " << "���� ��ũ " << availableInk << endl;
	}
};

class LaserPrinter : public Printer {
	int availableToner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
		: Printer(model, manufacturer, availableCount) {
		this->availableToner = availableToner;
	}

	bool print(int pages) {
		if (availableToner >= pages && availableCount >= pages) {
			availableCount -= pages;
			availableToner--;
			return true;
		}

		return false;
	}

	void show() {
		cout << "������ : " << model << ", " << manufacturer << ", ���� ���� " <<
			availableCount << "��, " << "���� ��� " << availableToner << endl;
	}
};

void chap9_Ex9() {
	Printer* p[2];
	p[0] = new InkjetPrinter("Officejet V40", "HP", 5, 10);
	p[1] = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

	string retry;
	
	cout << "���� �۵����� 2���� �����ʹ� ������ ����." << endl;
	for (int i = 0; i < 2; i++) p[i]->show();
	while (true) {
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է� >> ";
		int pSelect, pages;
		std::cin >> pSelect >> pages;

		if (p[pSelect - 1]->print(pages)) {
			cout << "����Ʈ �Ͽ����ϴ�" << endl;
		}
		else {
			cout << "������ �����մϴ�.." << endl;
		}
		for (int i = 0; i < 2; i++) p[i]->show();

		cout << "��� ����Ʈ �Ͻðڽ��ϱ�? (y/n) >> ";
		std::cin >> retry;

		if (retry != "y") {
			cout << "���α׷��� �����մϴ�" << endl;
			return;
		}
	}
	
}