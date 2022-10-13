#include <iostream>
#include <map>
#include <string>

using std::string;

void chap10_map() {
	std::map<string, string> dic;

	dic.insert(std::make_pair("love", "���"));
	dic.insert(std::make_pair("apple", "���"));
	dic["cherry"] = "ü��";

	std::cout << "����� �ܾ� ���� " << dic.size() << std::endl;
	string eng;

	while (true) {
		std::cout << "ã�� ���� �ܾ� >> ";
		std::getline(std::cin, eng);
		if (eng == "exit") break;

		if (dic.find(eng) == dic.end())
			std::cout << "����" << std::endl;
		else
			std::cout << dic[eng] << std::endl;
	}
}