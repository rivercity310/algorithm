#include <iostream>
#include <algorithm>
#include <vector>

void chap10_algorithm() {
	std::vector<int> v;
	
	std::cout << "5���� ������ �Է��ϼ���: ";
	for (int i = 0; i < 5; i++) {
		int n; std::cin >> n;
		v.push_back(n);
	}

	// v.begin()���� v.end() ������ ���� ������������ ����
	sort(v.begin(), v.end());

	for (auto it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}