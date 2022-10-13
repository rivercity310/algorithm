#include <iostream>
#include <string>
using std::string;

class Board {
private:
	static string timeline;
	static int idx;
public:
	static void add(string feed);
	static void print();
};

string Board::timeline = "";
int Board::idx = 0;

void Board::add(string feed) {
	string str = (idx++) + ": " + feed + "\n";
	timeline.append(str);
}

void Board::print() {
	std::cout << "************ �Խ����Դϴ� *************" << std::endl;
	std::cout << timeline << std::endl;
}

void chap6_Ex9() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿����ּ���");
	Board::print();
	
	Board::add("Ȳ�¼� �л��� ������ȸ �Ի��Ͽ����ϴ�.");
	Board::print();
}