//#include <iostream>
//#include <vector>
//#include <string>
//#include <unordered_map>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <utility>
//
//using namespace std;
//
//extern unordered_map<unsigned, string> color_map;
//
//namespace welsh_powell {
//
//	template <typename T>
//	struct Edge {
//		unsigned src;
//		unsigned dst;
//		T weight;
//
//		inline bool operator < (const Edge<T>& e) const {
//			return this->weight < e.weight;
//		}
//	};
//
//	template <typename T>
//	class Graph {
//	private:
//		unsigned V;
//		vector<Edge<T>> edge_list;
//
//	public:
//		Graph(unsigned N) : V(N) {}
//
//		unsigned vertices() const {
//			return V;
//		}
//
//		vector<Edge<T>>& edges() const {
//			return edge_list;
//		}
//
//		vector<Edge<T>> edges(unsigned v) const {
//			vector<Edge<T>> edges_from_v;
//
//			for (auto& e : edge_list)
//				if (e.src == v)
//					edges_from_v.push_back(e);
//
//			return edges_from_v;
//		}
//
//		// ������ ������ &&
//		void add_edge(Edge<T>&& e) {
//			if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
//				edge_list.emplace_back(e);
//			else
//				cerr << "Error! " << endl;
//		}
//
//		// ǥ�� ��� ��Ʈ�� ����
//		template <typename U>
//		friend ostream& operator<< (ostream& os, const Graph<U>& G) {
//			for (unsigned i = 1; i < G.vertices(); i++) {
//				os << i << ":\t";
//				vector<Edge<T>> edges = G.edges(i);
//				for (auto& e : edges)
//					os << "{" << e.dst << ": " << e.weight << "}, ";
//
//				os << endl;
//			}
//
//			return os;
//		}
//	};
//
//}
//
//template <typename T>
//auto welsh_powell_coloring(const welsh_powell::Graph<T>& G) {
//	unsigned size = G.vertices();
//	vector<pair<unsigned, size_t>> degrees;  // ����
//
//	// �� ������ ������ <���� ID, ����>�� ������ ����
//	for (unsigned i = 1; i < size; i++)
//		degrees.push_back(make_pair(i, G.edges[i].size()));
//
//	// ������ ������ �������� �������� ����
//	std::sort(degrees.begin(), degrees.end(), [](const auto& a, const auto& b) {
//		return a.second > b.second;
//		});
//
//	cout << "[���� ���� ���� (��ȣ�� ����)]" << endl;
//	for (auto const i : degrees)
//		cout << i.first << " (" << i.second << ")" << endl;
//
//	vector<unsigned> assigned_colors(size);
//	int color_to_be_assigned = 1;
//
//	while (true) {
//		for (auto const i : degrees) {
//			// �̹� ��ĥ�������� ���� ���� �˻�
//			if (assigned_colors[i.first] != 0) continue;
//
//			auto outgoing_edges = G.edges(i.first);
//
//			// i��° ������ �������ִ� �������� ���� ����
//			set<unsigned> neighbours;
//
//			for (auto& e : outgoing_edges)
//				neighbours.insert(assigned_colors[e.dst]);
//
//
//			// i��° ������ ������ ������ color_to_be_assigned ������ ������ ���� �ʴٸ�
//			// i��° ������ color_to_be_assigned ������ �����Ѵ�.
//			if (neighbours.find(color_to_be_assigned) == neighbours.end())
//				assigned_colors[i.first] = color_to_be_assigned;
//		}
//
//		color_to_be_assigned++;
//
//		// ��� ������ ĥ���������� ����
//		if (std::find(assigned_colors.begin() + 1, assigned_colors.end(), 0) == assigned_colors.end())
//			break;
//	}
//
//	return assigned_colors;
//}
//
//template <typename T>
//void print_colors(vector<T>& colors) {
//	for (auto i = 1; i < colors.size(); i++)
//		cout << i << ": " << color_map[colors[i]] << endl;
//}
//
//void welsh_powell_test() {
//	using T = unsigned;
//
//	// �׷��� ��ü ����
//	welsh_powell::Graph<T> G(9);
//
//	map<unsigned, vector<pair<unsigned, T>>> edge_map;
//	edge_map[1] = { {2, 0}, {5, 0} };
//	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
//	edge_map[3] = { {4, 0}, {7, 0} };
//	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
//	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
//	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
//	edge_map[7] = { {3, 0}, {6, 0} };
//	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };
//
//	for (auto& i : edge_map)
//		for (auto& j : i.second)
//			G.add_edge(welsh_powell::Edge<T>{i.first, j.first, j.second});
//
//	cout << "[�Է� �׷���]" << endl;
//	cout << G << endl;
//	
//	vector<unsigned> colors = welsh_powell_coloring<T>(G);
//	cout << "[�׷��� �÷���]" << endl;
//	print_colors(colors);
//}