#include <iostream>
#include <forward_list>

template <typename T>
void prt_forward_list(const std::forward_list<T>& f_list) {
	for (auto element : f_list) std::cout << element << " ";
	std::cout << std::endl;
}

void chap1_forward_list() {
	std::forward_list<int> fwd_list = { 1, 2, 3 };
	fwd_list.push_front(0);       // �� �տ� 0 �߰�

	auto it = fwd_list.begin();

	// ���ο� ���Ҹ� �����Ϸ��� �ٷ� �� ������ next �����͸� �����ؾ� �ϹǷ�
	fwd_list.insert_after(it, 5);  // �� �� �ٷ� �ڿ� 5 �߰�
	fwd_list.insert_after(it, 6);  // �� �� �ٷ� �ڿ� 6 �߰�


	// ���� ����
	fwd_list.pop_front();     // �� �� ���� ����
	// fwd_list.erase_after(it);  // �� �� ���� ���Ҹ� ����
	// fwd_list.erase_after(it, fwd_list.end());  // �� �� ���� �������� �� ���������� ����

	prt_forward_list(fwd_list);
}

void chap1_forward_list2() {
	std::forward_list<int> list1 = { 23, 0, 1, -3, 34, 32 };
	list1.sort();   // default: std::less<value_type>

	prt_forward_list(list1);

	list1.sort(std::greater<int>());
	prt_forward_list(list1);
}

void chap1_forward_list3() {
	std::forward_list<int> list1 = { 2, 53, 1, 0, 4, 10 };
	list1.reverse();
	prt_forward_list(list1);

	list1 = { 0, 1, 0, 1, -1, 10, 5, 5, 10, 0 };
	list1.sort(std::greater<int>());
	list1.unique();
	prt_forward_list(list1);

	// ����Ʈ���� Ư�� ���Ұ� �ٷ� �� ���Һ��� 2 �̻� ũ�� ������ ����
	list1.sort(std::less<int>());
	list1.unique([](int a, int b) {return b - a < 2; });
	prt_forward_list(list1);
}