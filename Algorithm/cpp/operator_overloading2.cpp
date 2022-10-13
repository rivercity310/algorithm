#include <iostream>
using namespace std;

class dot {
	int x;
	int y;
public:
	dot(int x = 0, int y = 0) : x(x), y(y) {};

	friend ostream& operator<<(ostream& os, const dot d) {
		os << "(" << d.x << ", " << d.y << ")";
		return os;
	}

	// ���� ������ �Լ����� �ι�° �Ű������� ������ �����ؾ� �Ѵ�.
	friend istream& operator>>(istream& is, dot& d) {
		cout << "x: ";
		is >> d.x;
		cout << "y: ";
		is >> d.y;

		return is;
	}
};

// ����� ������ ����� : �Ű����� os�� cout�� ����
ostream& fivestar(ostream& os) {
	return os << "*****";
}

ostream& rightarrow(ostream& os) {
	return os << "---->";
}

void operator_overloading2() {
	// �Է� ������(<<) �ߺ� ostream& ��ȯ
	dot d(4, 5);
	cout << d << endl;


	// ���� ������(>>) �ߺ� 
	dot f;
	cin >> f;
	cout << f << endl;



	// ����� ���� ������
	cout << fivestar << " C++ " << rightarrow << endl;
}