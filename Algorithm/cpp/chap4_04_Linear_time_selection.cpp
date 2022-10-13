#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

// �� �ݺ��� ������ �߰� ���� ã�� �Լ�
template <typename T>
typename vector<T>::iterator find_median(
	typename vector<T>::iterator begin, 
	typename vector<T>::iterator last
) 
{
	// ����
	sort(begin, last);
	
	// ��� ���� �ݺ��� ��ȯ
	return begin + (distance(begin, last) / 2);
}

// �ǹ� ��ġ �ݺ��ڸ� ���ڷ� �޴� ������ ���� �Լ�
template <typename T>
auto partition_using_given_pivot(
	typename vector<T>::iterator begin, 
	typename vector<T>::iterator end, 
	typename vector<T>::iterator pivot
) 
{
	typename vector<T>::iterator left_iter = begin;
	typename vector<T>::iterator right_iter = end;

	while (true) {
		while (*left_iter < *pivot && left_iter != right_iter) left_iter++;
		while (*right_iter >= *pivot && left_iter != right_iter) right_iter--;

		if (left_iter == right_iter) break;
		else
			iter_swap(left_iter, right_iter);
	}

	if (*pivot > *right_iter) iter_swap(pivot, right_iter);
	
	return right_iter;
}

// ���� �ð� �˻� �˰���
template <typename T>
typename vector<T>::iterator linear_time_select(
	typename vector<T>::iterator begin,
	typename vector<T>::iterator last,
	size_t i
)
{
	auto size = std::distance(begin, last);

	if (size > 0 && i < size) {
		// �ټ����� ���ҷ� �����Ͽ� ���� �κ� ���� Vi�� ���� ���
		int num_Vi = (size + 4) / 5;
		size_t j = 0;

		// ������ Vi���� �߾Ӱ��� ã�� ���� M�� ����
		vector<T> M;
		for (; j < size / 5; j++) {
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + 5;

			M.push_back(*find_median<T>(b, l));
		}

		if (j * 5 < size) {
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + (size % 5);

			M.push_back(*find_median<T>(b, l));
		}

		// Vi�� �߾Ӱ����� ������ ���� M���� �ٽ� �߾Ӱ� q�� ã��
		auto med = (M.size() == 1) ? M.begin() : linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);

		// ���� ������ �����ϰ� �ǹ� q�� ��ġ k�� ã��
		auto partition_iter = partition_using_given_pivot<T>(begin, last, med);
		auto k = std::distance(begin, partition_iter) + 1;

		if (i == k) return partition_iter;
		else if (i < k) return linear_time_select<T>(begin, partition_iter - 1, i);
		else if (i > k) return linear_time_select<T>(partition_iter + 1, last, i - k);
	}
	else
		return begin;
}

// �׽�Ʈ�� ���� ���� �Լ�
template <typename T>
vector<T> mg(vector<T>& arr1, vector<T>& arr2) {
	vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end()) {
		if (*iter1 < *iter2) {
			merged.emplace_back(*iter1);
			iter1++;
		}
		else {
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	if (iter1 != arr1.end()) {
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	else {
		for (; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}

	return merged;
}

template <typename T>
vector<T> mg_sort(vector<T> arr) {
	if (arr.size() > 1) {
		auto mid = size_t(arr.size() / 2);
		auto left_half = mg_sort(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = mg_sort(vector<T>(arr.begin() + mid, arr.end()));

		return mg<T>(left_half, right_half);
	}

	return arr;
}

void pv(vector<int> v) {
	for (auto i : v) cout << i << " ";
	cout << endl;
}

void run_linear_select_test() {
	vector<int> s1;

	random_device rd;
	mt19937 rand(rd());
	uniform_int_distribution<mt19937::result_type> uniform_dist(1, 1000);

	for (int i = 0; i < 10; i++) s1.push_back(uniform_dist(rand));
	
	cout << "�Է� ����" << endl;
	pv(s1);
	cout << endl;

	cout << "���ĵ� ����" << endl;
	pv(mg_sort(s1));
	cout << endl;

	while (true) {
		size_t s;
		cout << "���°? ";
		cin >> s;

		if (s <= 0) break;
		cout << *linear_time_select<int>(s1.begin(), s1.end() - 1, s) << endl;
	}
}