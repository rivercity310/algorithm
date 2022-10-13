#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <limits>
#include "graph_and_edge.h"
#include "label.h"
using namespace std;

// ���� �˰��� ���� �Լ�
template <typename T>
vector<unsigned> prim_MST(const Graph<T>& G, unsigned src) {
	// �ּ� ��
	priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;

	// ��� �������� �Ÿ� ���� �ִ�� ����
	vector<T> distance(G.vertices(), numeric_limits<T>::max());

	set<unsigned> visited;     // �湮�� ����
	vector<unsigned> MST;      // �ּ� ���� Ʈ��

	heap.emplace(Label<T>{src, 0});

	while (!heap.empty()) {
		Label<T> current_vertex = heap.top();
		heap.pop();

		// ���� ������ ������ �湮���� �ʾҴٸ�
		if (visited.find(current_vertex.ID) == visited.end()) {
			MST.push_back(current_vertex.ID);

			for (Edge<T>& e : G.edges(current_vertex.ID)) {
				unsigned neighbor = e.dst;
				T new_distance = e.weight;

				// ������ ������ �Ÿ� ���� ���ο� ��ο� ���� �Ÿ������� ũ��
				// ���� �߰��ϰ�, �Ÿ� ���� ������Ʈ
				if (new_distance < distance[neighbor]) {
					heap.emplace(Label<T>{neighbor, new_distance});
					distance[neighbor] = new_distance;
				}
			}

			visited.insert(current_vertex.ID);
		}
	}

	return MST;
}

void prim_test() {
	using T = unsigned;

	Graph<T> G = create_reference_graph2<T>();
	cout << "[�Է� �׷���]" << endl;
	cout << G << endl;

	vector<unsigned> MST = prim_MST<T>(G, 1);

	cout << "\n\n[�ּ� ���� Ʈ��]" << endl;
	for (unsigned v : MST)
		cout << v << endl;
	cout << endl;
}