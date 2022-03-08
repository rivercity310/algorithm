#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Book {
	int year;
	string bookName;
	string author;
public:
	Book(int year, string bookName, string author) {
		this->year = year;
		this->bookName = bookName;
		this->author = author;
	}

	string getAuthor() { return this->author; }
	int getYear() { return this->year; }

	void showInfos() {
		cout << year << "�⵵, " << bookName << ", " << author << endl;
	}
};

class BookManager {
	vector<Book> v;
public:
	void run();
	void addBook();
	void search();
	void search_name();
	void search_year();
};

void BookManager::addBook() {
	while (true) {
		int year;
		string bookName, author;
		cout << "�⵵: "; cin >> year;
		if (year == -1) {
			cout << "�� �԰�� å�� " << v.size() << "�� �Դϴ�." << endl;
			break;
		}
		cin.ignore();
		cout << "å�̸�: "; std::getline(cin, bookName);
		cout << "����: "; std::getline(cin, author);

		v.push_back(Book(year, bookName, author));
		cout << "***** �Է��� �Ϸ�Ǿ����ϴ�! *****" << endl;
		cout << endl;
	}
}

void BookManager::search() {
	while (true) {
		cout << "�˻� �����Դϴ�.." << endl;
		cout << "�̸�(1), ����(2): ";
		int input; cin >> input;
		cin.ignore();

		switch (input) {
		case 1:
			BookManager::search_name();
			break;
		case 2:
			BookManager::search_year();
			break;
		default:
			cout << "�߸��� �Է��Դϴ�..." << endl;
			break;
		}
	}
}

void BookManager::search_name() {
	cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���: ";
	string name; std::getline(cin, name);

	for (int i = 0; i < v.size(); i++)
		if (v[i].getAuthor() == name) v[i].showInfos();
}

void BookManager::search_year() {
	cout << "�˻��ϰ��� �ϴ� ������ �Է��ϼ���: ";
	int year; cin >> year;

	for (int i = 0; i < v.size(); i++)
		if (v[i].getYear() == year) v[i].showInfos();
}

void BookManager::run() {
	cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� ����..." << endl;
	BookManager::addBook();
	BookManager::search();
}

void chap10_Ex11() {
	BookManager* BM = new BookManager();
	BM->run();

	delete BM;
}