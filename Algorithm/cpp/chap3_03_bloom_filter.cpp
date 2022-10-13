#include <iostream>
#include <vector>
using namespace std;

class bloom_filter {
	vector<bool> data;
	int bits;

	// switch ������ �̿��ϸ� ���� ���� �ؽ� �Լ��� ���� ������ �ʾƵ� ��
	int hash(int num, int key) {
		switch (num) {
		case 0: return key % bits;
		case 1: return (key / 7) % bits;
		case 2: return (key / 11) % bits;
		}

		return 0;
	}

public:
	bloom_filter(int n) : bits(n) {
		data = vector<bool>(bits, false);
	}

	void lookup(int key) {
		bool rst = (bool)(data[hash(0, key)] & data[hash(1, key)] & data[hash(2, key)]);

		if (rst) cout << key << ": ���� �� ����" << endl;
		else cout << key << ": ���� ����" << endl;
	}

	void insert(int key) {
		data[hash(0, key)] = true;
		data[hash(1, key)] = true;
		data[hash(2, key)] = true;
		cout << key << " ����" << endl;

		for (auto a : data)
			cout << a << " ";
		cout << endl;
	}
};

void bm_ft() {
	bloom_filter bf(7);

	bf.insert(100);
	bf.insert(54);
	bf.insert(82);

	bf.lookup(5);
	bf.lookup(50);
	bf.lookup(20);
	bf.lookup(54);
}