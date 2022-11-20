#include <iostream>
#include <vector>
using namespace std;

/*
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

enum class city : int {
	LONDON, PARIS, SEOUL, CALIFORNIA, NEWYORK
};

ostream& operator<<(ostream& os, const city c) {
	switch (c) {
	case city::LONDON:
		os << "London";
		return os;
	case city::PARIS:
		os << "Paris";
		return os;
	case city::SEOUL:
		os << "Seoul";
		return os;
	case city::CALIFORNIA:
		os << "California";
		return os;
	case city::NEWYORK:
		os << "Newyork";
		return os;
	default:
		return os;
	}
}

class adj_mat_grp {
	vector<vector<int>> data;

	void setEdge(const city& c1, const city& c2, int weight) {
		int n1 = static_cast<int>(c1);
		int n2 = static_cast<int>(c2);

		data[n1][n2] = weight;
		data[n2][n1] = weight;
	}

public:
	adj_mat_grp(int n) {
		data.reserve(n);

		vector<int> v(n);
		fill(v.begin(), v.end(), -1);

		for (int i = 0; i < n; i++) data.push_back(v);
	}

	void addEdge(const city& c1, const city& c2, int weight) {
		cout << c1 << " <--> " << c2 << "�� ������ �߰��մϴ�: " << weight << endl;
		setEdge(c1, c2, weight);
	}

	void removeEdge(const city& c1, const city& c2) {
		cout << c1 << " <-X-> " << c2 << "�� ������ �����մϴ�." << endl;
		setEdge(c1, c2, -1);
	}

	void prt_data() {
		for (vector<int> i : data) {
			for (int j : i)
				cout << setw(5) << left << j;
			cout << endl;
		}
	}
};

int main() {
	auto g = new adj_mat_grp(6);

	g->addEdge(city::CALIFORNIA, city::SEOUL, 8000);
	g->addEdge(city::CALIFORNIA, city::LONDON, 4000);
	g->addEdge(city::CALIFORNIA, city::PARIS, 5500);
	g->addEdge(city::LONDON, city::SEOUL, 4500);
	g->addEdge(city::LONDON, city::PARIS, 1000);
	g->addEdge(city::NEWYORK, city::CALIFORNIA, 2500);

	g->prt_data();

	g->removeEdge(city::CALIFORNIA, city::LONDON);

	g->prt_data();

}
*/


enum class city : int {
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(ostream& os, const city c) {
	switch (c) {
	case city::LONDON:
		os << "����";
		return os;
	case city::MOSCOW:
		os << "��ũ��";
		return os;
	case city::SEOUL:
		os << "����";
		return os;
	case city::SEATTLE:
		os << "�ÿ�Ʋ";
		return os;
	case city::DUBAI:
		os << "�ι���";
		return os;
	case city::SYDNEY:
		os << "�õ��";
		return os;
	default:
		return os;
	}
}

// ���� �����͸� ������ graph ����ü ����
struct adj_mat_graph {
	vector<vector<int>> data;

	// �־��� ������ ���� ������ �׷����� �����ϴ� ������ �߰�
	adj_mat_graph(int n) {
		data.reserve(n);	// n��ŭ�� �뷮�� �̸� Ȯ���ص� -> vector�� ���Ҵ� ����
		vector<int> row(n);
		fill(row.begin(), row.end(), -1);

		for (int i = 0; i < n; i++)
			data.push_back(row);
	}

	// ������ �߰��ϴ� �Լ�, �ΰ��� ���ÿ� ����ġ�� ���ڷ� ����
	void addEdge(const city c1, const city c2, int dis) {
		cout << "���� �߰�: " << c1 << " - " << c2 << " = " << dis << endl;

		int n1 = static_cast<int>(c1);
		int n2 = static_cast<int>(c2);

		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}

	// ������ �����ϴ� �Լ�
	void removeEdge(const city c1, const city c2) {
		cout << "���� ����: " << c1 << " - " << c2 << endl;

		int n1 = static_cast<int>(c1);
		int n2 = static_cast<int>(c2);

		data[n1][n2] = -1;
		data[n2][n1] = -1;
	}

	void prt_graph() {
		cout << endl;
		for (auto i : data) {
			for (auto j : i)
				printf("%-10d", j);
			cout << endl;
		}

		cout << endl;
	}
};

void chap2_adj_matrix_graph() {
	adj_mat_graph g(6);

	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.prt_graph();

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	g.prt_graph();
}