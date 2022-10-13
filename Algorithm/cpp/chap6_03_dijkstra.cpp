#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <limits>
#include <algorithm>

#include "Label.h"
#include "graph_and_edge.h"
using namespace std;

template <typename T>
vector<unsigned> dijkstra_shortest_path(const Graph<T>& G, unsigned src, unsigned dst) {
	// �ּ� ��
	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;

	// ��� �������� �Ÿ� ���� �ִ�� ����
	vector<T> distance(G.vertices(), numeric_limits<T>::max());

	set<unsigned> visited;                     // �湮�� ����
	vector<unsigned> parent(G.vertices());     // �̵� ��� ����� ���� ����

	heap.emplace(Label<T>{src, 0});
	parent[src] = src;

	while (!heap.empty()) {
		Label<T> current_vertex = heap.top();
		heap.pop();

		// ������ ������ �����ߴٸ� ����
		if (current_vertex.ID == dst) {
			cout << current_vertex.ID << "�� ����(���� ����)�� ����!" << endl;
			break;
		}

		// ���� ������ ������ �湮���� �ʾҴٸ�
		if (visited.find(current_vertex.ID) == visited.end()) {
			cout << current_vertex.ID << "�� ������ ����!" << endl;

			// ���� ������ ����� ��� ������ ����
			for (Edge<T>& e : G.edges(current_vertex.ID)) {
				unsigned neighbor = e.dst;
				unsigned new_distance = current_vertex.distance + e.weight;

				// ������ ������ �Ÿ� ���� ���ο� ��ο� ���� �Ÿ������� ũ��
				// ���� �߰��ϰ� �Ÿ� ���� ������Ʈ �Ѵ�
				if (new_distance < distance[neighbor]) {
					heap.emplace(Label<T>{neighbor, new_distance});

					parent[neighbor] = current_vertex.ID;
					distance[neighbor] = new_distance;
				}
			}

			visited.insert(current_vertex.ID);
		}
	}

	// ��Ʈ��ŷ ������� ���� �������� ���� ���������� ��� ����
	vector<unsigned> shortest_path;
	unsigned current_vertex = dst;

	while (current_vertex != src) {
		shortest_path.push_back(current_vertex);
		current_vertex = parent[current_vertex];
	}

	shortest_path.push_back(src);
	reverse(shortest_path.begin(), shortest_path.end());

	return shortest_path;
}

void dijkstra_test() {
	using T = unsigned;

	Graph<T> G = create_reference_graph2<T>();

	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	vector<unsigned> shortest_path = dijkstra_shortest_path<T>(G, 1, 6);

	cout << "\n[1���� 6�� ���� ������ �ִ� ���]" << endl;
	for (unsigned v : shortest_path)
		cout << v << " ";
	cout << endl;
}