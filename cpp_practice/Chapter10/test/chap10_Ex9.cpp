#include <iostream>
#include <vector>

void chap10_Ex9() {
	std::vector<int> v;

	while (true) {
		int input; 
		std::cout << "������ �Է��ϼ��� (0�� �Է��ϸ� ����) ";
		std::cin >> input;
		if (input == 0) {
			std::cout << "���α׷��� �����մϴ�..." << std::endl;
		}
		else v.push_back(input);

		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
			std::cout << v[i] << " ";
			std::cout << std::endl;
		}
		std::cout << "��� = " << (double)sum / v.size() << std::endl;
	}
}
