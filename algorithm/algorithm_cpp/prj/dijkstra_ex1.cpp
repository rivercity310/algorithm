#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

// constexpr : ��ũ��(define)ó�� ������ ����� ����
constexpr int INF = 1e9;

vector<vector<pair<int, int>>> grph;
vector<int> dist;
set<int> visited;
int cnt = 0;

ostream& operator << (ostream& os, vector<int>& dist) {
	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == INF)
			os << "-1 ";
		else
			os << dist[i] << " ";
	}

	cnt++;

	return os;
}

// �켱���� ť(��)�� ����ϸ� �� ������ O(logN) �������� ���� �� �ִ�. 
int get_smallest_node() {
	int min_value = INF;
	int idx = 0;

	for (int i = 1; i < grph.size(); i++) {
		if (dist[i] < min_value && visited.find(i) == visited.end()) {
			min_value = dist[i];
			idx = i;
		}
	}

	return idx;
}

void dijkstra_test(int start) {
	dist[start] = 0;
	visited.insert(start);
	for (auto& p : grph[start])
		dist[p.first] = p.second;

	cout << "\n\n��� ���� : " << start << "\n";
	cout << "������Ʈ �Ϸ�\n";
	cout << dist << "\n\n" << endl;

	for (int i = 0; i < grph.size() - 2; i++) {
		int now = get_smallest_node();
		visited.insert(now);

		for (auto& p : grph[now]) {
			int cost = dist[now] + p.second;

			if (cost < dist[p.first])
				dist[p.first] = cost;
		}

		cout << "��� ���� : " << now << "\n";
		cout << "������Ʈ �Ϸ�\n";
		cout << dist << "\n\n" << endl;
	}
}

int main_dijk() {
	int N, M;
	cin >> N >> M;

	grph = vector<vector<pair<int, int>>>(N + 1);
	dist = vector<int>(N + 1, INF);

	int start;
	cin >> start;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		grph[a].push_back(make_pair(b, c));
	}

	dijkstra_test(start);

	cout << dist;

	cout << "\n\n������ �ߺ� �Լ��� ȣ�� Ƚ�� : " << cnt;

	return 0;
}