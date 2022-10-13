#include <iostream>
#include <vector>
#include <limits>

using namespace std;

/*
���� ����ġ�� �ִ� �׷������� ���ͽ�Ʈ�� �˰����� ����� �������� ���� ���ɼ��� �ִ�.
���� ����-���� �˰����� ����Ѵ�.

�׷����� ��� ������ ���� ���ͽ�Ʈ���� �׸��� ���� ����� (V - 1)�� �ݺ�
�Ͽ� ���������� �ִ� �Ÿ��� ã�´�.

��������� ���ͽ�Ʈ�� �˰��򺸴� �� ���� ������ �ð� ���⵵�� ��������
��Ȯ�� ����� �����Ѵ�.
*/


// ���� ����ü
struct Edge {
	int src;
	int dst;
	int weight;
};

// ���Ѵ븦 ǥ���ϴ� ���
const int UNKNOWN = numeric_limits<int>::max();


// ����-���� �˰��� ���� �Լ�
// edges: �׷����� �����ϴ� ���� ����Ʈ, V: ���� ����, start: ��� ���� ��ȣ
vector<int> BellmanFord(vector<Edge> edges, const int V, int start) {
	vector<int> distance(V, UNKNOWN);
	distance[start] = 0;

	// (V - 1)�� �ݺ�
	for (int i = 0; i < V - 1; i++) {

		// ��ü ������ ���� �ݺ�
		for (Edge& e : edges) {

			// ������ ���� ������ �Ÿ� ���� UNKNOWN�̸� ��ŵ
			if (distance[e.src] == UNKNOWN) continue;

			// ������ ������ �Ÿ� ���� ���ο� ��ο� ���� �Ÿ� ������ ũ�� ������Ʈ
			if (distance[e.dst] > distance[e.src] + e.weight) {
				cout << "(" << e.src << ", " << e.dst << ") ";
				cout << distance[e.dst] << " => " << distance[e.src] + e.weight << endl;
				
				distance[e.dst] = distance[e.src] + e.weight;
			}
		}
	}

	return distance;
}


void BellmanFord_Test() {
	const int V = 5;     // ���� ����
	vector<Edge> edges;

	vector<vector<int>> edge_map{		// {���� ����, ��ǥ ����, ����ġ}
		{0, 1, 3},
		{1, 2, 5},
		{1, 3, 10},
		{3, 2, -7},
		{2, 4, 2}
	};

	for (vector<int>& v : edge_map)
		edges.emplace_back(Edge{ v[0], v[1], v[2] });

	for (int i = 0; i < edges.size(); i++) {
		int start = i;
		vector<int> distance = BellmanFord(edges, V, start);

		cout << "[" << start << "�� �������κ��� �ּ� �Ÿ�]\n";

		for (int j = 0; j < distance.size(); j++) {
			if (distance[j] == UNKNOWN)
				cout << j << "�� ����: X" << "\n";
			else
				cout << j << "�� ����: " << distance[j] << "\n";
		}

		cout << endl;
	}
}

vector<int> BF(vector<Edge> edges, int V, int start) {
	vector<int> distance(V, UNKNOWN);
	distance[start] = 0;

	for (int i = 0; i < V - 1; i++) {
		
		cout << "[ " << i + 1 << "��° �ݺ� ]" << endl;

		for (Edge& e : edges) {
			if (distance[e.src] == UNKNOWN)
				continue;

			if (distance[e.dst] > distance[e.src] + e.weight) {
				cout << "(" << e.src << ", " << e.dst << ") : ";
				cout << distance[e.dst] << " => " << distance[e.src] + e.weight << endl;

				distance[e.dst] = distance[e.src] + e.weight;
			}
		}
	}

	return distance;
}

void bf_test() {
	const int V = 5;

	vector<Edge> edges;

	vector<vector<int>> edge_map{		// {���� ����, ��ǥ ����, ����ġ}
		{0, 1, 3},
		{1, 2, 5},
		{1, 3, 10},
		{3, 2, -7},
		{2, 4, 2}
	};

	for (vector<int>& v : edge_map)
		edges.emplace_back(Edge{ v[0], v[1], v[2] });

	for (int i = 0; i < edges.size(); i++) {
		int start = i;

		cout << "[[ ���� ���� : " << start << " ]]" << endl;

		vector<int> distance = BF(edges, V, i);

		for (int j = 0; j < distance.size(); j++) {
			if (distance[j] == UNKNOWN)
				cout << "X ";
			else
				cout << distance[j] << " ";
		}
		cout << "\n" << endl;
	}
}