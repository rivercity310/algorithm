#include <iostream>
#include <stack>

using namespace std;

void boj_1874() {
	
	int n;
	cin >> n;

	stack<int> stk;
	string ans = "";
	int bp = 0;

	while (n--) {
		int k;
		cin >> k;

		if (k > bp) {
			for (int i = bp + 1; i <= k; i++) {
				ans += "+\n";
				stk.push(i);
			}

			bp = k;
		}

		/*
		exit : �ٷ� C ���α׷� ��ü ���μ��� ���� (0 : ��������, 1 : �����޼��� ����)
		return : �� ������ �����ϸ� ����
		*/

		if (stk.top() != k) {
			cout << "NO";
			exit(0);
		}

		ans += "-\n";
		stk.pop();
	}

	cout << ans;
}