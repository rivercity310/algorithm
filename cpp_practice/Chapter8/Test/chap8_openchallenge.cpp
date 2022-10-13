#include <iostream>
#include <string>
using std::string;

class Product {
	int id, price;
	string intro, manufacturer;
protected:
	Product(int id, int price, string intro, string manufacturer) {
		this->id = id;
		this->price = price;
		this->intro = intro;
		this->manufacturer = manufacturer;
		std::cout << "Product ������ ����" << std::endl;
	}
	string getIntro() { return this->intro; }
	string getManu() { return this->manufacturer; }
	int getPrice() { return this->price; }
	int getID() { return this->id; }
public:
	virtual void show() = 0;
};

class Book : public Product {
	int ISBN;
	string author, title;
public:
	Book(int id, int price, string intro, string manufacturer, string author, string title, int ISBN) : Product(id, price, intro, manufacturer) {
		this->author = author;
		this->title = title;
		this->ISBN = ISBN;
		std::cout << "Book ������ ����" << std::endl;
	}
	void show() override;
};

void Book::show() {
	std::cout << "--- ��ǰID : " << getID() << "\n";
	std::cout << "��ǰ ����: " << getIntro() << "\n";
	std::cout << "������: " << getManu() << "\n";
	std::cout << "����: " << getPrice() << "\n";
	std::cout << "����: " << author << "\n";
	std::cout << "å����: " << title << "\n";
	std::cout << "ISBN: " << ISBN << std::endl;
}

class ConversationBook : public Book {
	string lang;
public:
	ConversationBook(int id, int price, string intro, string manufacturer, string author, string title, int ISBN, string lang) : Book(id, price, intro, manufacturer, author, title, ISBN) {
		this->lang = lang;
		std::cout << "ConversationBook ������ ����" << std::endl;
	}

	void show() override;
};

void ConversationBook::show() {
	Book::show();
	std::cout << "���: " << lang << std::endl;
}

class CompactDisc : public Product {
	string albumTitle, singer;
public:
	CompactDisc(int id, int price, string intro, string manufacturer, string albumTitle, string singer) : Product(id, price, intro, manufacturer) {
		this->albumTitle = albumTitle;
		this->singer = singer;
		std::cout << "CompactDisc ������ ����" << std::endl;
	}
	void show() override;
};

void CompactDisc::show() {
	std::cout << "--- ��ǰID : " << getID() << "\n";
	std::cout << "��ǰ ����: " << getIntro() << "\n";
	std::cout << "������: " << getManu() << "\n";
	std::cout << "����: " << getPrice() << "\n";
	std::cout << "�ٹ� ����: " << albumTitle << "\n";
	std::cout << "����: " << singer << std::endl;
}

void chap8_openchallenge() {
	string intro, manufacturer, author, title, lang, albumTitle, singer;
	int price, ISBN;
	int id = 0;

	Product* products[100];

	std::cout << "**** ��ǰ ���� ���α׷��� �۵��մϴ� ****" << std::endl;
	while (true) {
		std::cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) : ";
		int select; std::cin >> select;

		switch (select) {
		case 1:
		{
			std::cout << "��ǰ ���� >> å(1), ���� CD(2), ȸȭå(3): ";
			int kinds; std::cin >> kinds;
			std::cin.ignore();

			switch (kinds) {
			case 1:
			{
				// (int id, int price, string intro, string manufacturer, string author, string title, int ISBN)
				std::cout << "��ǰ ����: "; std::getline(std::cin, intro);
				std::cout << "������: "; std::getline(std::cin, manufacturer);
				std::cout << "����: "; std::cin >> price; std::cin.ignore();
				std::cout << "å ����: "; std::getline(std::cin, title); 
				std::cout << "����: "; std::getline(std::cin, author);
				std::cout << "ISBN: "; std::cin >> ISBN;

				Book* book = new Book(id, price, intro, manufacturer, author, title, ISBN);
				products[id++] = book;
				break;
			}
			case 2:
			{
				//(int id, int price, string intro, string manufacturer, string albumTitle, string singer)
				std::cout << "��ǰ ����: "; std::getline(std::cin, intro);
				std::cout << "������: "; std::getline(std::cin, manufacturer);
				std::cout << "����: "; std::cin >> price; std::cin.ignore();
				std::cout << "�ٹ� ����: "; std::getline(std::cin, albumTitle);
				std::cout << "����: "; std::getline(std::cin, singer);

				CompactDisc* CD = new CompactDisc(id, price, intro, manufacturer, albumTitle, singer);
				products[id++] = CD;
				break;
			}
			case 3:
			{
				//int id, int price, string intro, string manufacturer, string author, string title, int ISBN, string lang)
				std::cout << "��ǰ ����: "; std::getline(std::cin, intro);
				std::cout << "������: "; std::getline(std::cin, manufacturer);
				std::cout << "����: "; std::cin >> price; std::cin.ignore();
				std::cout << "å ����: "; std::getline(std::cin, title);
				std::cout << "����: "; std::getline(std::cin, author);
				std::cout << "ISBN: "; std::cin >> ISBN; std::cin.ignore();
				std::cout << "���: "; std::getline(std::cin, lang);

				ConversationBook* CB = new ConversationBook(id, price, intro, manufacturer, author, title, ISBN, lang);
				products[id++] = CB;
				break;
			}
			default:
				std::cout << "�߸��� �����Դϴ�.." << std::endl;
				break;
			}


			break;
		}
		case 2:
			for (int i = 0; i < id; i++) products[i]->show();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << "���α׷��� �����մϴ�... " << std::endl;
			return;
		default:
			std::cout << "�߸��� �����Դϴ�..." << std::endl;
			break;
		}
	}
}