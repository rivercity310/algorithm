#include <iostream>
#include <list>
#include <vector>

using namespace std;

void chap1_std_list() {
	list<int> list1 = { 1, 2, 3, 4, 5 };
	list1.push_back(6);
	list1.insert(next(list1.begin()), 0);     // ����Ʈ �� ó�� ���� ���� ��ġ�� 0 ����
	list1.insert(list1.end(), 7);             // �� �ڿ� 7 ����

	list1.pop_back();
	cout << "����/���� �� ����Ʈ: ";
	for (auto i : list1) cout << i << " ";
	cout << endl;
}

void chap1_std_list2() {
	// => v_it4 �ݺ��ڴ� ��ȿȭ�ȴ�.
	vector<int> vec = { 1, 2, 3, 4, 5 };
	auto v_it4 = vec.begin() + 4;
	vec.insert(vec.begin() + 2, 0);

	
	// l_it4 �ݺ��ڴ� ������ ��ȿ�ϴ�.
	list<int> lst = { 1, 2, 3, 4, 5 };
	auto l_it4 = next(lst.begin(), 4);
	lst.insert(next(lst.begin(), 2), 0);

	cout << *l_it4 << endl;
}