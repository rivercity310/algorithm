#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

// �� ���� �׽�Ʈ �Լ� �ۼ�
void transform_test(vector<int>& v) {
	vector<int> Tr;

	cout << "[�� �׽�Ʈ]" << endl;
	cout << "�Է� �迭: ";
	for (auto i : v) cout << i << " ";
	cout << endl;

	// std::transform() �Լ� ��� : ������ �ٲ��� �ʰ� ������ ���͸� ����� ��ȯ
	std::transform(v.begin(), v.end(), std::back_inserter(Tr), [](int x) {
		return std::pow(x, 2);
	});

	cout << "std::transform(), Tr: ";
	for (auto i : Tr) cout << i << " ";
	cout << endl;

	// std::for_each() �Լ� ��� : ���� ���� ��ü�� ����
	std::for_each(v.begin(), v.end(), [](int& x) {
		x = pow(x, 2);
	});

	cout << "std::for_each(), v: ";
	for (auto i : v) cout << i << " ";
	cout << endl;
}

void edr_test(vector<int> v) {
	cout << "\n[���ེ �׽�Ʈ]" << endl;
	cout << "�Է� �迭: ";
	for (auto i : v) cout << i << " ";
	cout << endl;

	// std::accumulate() �Լ� ���
	int ans = std::accumulate(v.begin(), v.end(), 0, [](int acc, int x) {
		return acc + x;
		});
	cout << "std::accumulate(), ans: " << ans << endl;

}

void map_reduce_test() {
	vector<int> v = { 1, 10, 4, 7, 3, 5, 6, 9, 8, 2 };

	transform_test(v);
	//reduce_test(v);
}