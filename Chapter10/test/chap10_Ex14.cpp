#include <iostream>
#include <map>

using std::map;
using std::string;

void chap10_Ex14() {
	std::cout << "***** ��ȣ���� ���α׷� WHO�� �����մϴ� *****" << std::endl;
	map<string, string> pas;

	while (true) {
		std::cout << "����(1), �˻�(2), ����(3) : ";
		int select; std::cin >> select;

		switch (select) {
		case 1:
		{
			std::cout << "�̸� ��ȣ >> ";
			string id, password;
			std::cin >> id >> password;

			pas.insert(make_pair(id, password));
			break;
		}
		case 2:
		{
			std::cout << "�̸�? ";
			string id; std::cin >> id;
			std::cout << "��ȣ? ";
			string password; std::cin >> password;

			if (pas.find(id) == pas.end()) std::cout << "����~" << std::endl;
			else {
				std::cout << "���~" << std::endl;
				std::cout << "ID: " << id << "PW: " << pas[id] << std::endl;
			}
			break;
		}
		case 3:
			std::cout << "���α׷��� �����մϴ�..." << std::endl;
			exit(0);
		default:
			std::cout << "�߸��� �Է��Դϴ�..." << std::endl;
			break;
		}
	}
}