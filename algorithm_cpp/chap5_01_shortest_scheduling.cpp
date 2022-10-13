#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

template <typename T>
auto compute_waiting_times(vector<T>& service_times) {
	vector<T> W(service_times.size());
	W[0] = 0;

	for (auto i = 1; i < service_times.size(); i++)
		W[i] = W[i - 1] + service_times[i - 1];

	return W;
}

template <typename T>
void pt_vt(vector<T>& v) {
	for (auto i : v) {
		cout.width(3);
		cout << i << " ";
	}
	cout << endl;
}

template <typename T>
void compute_and_print_waiting_times(vector<T>& service_times) {
	vector<T> waiting_times = compute_waiting_times<int>(service_times);

	cout << "- ó�� �ð�: ";
	pt_vt(service_times);

	cout << "- ��� �ð�: ";
	pt_vt(waiting_times);

	double ave_waiting_times = std::accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
	cout << "- ��� ��� �ð�: " << ave_waiting_times << endl;
}

void shortest_job_first_scheduling_test() {
	vector<int> service_times{ 8, 1, 2, 4, 9, 2, 3, 5 };

	cout << "[ ó�� �� ó�� �ð� & ��� �ð� ]" << endl;
	compute_and_print_waiting_times(service_times);

	// �� ó�� �ð��� ������������ ����
	std::sort(service_times.begin(), service_times.end());

	cout << "\n[ ���� �� �� ó�� �ð� & ��� �ð� ]" << endl;
	compute_and_print_waiting_times(service_times);
}