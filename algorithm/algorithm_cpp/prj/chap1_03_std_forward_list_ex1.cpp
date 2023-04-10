#include <iostream>
#include <forward_list>
#include <string>

/*
[ ���� ����Ʈ���� remove_if() �Լ��� �̿��� ���Ǻ� ���� ���� ]

���� �Ⱓ�� �Ϻ� �ùε��� ������ �̿��Ͽ� ���ű��� ���� ����� ��������

*/

struct citizen {
	std::string name;
	int age;
};

std::ostream& operator<<(std::ostream& os, const citizen& c) {
	return (os << "[" << c.name << ", " << c.age << "]");
}

void std_forward_list_ex1() {
	std::forward_list<citizen> citizens = {
		{"Kim", 22}, {"Lee", 25}, {"Park", 18}, {"Jin", 16}
	};

	std::cout << "��ü �ùε�: ";
	for (const auto& c : citizens) std::cout << c << " ";
	std::cout << std::endl;



	citizens.remove_if([](const citizen& c) {
		return (c.age < 19);
		});

	std::cout << "��ǥ���� �ִ� �ùε�: ";
	for (const auto& c : citizens) std::cout << c << " ";
	std::cout << std::endl;
}