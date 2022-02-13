#include <iostream>
#include <string>
using std::string;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0);
	Book(const Book& book);
	void show();
	string getTitle() { return title; }
	Book& operator+=(int increase);
	Book& operator-=(int decrease);
	bool operator==(int price);
	bool operator==(string title);
	bool operator==(Book& book);
	bool operator>(string title);
	bool operator!();
};

Book::Book(string title, int price, int pages) {
	this->title = title;
	this->price = price;
	this->pages = pages;
}

Book::Book(const Book& book) {
	std::cout << "���� ������ ȣ��" << std::endl;
	this->title = book.title;
	this->price = book.price;
	this->pages = book.pages;
}

void Book::show() {
	std::cout << title << " " << price << "�� " << pages << "������" << std::endl;
}

Book& Book::operator+=(int increase) {
	this->price += increase;
	return *this;
}

Book& Book::operator-=(int decrease) {
	this->price -= decrease;
	return *this;
}

bool Book::operator==(int price) {
	if (this->price == price) return true;
	else return false;
}

bool Book::operator==(string title) {
	if (this->title == title) return true;
	else return false;
}

bool Book::operator==(Book& book) {
	if (this->title == book.title && this->price == book.price && this->pages == book.pages) return true;
	else return false;
}

bool Book::operator!() {
	if (this->price == 0) return true;
	else return false;
}

bool Book::operator>(string title) {
	bool res = this->title > title;
	if (res) return true;
	else return false;
}

void chap7_Ex1() {
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;    // å a�� ���� 500�� ����
	b -= 500;    // å b�� ���� 500�� ����
	a.show();
	b.show();
}

void chap7_Ex2() {
	// ���� ������ ������Ű�� ������ �Լ� �ۼ�
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	Book c = a;
	
	if (a == 30000) std::cout << "���� 30000��" << std::endl;   // price ��
	if (a == "��ǰ C++") std::cout << "��ǰ C++ �Դϴ�." << std::endl;   // title ��
	if (a == c) std::cout << "�� å�� �����ϴ�." << std::endl;   // ��� ��
}

void chap7_Ex3() {
	// ������ 0���̸� true�� �����ϴ� ! ������ �ۼ�
	
	Book book("�������", 0, 50);  
	if (!book) std::cout << "��¥��!" << std::endl;
}

void chap7_Ex4() {
	// å�� ������ ���� ������ ���ϴ� < ������ �ۼ�
	Book a("û��", 20000, 300);
	string b;
	getline(std::cin, b);
	if (a > b)
		std::cout << a.getTitle() << "�� " << b << "���� �ڿ� �ֱ���!" << std::endl;
	else
		std::cout << a.getTitle() << "�� " << b << "���� �տ� �ֱ���!" << std::endl;

	if ("a" > "b") std::cout << true << std::endl;
}