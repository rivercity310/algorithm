#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Object {
	int id;
	int weight;
	double value;
	double value_per_unit_weight;

	Object(int id, int weight, double value) {
		this->id = id;
		this->weight = weight;
		this->value = value;
		this->value_per_unit_weight = value / weight;
	}

	// sort()���� ���
	inline bool operator<(const Object& obj) {
		return this->value_per_unit_weight < obj.value_per_unit_weight;
	}

	friend ostream& operator<<(ostream& os, const Object& obj) {
		os << "[" << obj.id << "] ����: " << obj.value
			<< " \t����: " << obj.weight
			<< " kg\t���� ���� �� ����: " << obj.value_per_unit_weight;

		return os;
	}
};

// ���� ���� �賶 ���� �˰��� ���� �Լ�
auto fill_knapsack(vector<Object>& objects, int knapsack_capacity) {
	vector<Object> knapsack_contents;
	knapsack_contents.reserve(objects.size());

	// ���ǵ��� ������������ ����
	std::sort(objects.begin(), objects.end());
	std::reverse(objects.begin(), objects.end());

	// '���� ��ġ �ִ�' ������ ���� �賶�� �߰�
	vector<Object>::iterator curr_obj = objects.begin();
	int curr_total_weight = 0;

	while (curr_total_weight < knapsack_capacity && curr_obj != objects.end()) {
		knapsack_contents.push_back(*curr_obj);

		curr_total_weight += curr_obj->weight;
		curr_obj++;
	}

	// �������� �߰��� ���ǿ� ���� �賶 �ִ� ��� ���԰� �ʰ��� ���
	int weight_of_last_obj_to_remove = curr_total_weight - knapsack_capacity;
	Object& last_object = knapsack_contents.back();

	if (weight_of_last_obj_to_remove > 0) {
		last_object.weight -= weight_of_last_obj_to_remove;
		last_object.value -= last_object.value_per_unit_weight * weight_of_last_obj_to_remove;
	}

	return knapsack_contents;
}

void fractinal_knapsack_problem_test() {
	vector<Object> obj;
	obj.reserve(7);

	vector<int> weights{ 1, 2, 5, 9, 2, 3, 4 };
	vector<double> values{ 10, 7, 15, 10, 12, 11, 5 };

	for (auto i = 0; i < 7; i++)
		obj.push_back(Object(i + 1, weights[i], values[i]));


	// ����� �� �ִ� ���� ���� ����ϱ�
	cout << "[����� �� �ִ� ���� ����]" << "\n";
	for (auto& o : obj) cout << o << endl;
	cout << endl;


	// ���� ���� �賶 ���� �˰��� ����, �賶�� �ִ� ��� ���Դ� 7�� ����
	int knapsack_capacity = 7;
	vector<Object> solution = fill_knapsack(obj, knapsack_capacity);

	
	// �賶�� ���� ���� ���� ���
	cout << "[�賶�� ���� ���ǵ� (�ִ� �뷮 = " << knapsack_capacity << ")]" << endl;
	for (auto& o : solution) cout << o << endl;
	cout << endl;
}