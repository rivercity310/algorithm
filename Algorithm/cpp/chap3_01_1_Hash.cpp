#include <iostream>
#include <vector>
using namespace std;

class hash_map {
	using uint = unsigned int;

	vector<int> data;

public:
	hash_map(size_t n) {
		data = vector<int>(n, -1);
	}

	void insert(int val) {
		int n = data.size();
		data[val % n] = val;
		cout << val << " ����!" << endl;
	}

	bool find(uint val) {
		int n = data.size();
		return data[val % n] == val;
	}

	void erase(uint val) {
		int n = data.size();
		if (data[val % n] == val) {
			data[val % n] = -1;
			cout << val << " ����!" << endl;
		}
	}
};

void hs_1() {
	hash_map hs(10);

	auto print = [&](int value) {
		if (hs.find(value)) cout << "�ؽ� �ʿ��� " << value << " ã��!" << endl;
		else cout << "�ؽ� �ʿ��� " << value << " ã�� ����!" << endl;
		cout << endl;
	};

	for (int i = 0; i < 10; i++) hs.insert(i);
	print(5);

	hs.erase(8);
	print(8);



}