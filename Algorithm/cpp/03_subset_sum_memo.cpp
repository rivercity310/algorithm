#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int UNKNOWN = INT_MAX;

bool SubsetSum_Memoization(vector<int>& set, int sum, int i, vector<vector<int>>& memo) {
	if (sum == 0) return true;
	if (i == set.size() || set[i] > sum) return false;

	// ���� ���°� ĳ�ÿ� �ִ��� Ȯ��
	if (memo[i][sum] == UNKNOWN) {
		// ���� ���¿� ���� �ַ���� ���Ͽ� ĳ�ÿ� ����
		bool append = SubsetSum_Memoization(set, sum - set[i], i + 1, memo);
		bool ignore = SubsetSum_Memoization(set, sum, i + 1, memo);

		memo[i][sum] = append || ignore;
	}

	return memo[i][sum];
}

void subset_memo_test() {
	vector<int> set = { 16, 1058, 22, 13, 46, 55, 3, 92, 47, 7, 98, 367, 807, 106, 333, 85, 577, 9, 3059 };
	int target = 6799;
	
	sort(set.begin(), set.end());

	vector<vector<int>> memo(set.size(), vector<int>(7000, UNKNOWN));
	bool found = SubsetSum_Memoization(set, target, 0, memo);

	if (found) cout << "�κ� ���� ����" << endl;
	else cout << "�κ� ���� �������� ����!" << endl;
}