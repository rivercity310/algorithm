//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//#include <algorithm>
//
//#include "graph_and_edge.h"
//#include "disjoint_set.h"
//
//
//// Ʈ���� �׷����� ǥ���� �� �����Ƿ� �ּ� ���� Ʈ���� Graph ��ü�� ��ȯ
//// ��, ����Ŭ�� �����ϸ� �ȵ�
//template <typename T>
//Graph<T> minimum_spanning_tree(const Graph<T>& G) {
//	// ���� ����ġ�� �̿��� �ּ� �� ����
//	priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> edge_min_heap;
//
//	// ��� ������ �ּ� ���� �߰�
//	for (const Edge<T>& e : G.edges())
//		edge_min_heap.push(e);
//
//	// ���� ������ �ش��ϴ� ũ���� ������Ʈ-�� �ڷᱸ�� ���� �� �ʱ�ȭ
//	unsigned N = G.vertices();
//	SimpleDisjointSet dset(N);
//	for (unsigned i = 0; i < N; i++)
//		dset.make_set(i);
//
//	auto t = dset.get_forest();
//	cout << "id\trank\tparent" << endl;
//	for (auto n : t) cout << n.id << "\t" << n.rank << "\t" << n.parent << endl;
//
//	// ������Ʈ-�� �ڷᱸ���� �̿��Ͽ� �ּ� ���� Ʈ�� ���ϱ�
//	Graph<T> MST(N);
//	
//	while (!edge_min_heap.empty()) {
//		// �ּ� ������ �ּ� ����ġ�� ���� ���� ����
//		Edge<T> e = edge_min_heap.top();
//		edge_min_heap.pop();
//
//		// ������ ������ ����Ŭ�� �������� ������ �ش� ������ MST�� �߰�
//		if (dset.find(e.src) != dset.find(e.dst)) {
//			MST.add_edge(Edge<T>{e.src, e.dst, e.weight});
//			dset.union_sets(e.src, e.dst);
//		}
//	}
//
//	return MST;
//}
//
//// �׽�Ʈ �Լ�
//void mst_test() {
//	using T = unsigned;
//
//	// �׷��� ��ü ����
//	Graph<T> G = create_reference_graph2<T>();
//
//	cout << "[�Է� �׷���]" << endl;
//	cout << G << endl;
//
//	Graph<T> MST = minimum_spanning_tree(G);
//	cout << "\n\n[�ּ� ���� Ʈ��]" << endl;
//	cout << MST << endl;
//}