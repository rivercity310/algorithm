#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
using namespace std;

/*
// ���� �ΰ��� ������ �ް�, �� ���͸� ������������ ������ �ϳ��� ���ο� ���͸� ��ȯ 
template <typename T>
vector<T> merging(vector<T>& arr1, vector<T>& arr2) {
	vector<T> merged;
	
	auto it1 = arr1.begin();
	auto it2 = arr2.begin();

	while (it1 != arr1.end() && it2 != arr2.end()) {
		if (*it1 < *it2) {
			merged.push_back(*it1);
			it1++;
		}
		else {
			merged.push_back(*it2);
			it2++;
		}
	}

	if (it1 != arr1.end()) 
		for (; it1 != arr1.end(); it1++)
			merged.push_back(*it1);
	 
	else 
		for (; it2 != arr2.end(); it2++)
			merged.push_back(*it2);
	

	return merged;
}
*/

template <typename T>
void print_template_vt(vector<T>& arr) {
	for (auto i : arr) cout << setw(10) << left << i;
	cout << endl;
}

template <class T>
vector<T> merging(vector<T>& arr1, vector<T>& arr2) {
	vector<T> merged;

	typename vector<T>::iterator it1 = arr1.begin();
	typename vector<T>::iterator it2 = arr2.begin();

	while (it1 != arr1.end() && it2 != arr2.end()) {
		if (*it1 < *it2) {
			merged.emplace_back(*it1);
			it1++;
		}
		else {
			merged.emplace_back(*it2);
			it2++;
		}
	}

	if (it1 != arr1.end())
		for (; it1 != arr1.end(); it1++)
			merged.emplace_back(*it1);
	else
		for (; it2 != arr2.end(); it2++)
			merged.emplace_back(*it2);

	return merged;
}

template <typename T>
vector<T> merge_sort(vector<T> arr) {
	if (arr.size() > 1) {
		size_t mid = floor(arr.size() / 2);
		
		vector<T> left_half = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
		vector<T> right_half = merge_sort(vector<T>(arr.begin() + mid, arr.end()));

		return merging(left_half, right_half);
	}

	return arr;
}


void merged_sort_test() {
	random_device rd;
	mt19937 rand(rd());
	uniform_int_distribution<mt19937::result_type> uniform_dist(1, 1000);

	vector<int> v1;
	for (int i = 0; i < 6; i++)
		v1.emplace_back(uniform_dist(rand));

	cout << "���� �� ����" << endl;
	print_template_vt(v1);	
	cout << "\n\n" << endl;

	vector<int> s1 = merge_sort(v1);

	cout << "���� �� ����" << endl;
	print_template_vt(s1);
}