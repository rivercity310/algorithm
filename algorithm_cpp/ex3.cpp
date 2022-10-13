#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [ �������� 3. ���� ]

constexpr int INF = 1e9;
constexpr int MAX = 30001;

// ���� �׷��� => ���� ����Ʈ ������� ����, ���� ����ġ�� �ִ� �׷������ pair
// ������ �׷��� => ���� ��� ������� ����
vector<pair<int, int>> city_ex3[MAX];
vector<int> city_dist(MAX, INF);

void dijk_city(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	city_dist[start] = 0;

	while (!pq.empty()) {
		pair<int, int> pr = pq.top();
		pq.pop();

		int dist = pr.first;
		int now = pr.second;

		if (city_dist[now] < dist)
			continue;

		for (pair<int, int>& p : city_ex3[now]) {
			int end_vertex = p.first;
			int weight = p.second;
			int cost = city_dist[now] + weight;

			if (city_dist[end_vertex] > cost) {
				city_dist[end_vertex] = cost;
				pq.push({ cost, end_vertex });
			}
		}
	}
}

void dijk_ex3() {
	int N, M, C;
	cin >> N >> M >> C;

	while (M--) {
		int X, Y, Z;
		cin >> X >> Y >> Z;

		// Ư�� ���� X���� �ٸ� Ư�� ���� Y�� �̾����� ����� ���޽ð��� Z
		city_ex3[X].push_back(make_pair(Y, Z));
	}

	dijk_city(C);

	cout << "[���ͽ�Ʈ�� ���]" << "\n";
	for (int i = 1; i <= N; i++)
		cout << city_dist[i] << "\t";
	cout << endl;

	int received_cnt = 0;
	int maximum_time = 0;

	for (int i = 1; i <= N; i++) {
		if (city_dist[i] != INF) {
			maximum_time = max(maximum_time, city_dist[i]);
			received_cnt++;
		}

	}

	cout << received_cnt - 1 << " " << maximum_time;
}