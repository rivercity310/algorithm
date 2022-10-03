#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
[ �κ� ������ �� ���� ]

Dynamic Programming�� ���� �˾ƺ��鼭 ���� ����(Brute-Force), ��Ʈ��ŷ, �޸������̼�, Ÿ�淹�̼��̶��
�� ���� ���� ����� ���� ��� ����غ���.

�տ� ������ ���� ����� �Է� ũ�� N�� �����Կ� ���� �� �Ѱ谡 ��Ȯ�ϴ�.
�׷����� �̵� ����� ���ʴ�� �����غ����μ� �� ���� ����� ���̸� �˾ư��� ���� ��ǥ�̴�.
*/

#define DEBUG 0
#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

/* ���� set�� ��� �κ������� ���ϴ� �Լ� */
void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets) {
	
	// ���� set�� ���� �ٴٸ� ���
	if (index == set.size()) {

		// �κ����� ũ�⸦ �ε����� ����Ͽ� �κ������� allSubsets�� �߰�
		allSubsets[subset.size()].push_back(subset);
		return;
	}

	// ���Ҹ� �߰����� �ʰ� ��� ȣ��
	GetAllSubsets(set, subset, index + 1, allSubsets);

	// ���Ҹ� �κ����տ� �߰��� �� ��� ȣ��
	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubsets);
}

bool SubsetSum_BruteForce(vector<int> set, int target) {
	vector<vector<vector<int>>> allSubsets(set.size() + 1);
	GetAllSubsets(set, {}, 0, allSubsets);

	/* �� �κ������� ���� ���� target�� ���ϰ� ��ġ�ϸ� true ��ȯ */
	for (int i = 0; i < set.size(); i++) {
		PRINT("�κ������� ���� ����: " << i << endl);

		for (auto subset : allSubsets[i]) {
			PRINT("\t{ ");
			
			int sum = 0;
			for (auto number : subset) {
				sum += number;
				PRINT(number << " ");
			}

			PRINT("} = " << sum << endl);

			if (sum == target)
				return true;
		}
	}

	return false;
}

void subset_test() {
	vector<int> set = { 13, 79, 45, 29 };
	int target = 58;

	bool found = SubsetSum_BruteForce(set, target);

	if (found) cout << "���� ���� " << target << "�� �κ����� ����!" << endl;
	else cout << "���� ���� " << target << "�� �κ����� �������� ����!" << endl;
}