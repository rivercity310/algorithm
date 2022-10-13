#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include "graph_and_edge.h"

using namespace std;


// �ʺ� �켱 Ž�� �˰��� ����
template <typename T>
vector<unsigned> breadth_first_search(const Graph<T>& G, unsigned start) {
	queue<unsigned> queue;
	set<unsigned> visited;          // �湮�� ����
	vector<unsigned> visit_order;   // �湮 ����
	
	queue.push(start);

	while (!queue.empty()) {
		unsigned current_vertex = queue.front();
		queue.pop();

		// ���� ������ ������ �湮���� �ʾҴٸ�
		if (visited.find(current_vertex) == visited.end()) {
			visited.insert(current_vertex);
			visit_order.push_back(current_vertex);

			for (Edge<T>& e : G.edges(current_vertex)) 
				// ������ ���� �߿��� �湮���� ���� ������ �ִٸ� ť�� �߰�
				if (visited.find(e.dst) == visited.end())
					queue.push(e.dst);
		}
	}

	return visit_order;
}


// �׽�Ʈ �Լ�
void bfs_test() {
	using T = unsigned;

	// �׷��� ��ü ����
	Graph<T> G = create_reference_graph<T>();

	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	// 1�� �������� BFS ���� & �湮 ���� ���
	cout << "\n\n[BFS �湮 ����]" << endl;
	vector<unsigned> bfs_visit_order = breadth_first_search(G, 1);
	for (int i = 0; i < bfs_visit_order.size(); i++) {
		cout << bfs_visit_order[i];
		if (i != bfs_visit_order.size() - 1) cout << " -> ";
	}
}