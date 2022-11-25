//#pragma once
//
//using namespace std;
//
//class SimpleDisjointSet {
//private:
//	typedef struct node {
//		unsigned id;
//		unsigned rank;
//		unsigned parent;
//
//		struct node(unsigned _id) : id(_id), rank(0), parent(_id) {}
//
//		bool operator != (const struct node& n) const {
//			return this->id != n.id;
//		}
//	} Node;
//
//	// ������Ʈ-�� ������Ʈ
//	vector<Node> nodes;
//
//public:
//	SimpleDisjointSet(unsigned N) {
//		nodes.reserve(N);
//	}
//
//	void make_set(const unsigned& x) {
//		nodes.emplace_back(x);
//	}
//
//	unsigned find(unsigned x) {
//		vector<Node>::iterator node_it = find_if(nodes.begin(), nodes.end(),
//			[x](Node n) {
//				return n.id == x;
//			});
//
//		unsigned node_id = node_it->id;
//
//		while (node_id != nodes[node_id].parent)
//			node_id = nodes[node_id].parent;
//
//		return node_id;
//	}
//
//	void union_sets(unsigned x, unsigned y) {
//		unsigned root_x = find(x);
//		unsigned root_y = find(y);
//
//		// ���� x�� y�� ���� Ʈ���� �ִٸ� �״�� ����
//		if (root_x == root_y) return;
//
//		// ���� ��ũ�� Ʈ���� ū ��ũ�� Ʈ�� ������ ����
//		if (nodes[root_x].rank > nodes[root_y].rank)
//			swap(root_x, root_y);
//
//		nodes[root_x].parent = nodes[root_y].parent;
//		nodes[root_y].rank++;
//	}
//
//	vector<Node> get_forest() {
//		return this->nodes;
//	}
//};