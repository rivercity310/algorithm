#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
using namespace std;

template<typename T>
void prt_v(vector<T> arr) {
	for (auto i : arr) cout << i << " ";
	cout << endl;
}

template <typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
	// �� ���� �ݺ��� ����
	// �ϳ��� �ǹ�, ������ ���� �ǹ��� ������ ������ ó���� ��
	T pivot_val = *begin;
	typename vector<T>::iterator left_iter = begin + 1;
	typename vector<T>::iterator right_iter = end;

	while (true) {
		// ������ ù��° ���Һ��� �����Ͽ� �ǹ����� ū ���� ã��
		while (*left_iter <= pivot_val && distance(left_iter, right_iter) > 0)
			left_iter++;

		// ������ ������ ���Һ��� �������� �ǹ����� ���� ���� ã��
		while (*right_iter > pivot_val && distance(left_iter, right_iter) > 0)
			right_iter--;

		if (left_iter == right_iter) break;
		else iter_swap(left_iter, right_iter);
	}

	if (pivot_val > *right_iter) 
		iter_swap(begin, right_iter);
	
	cout << "\n" << endl;
	cout << "Pivot: " << pivot_val << endl;

	cout << "[ �κ� �迭 L (pivot���� �۰ų� ����) ]" << endl;
	prt_v(vector<T>(begin, right_iter));

	cout << endl;

	cout << "[ �κ� �迭 R (pivot���� ū) ]" << endl;
	prt_v(vector<T>(right_iter, end));

	return right_iter;
}

// ���� ���� (partition �Լ�)�� ��������� �����Ͽ� �� ������ ����
template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last) {
	if (distance(begin, last) >= 1) {
		// ���� �۾� ����
		typename vector<T>::iterator partition_iter = partition<T>(begin, last);

		// ���� �۾��� ���� ������ ���͸� ��������� ����
		quick_sort<T>(begin, partition_iter - 1);
		quick_sort<T>(partition_iter, last);
	}
}

void q_sort_test() {
	random_device rd;
	mt19937 rand(rd());
	uniform_int_distribution<mt19937::result_type> uniform_dist(1, 100);

	vector<int> v1;

	for (int i = 0; i < 10; i++)
		v1.emplace_back(uniform_dist(rand));

	cout << "[ ���� �� ���� ]" << endl;
	prt_v(v1);

	cout << endl;

	// end()�� ������ ���� ������ ����Ű�Ƿ� 1�� ���ش�.
	quick_sort<int>(v1.begin(), v1.end() - 1);
	
	cout << "[ ���� �� ���� ]" << endl;
	prt_v<int>(v1);
}
