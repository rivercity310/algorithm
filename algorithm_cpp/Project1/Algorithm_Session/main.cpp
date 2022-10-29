#define MAIN
#define DAY1
#define BS
#define DAY2
#define DAY3

#ifdef MAIN
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <iostream>
#include <stack>
using namespace std;
#endif

#ifdef DAY1
#endif

#ifdef BS
extern void boj_1620();			// ���¾� ���ϸ� ������ �̴ټ�
extern void boj_2504();			// * ���ذ�
#endif

#ifdef DAY2
extern void boj_9012();			// ��ȣ ���ڿ�
extern void boj_1541();			// �Ҿ���� ��ȣ
#endif

#ifdef DAY3
extern void boj_1874();			// ���� ����
#endif

int main() {
	FAST_IO;
	
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

		if (stk.top() != k) {
			cout << "NO";
			exit(0);
		}

		ans += "-\n";
		stk.pop();
	}

	cout << ans;
}