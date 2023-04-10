#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Book {
	string title;    // å ����
	int price;
public:
	Book(string title, int price);
	//~Book();
	void set(string title, int price);
	void show() { cout << title << ", " << price << "�� " << endl; }
};

Book::Book(string title, int price) {
	set(title, price);
}

void Book::set(string title, int price) {
	this->title = title;
	this->price = price;
}

/* [ C ��Ʈ�� ��� ]
Book::Book(const char* title, int price) {
	this->price = price;
	int size = strlen(title) + 1;
	this->title = new char[size];
	strcpy(this->title, title);
}


[ �����Ϸ��� �����ϴ� ����Ʈ ���� ������(���� ����) ]
Book::Book(const Book& b) {
	this->title = b.title;
	this->price = b.price;
}

[ ���� ���� ������(C - ��Ʈ��) ]
Book::Book(const Book& b) {
	this->price = price;
	int size = strlen(b.title) + 1;
	this->title = new char[size];
	strcpy(this->title, b.title);
}


Book::~Book() {
	if (this->title) delete[] title;
	cout << title << " �Ҹ�!" << endl;
}

void Book::set(char* title, int price) {
	if (this->title) delete[] this->title;
	this->price = price;
	int size = strlen(title) + 1;
	this->title = new char[size];
	strcpy(this->title, title);
}
*/

void Ex11() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp;       // ���� ������ ȣ��
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}