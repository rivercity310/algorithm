#include <map>

using namespace std;

// ������ �׷��� ����
template <typename T>
struct Edge {
	unsigned src;
	unsigned dst;
	T weight;

	// Edge ��ü �񱳴� ����ġ�� �̿��Ѵ�.
	inline bool operator < (const Edge<T>& e) const {
		return this->weight < e.weight;
	}

	inline bool operator > (const Edge<T>& e) const {
		return this->weight > e.weight;
	}
};

template <typename T>
class Graph {
private:
	unsigned V;     // ������ ����
	vector<Edge<T>> edge_list;

public:
	// N���� �������� ������ �׷���
	Graph(unsigned N) : V(N) {}

	// �׷����� ���� ���� ��ȯ
	unsigned vertices() const {
		return V;
	}

	// ��ü ���� ����Ʈ ��ȯ
	const vector<Edge<T>>& edges() const {
		return edge_list;
	}

	// ���� v���� ������ ��� ������ ��ȯ
	vector<Edge<T>> edges(unsigned v) const {
		vector<Edge<T>> edges_from_v;

		for (Edge<T> e : edge_list)
			if (e.src == v)
				edges_from_v.emplace_back(e);

		return edges_from_v;
	}

	void add_edge(Edge<T>&& e) {
		// ���� �� �� ���� ID�� ��ȿ���� �˻�
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
			edge_list.emplace_back(e);
		else
			cerr << "����: ��ȿ ������ ��� ����" << endl;
	}

	// ǥ�� ��� ��Ʈ�� ����
	template <typename U>
	friend ostream& operator<<(ostream& os, const Graph<U>& G) {
		for (unsigned i = 1; i < G.vertices(); i++) {
			os << i << ":\t";
			vector<Edge<T>> edges = G.edges(i);

			for (Edge<T>& e : edges)
				os << "{" << e.dst << ": " << e.weight << "}, ";

			os << endl;
		}

		return os;
	}
};

// �׷����� �����Ͽ� ��ȯ�ϴ� �Լ�
template <typename T>
Graph<T> create_reference_graph() {
	Graph<T> G(9);

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	for (auto& i : edge_map)
		for (auto& j : i.second)
			G.add_edge(Edge<T>{i.first, j.first, j.second});

	return G;
}

// �׷����� �����Ͽ� ��ȯ�ϴ� �Լ�
template <typename T>
Graph<T> create_reference_graph2() {
	Graph<T> G(9);

	map<unsigned, vector<pair<unsigned, T>>> edge_map;
	edge_map[1] = { {2, 2}, {5, 3} };
	edge_map[2] = { {1, 2}, {5, 5}, {4, 1} };
	edge_map[3] = { {4, 2}, {7, 3} };
	edge_map[4] = { {2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5} };
	edge_map[5] = { {1, 3}, {2, 5}, {4, 2}, {8, 3} };
	edge_map[6] = { {4, 4}, {7, 4}, {8, 1} };
	edge_map[7] = { {3, 3}, {6, 4} };
	edge_map[8] = { {4, 5}, {5, 3}, {6, 1} };

	for (auto& i : edge_map)
		for (auto& j : i.second)
			G.add_edge(Edge<T>{i.first, j.first, j.second});

	return G;
}
