#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

/*
[ �پ��� �ݺ��ڿ��� �̵��ϱ� ]
*/

void chap1_iterator() {
	vector<string> vec = {
		"Lewis Hamilton", "Nico Roseberg", "Sebastian Vettel",
		"Fernando Alonso"
	};

	auto it = vec.begin();
	cout << "�ֱ� �����: " << *it << "\n";

	it += 3;
	cout << "3�� �� �����: " << *it << "\n";

	advance(it, -1);
	cout << "�� �� 1�� �� �����: " << *it << endl;


	forward_list<string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	cout << "�ֱ� �����: " << *it1 << "\n";

	advance(it1, 2);
	cout << "2�� �� �����: " << *it1 << "\n";

	// forward_list�� �ݺ��ڴ� ������ �ݺ����̹Ƿ� ���� �ڵ�� ���� �߻�
	// advance(it1, -2)
}