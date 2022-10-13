#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

namespace stl_hash {
	// �����̳��� ��� ���� ���
	void print(const unordered_set<int>& container) {
		for (const auto& element : container)
			cout << element << " ";
		cout << endl;
	}

	void print(const unordered_map<int, int>& container) {
		for (const auto& element : container)
			cout << "(" << element.first << ", " << element.second << ") ";
		cout << endl;
	}

	void find(const unordered_set<int>& container, const int element) {
		if (container.find(element) == container.end())
			cout << element << " �˻� ����!" << endl;
		else
			cout << element << " �˻� ����!" << endl;
	}

	void find(const unordered_map<int, int>& container, const int element) {
		unordered_map<int, int>::const_iterator it = container.find(element);
		if (it == container.end())
			cout << element << " �˻� ����!" << endl;
		else
			cout << element << " �˻� ����, �� = " << it->second << endl;
	}
}

void stl_hs() {
	cout << "*** std::unordered_set ���� ***" << endl;
	unordered_set<int> set = { 1, 2, 3, 4, 5 };

	cout << "set�� �ʱⰪ: ";
	stl_hash::print(set);

	set.insert(2);
	set.insert(100);
	cout << "2, 100 ����: ";
	stl_hash::print(set);

	cout << "100 ����, 100, 2 ã��: " << endl;
	set.erase(100);
	stl_hash::find(set, 2);
	stl_hash::find(set, 100);
	stl_hash::print(set);

	cout << "\n\n" << endl;

	cout << "*** std::unordered_map ���� ***" << endl;
	unordered_map<int, int> sqr_map;

	sqr_map.insert({ 2, 4 });
	sqr_map[3] = 9;
	cout << "2, 3�� ���� ����: ";
	stl_hash::print(sqr_map);

	sqr_map.erase(3);
	cout << "Ű 3 ����, 3 ã��" << endl;
	stl_hash::find(sqr_map, 3);
	stl_hash::print(sqr_map);
}