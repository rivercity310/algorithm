#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <time.h>

using namespace std;

/*
��ȿ���� ���� ��� ��츦 �����ϴ� ��Ʈ��ŷ ��� 

���� ���� ������ �߰��Ͽ� ���ʿ��� ������ ���ش�.

- 1. ���� ���� �κ������� ���� target�� ���ٸ� TRUE
- 2. �׷��� �ʴٸ�:
	- ���� ���� �κ������� ���� target���� ũ�ٸ� FALSE
	- ���� ������ ���� ������ ��� FALSE
*/

bool SubsetSum_Backtracking(vector<int>& set, int sum, int i) {
	// ���� ���� ó�� �ڵ�
	/* ���� ���� �κ������� ���� target�� ���ٸ� */
	if (sum == 0) return true;

	/* ���� ������ ���� �����߰ų�, �κ������� ���� target���� Ŀ���� */
	if (i == set.size() || set[i] > sum) return false;

	
	/* 
	=> Case 1: sum���� set[i]�� ���� ��� ȣ�� (i��° ���Ҹ� �κ����տ� �߰�)
	=> Case 2: sum�� �״�� �����Ͽ� ��� ȣ�� (i���� ���Ҹ� �κ����տ� �߰����� ����)
	*/
	return SubsetSum_Backtracking(set, sum - set[i], i + 1) || SubsetSum_Backtracking(set, sum, i + 1);
}

void GetTime(clock_t& timer, string type) {
	timer = clock() - timer;

	cout << type << " ��� ��� �ð� : ";
	cout << fixed << setprecision(5) << (float)timer / CLOCKS_PER_SEC << endl;

	timer = clock();
}

void subset_bt_test() {
	vector<int> set = { 16, 1058, 22, 13, 46, 55, 3, 92, 47, 7, 98, 367, 807, 106, 333, 85, 577, 9, 3059 };
	int target = 6076;

	sort(set.begin(), set.end());

	clock_t timer = clock();
	bool found = SubsetSum_Backtracking(set, target, 0);

	if (found) cout << "���� ���� " << target << "�� �κ����� ����!" << endl;
	else cout << "���� ���� " << target << "�� �κ����� �������� ����!" << endl;

	GetTime(timer, "Back Tracking");
	cout << endl;
}