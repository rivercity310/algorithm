#include <iostream>

using namespace std;

constexpr int INF = 1e9;

/*
[ �湮 �Ǹſ� ���� ]
�Է¹��� �׷������� 1 -> K -> X�� ���� �ִ� ��� �� ���ϱ�
*/

// C++���� 2���� �迭�� �迭������ ������ ��ȯ�ؾ� �Ѵ�.
// �迭 �����Ϳ� ������ �迭(ex. int* arr[])�� ���̴� ���� �˻�
typedef int(*arrPointer)[501];

arrPointer init_grp(int N, int M) {
	// ��ȯ �� �������� gp�� ������� ���� ���� ���� static ����
	static int gp[501][501] = { 0, };

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (i == j) gp[i][j] = 0;
			else gp[i][j] = INF;
		}

	while (M--) {
		int a, b;
		cin >> a >> b;

		gp[a][b] = 1;
		gp[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
		for (int a = 1; a <= N; a++)
			for (int b = 1; b <= N; b++)
				gp[a][b] = std::min(gp[a][b], gp[a][k] + gp[k][b]);

	return gp;
}

void chap7_ex1() {
	int N, M;
	cin >> N >> M;

	// �迭������ ������ �ޱ�
	// arrPointer gp = init_grp(N, M) �Ǵ�
	int(*gp)[501] = init_grp(N, M);

	// �׷��� ���
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%-5d", gp[i][j]);
		putchar('\n');
	}

	int X, K;
	cin >> X >> K;

	int dist = gp[1][K] + gp[K][X];
	int val = dist >= INF ? -1 : dist;

	cout << val;
}