#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cuckoo_hashing {
	vector<int> data1;
	vector<int> data2;
	int size;

	// ������ ��������� �����ؾ� �ϱ� ������ ���� ���� ���� �Լ��� ���� �����.
	// ��� ȣ�� Ƚ���� �ؽ� ���̺� ũ�⺸�� Ŀ���ٸ� ��ȯ���� �����Ѵ�. 
	void insert_impl(int key, int cnt, int table) {
		if (cnt >= size) {
			cout << key << " ���� �� ��ȯ �߻�!\n";
			cout << "���ؽ��� �ʿ��մϴ�.." << endl;
			return;
		}

		if (table == 1) {
			int hash = hash1(key);
			if (data1[hash] == -1) {
				cout << table << "�� ���̺� " << key << " ����" << endl;
				data1[hash] = key;
			}
			else {
				int old = data1[hash];
				data1[hash] = key;
				cout << table << "�� ���̺� " << key << " ����: ";
				cout << "������ " << old << " �̵� -> ";
				insert_impl(old, cnt + 1, 2);
			}
		}
		else {
			int hash = hash2(key);
			if (data2[hash] == -1) {
				cout << table << "�� ���̺� " << key << " ����" << endl;
				data2[hash] = key;
			}
			else {
				int old = data2[hash];
				data2[hash] = key;
				cout << table << "�� ���̺� " << key << " ����: ";
				cout << "������ " << old << " �̵� -> ";
				insert_impl(old, cnt + 1, 1);
			}
		}
	}

public:
	cuckoo_hashing(int n) : size(n)
	{
		data1 = vector<int>(size, -1);
		data2 = vector<int>(size, -1);
	}

	// �ΰ��� �ؽ� �Լ�
	int hash1(int key) const {
		return key % size;
	}

	int hash2(int key) const {
		return (key / size) % size;
	}

	// ���
	vector<int>::iterator lookup(int key) {
		int hash_value1 = hash1(key);
		
		if (data1[hash_value1] == key) {
			cout << "1�� ���̺��� " << key << " �߰�!" << endl;
			return data1.begin() + hash_value1;
		}

		int hash_value2 = hash2(key);

		if (data2[hash_value2] == key) {
			cout << "2�� ���̺��� " << key << " �߰�!" << endl;
			return data2.begin() + hash_value2;
		}

		return data2.end();
	}

	// ����
	// lookup()�� ���� �ؽ� ���̺��� key�� ã�� ���ϴ� ��� data2.end()�� ��ȯ�Ѵ�.
	void erase(int key) {
		auto pos = lookup(key);

		if (pos != data2.end()) {
			*pos = -1;
			cout << key << " ����!" << endl;
		}
		else cout << key << " �߰����� ����!" << endl;
	}

	// ����
	void insert(int key) {
		insert_impl(key, 0, 1);
	}

	void prt_all() {
		cout << "Index: ";
		for (int i = 0; i < size; i++) cout << i << '\t';
		cout << endl;

		cout << "Data1: ";
		for_each(data1.begin(), data1.end(), [](int val) {
			cout << val << '\t';
		});
		cout << endl;

		cout << "Data2: ";
		for (auto it = data2.begin(); it != data2.end(); it++)
			cout << *it << '\t';
		cout << endl;
	}
};

void cuckoo_hashing_ex() {
	cuckoo_hashing map(7);
	map.prt_all();
	cout << endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	cout << endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	cout << endl;

	map.prt_all();
	cout << endl;
	map.insert(14);   // ��ȯ �߻�

}