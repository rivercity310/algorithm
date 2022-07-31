#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include "graph_and_edge.h"

using namespace std;


// ���� �켱 Ž���� ������ �Լ�
template <typename T>
vector<unsigned> depth_first_search(const Graph<T>& G, unsigned start) {
	stack<unsigned> stack;
	set<unsigned> visited;
	vector<unsigned> visit_order;

	stack.push(start);

	while (!stack.empty()) {
		unsigned current_vertex = stack.top();
		stack.pop();

		// ���� ������ ������ �湮���� �ʾҴٸ�
		if (visited.find(current_vertex) == visited.end()) {
			visited.insert(current_vertex);
			visit_order.push_back(current_vertex);

			for (Edge<T>& e : G.edges(current_vertex))
				// ������ ���� �߿��� �湮���� ���� ������ �ִٸ� ���ÿ� �߰�
				if (visited.find(e.dst) == visited.end())
					stack.push(e.dst);
		}
	}

	return visit_order;
}

void dfs_test() {
	using T = unsigned;

	// �׷��� ��ü ����
	Graph<T> G = create_reference_graph<T>();

	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	// 1�� �������� DFS ���� & �湮 ���� ���
	cout << "\n\n[DFS �湮 ����]" << endl;
	vector<unsigned> dfs_visit_order = depth_first_search(G, 1);
	for (unsigned v : dfs_visit_order)
		cout << v << endl;
}





bool visited[9];
vector<int> graph[9];

void dfs(int x) {
	visited[x] = true;
	cout << x << " ";

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) 
			dfs(y);
	}
}

bool visited2[9];

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited2[x] = true;

	while (!q.empty()) {
		int curr_vertex = q.front();
		q.pop();

		cout << curr_vertex << " ";

		for (int i = 0; i < graph[curr_vertex].size(); i++) {
			int y = graph[curr_vertex][i];
			if (!visited2[y]) {
				q.push(y);
				visited2[y] = true;
			}
		}
	}

}

void m_test() {
	graph[0] = {};
	graph[1] = { 2, 3, 8 };
	graph[2] = { 1, 7 };
	graph[3] = { 1, 4, 5 };
	graph[4] = { 3, 5 };
	graph[5] = { 3, 4 };
	graph[6] = { 7 };
	graph[7] = { 2, 6, 8 };
	graph[8] = { 1, 7 };

	dfs(1);
	cout << endl;
	bfs(1);
}