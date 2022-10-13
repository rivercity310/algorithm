#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

void chap10_lambda() {
	auto love = [](string a, string b) {
		cout << a << "���� " << b << "�� ����" << endl;
	};

	love("��", "��");
	love("�ø�", "����");
}

// ���� ���� pi�� ���� ĸ�� ����Ʈ�� �̿��Ͽ� ���ٽĿ��� Ȱ��
void chap10_lambda2() {
	double pi = 3.14;
	auto calc = [pi](int r) -> double {return pi * r * r; };

	cout << "������ " << calc(3) << endl;
}

// ĸ�� ����Ʈ�� ������ Ȱ���Ͽ� ���� �ܺ� ������ �����ϴ� ���ٽ� �����
void chap10_lambda3() {
	int sum = 0;
	[&sum](int x, int y) {sum = x + y; }(2, 3);
	cout << "���� " << sum << endl;
}

// STL ���ø��� ���ٽ� Ȱ��
void chap10_lambda4() {
	std::vector<int> v = { 1, 2, 3, 4, 5 };

	// for_each()�� ���� v�� ù��° ���Һ��� ������ �˻��ϸ鼭
	// �� ���ҿ� ���� 3��° �Ű� ������ ���ٽ� ȣ��, �Ű� ���� n�� �� ���� �� ����
	std::for_each(v.begin(), v.end(), [](int n) {cout << n << " "; });
}