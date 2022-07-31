#include <iostream>
#include <iomanip>
using namespace std;

/*
[ Floyd-Warshall ]
- ��� ��忡�� �ٸ� ��� ������ �ִ� �Ÿ��� ����ϴ� �˰���
- Time Complexity = O(N^3)
*/

constexpr int FW_INF = 1e9;
constexpr int FW_MAX = 501;

int fw_grp[FW_MAX][FW_MAX];

void fw_init(int N) {
	for (int i = 1; i <= N; i++)
		fill(fw_grp[i], fw_grp[i] + (N + 1), FW_INF);

	for (int a = 1; a <= N; a++)
		for (int b = 1; b <= N; b++)
			if (a == b)
				fw_grp[a][b] = 0;
	
	// fw_grp[a][b] = c    =>    a���� b�� ���� ����� c
	fw_grp[1][2] = 2;
	fw_grp[1][3] = 5;
	fw_grp[1][4] = 1;

	fw_grp[2][3] = 3;
	fw_grp[2][4] = 2;

	fw_grp[3][2] = 3;
	fw_grp[3][6] = 5;

	fw_grp[4][3] = 3;
	fw_grp[4][5] = 1;

	fw_grp[5][3] = 1;
	fw_grp[5][6] = 2;
}

void floyd_warshall(int N) {
	// ��ȭ�� => D_ab = min(D_ab, D_ak + D_kb)
	// a���� b�� ���� ��ο� k�� ���� ���� ����� ���� ������ ������Ʈ �ݺ�
	for (int k = 1; k <= N; k++)
		for (int a = 1; a <= N; a++)
			for (int b = 1; b <= N; b++)
				fw_grp[a][b] = std::min(fw_grp[a][b], fw_grp[a][k] + fw_grp[k][b]);
}

void FW_Test() {
	int N = 6;
	fw_init(N);

	floyd_warshall(N);

	// ���
	for (int a = 1; a <= N; a++) {
		for (int b = 1; b <= N; b++) {
			int val = fw_grp[a][b] == FW_INF ? -1 : fw_grp[a][b];
			cout << setw(5) << left << val;
		}
		cout << "\n";
	}
}