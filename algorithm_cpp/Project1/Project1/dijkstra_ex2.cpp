#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INFF = 1e9;
constexpr int MAX_NODE = 100001;

// �ִ� ��� ������ 10������� ����
vector<pair<int, int>> grp_ex[MAX_NODE];
int dist_ex[MAX_NODE];

void init_grp(int N) {
	grp_ex[1] = { {2, 2}, {3, 5}, {4, 1} };
	grp_ex[2] = { {3, 3}, {4, 2} };
	grp_ex[3] = { {2, 3}, {6, 5} };
	grp_ex[4] = { {3, 3}, {5, 1} };
	grp_ex[5] = { {3, 1}, {6, 2} };

	fill(dist_ex, dist_ex + (N + 1), INFF);
}

void dijkstra_with_pq(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });		// { �Ÿ�, ��� ��ȣ } ������ ť�� �߰�
	dist_ex[start] = 0;

	while (!pq.empty()) {
		pair<int, int> p = pq.top();
		pq.pop();

		// ť�� �⺻ ���� �ִ����̹Ƿ� ������Ҷ� ������ �ٿ� �ּ���ó�� �����ϰ� �����.
		int now_dist = -p.first;
		int now_vertex = p.second;

		// ���� �Ÿ� ������ ť���� ���� �Ÿ� ���� �� ũ�� �̹� ó���� ���� �����Ѵ�.
		if (dist_ex[now_vertex] < now_dist)
			continue;

		for (pair<int, int> k : grp_ex[now_vertex]) {
			int end_vertex = k.first;
			int weight = k.second;

			int cost = dist_ex[now_vertex] + weight;
			if (dist_ex[end_vertex] > cost) {
				dist_ex[end_vertex] = cost;
				pq.push({ -cost, end_vertex });
			}
		}
	}
}

void dijkstra_ex() {
	int N = 6;
	int start = 1;

	init_grp(N);
	dijkstra_with_pq(start);

	for (int i = 1; i <= N; i++)
		cout << dist_ex[i] << " ";
}