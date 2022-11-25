#include <iostream>
#include <array>

// ���� ���縦 ���� �ʱ� ���� ���������� & ���
template <size_t N> 
void prt_array(const std::array<int, N>& arr) {
	// ���� ��� for��
	// ���������� iterator ��� => begin() ��ġ���� ++�ؼ� end() ��ġ�� �����ϸ� ����
	for (auto element : arr)
		std::cout << element << " ";
	std::cout << std::endl;

	// �� �ڵ�� ������ �����ϴ�
	for (auto it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void chap1_array() {
	// 01. ũ�Ⱑ 10�� int Ÿ�� �迭 ����
	std::array<int, 10> arr1;       
	arr1[0] = 1;
	std::cout << "arr1�� ù��° ����: " << arr1[0] << std::endl;


	// 02. �ʱ�ȭ
	std::array<int, 4> arr2 = { 1, 2, 3, 4 };
	std::cout << "arr2�� ��� ����: ";
	for (int i = 0; i < arr2.size(); i++) std::cout << arr2[i] << " ";
	for (auto element : arr2) std::cout << element << " ";
	for (auto it = arr2.begin(); it != arr2.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;


	// 03. ���� ó�� �ڵ�
	// at() �Լ��� ���ڷ� ���޵� index ���� ��ȿ���� ������ std::out_of_range ���ܸ� �߻���Ų��.
	// arr1.at(50)
	std::array<int, 4> arr3 = { 1, 2, 3, 4 };
	try {
		std::cout << arr3.at(3) << std::endl;
		std::cout << arr3.at(4) << std::endl;
	}
	catch (const std::out_of_range& ex) {
		std::cerr << ex.what() << std::endl;       // std::cerr : ���� ��� ���� -> C�� stdout�� stderr�� �ֵ���
	}


	// 04. ������� ��� -> �پ��� ũ���� int�� �迭�� ����ϱ� ���� template���� �Լ� �ۼ�
	std::array<int, 6> arr4 = { 5, 6, 7, 8, 9, 0 };
	prt_array(arr4);



	// 05. ������ �޼ҵ�
	// front() : �迭 ù ���ҿ� ���� ���� ��ȯ
	// back() : �迭 ������ ���ҿ� ���� ���� ��ȯ
	// data() : �迭 ��ü ���ο��� ���� ������ �޸� ���۸� ����Ű�� ������ ��ȯ

	// 5 0 6 ���
	std::cout << arr4.front() << "\n";
	std::cout << arr4.back() << "\n";
	std::cout << *(arr4.data() + 1) << std::endl;
}