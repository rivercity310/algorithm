#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// ó�� ������ - ������ ���ڵ��� ���� - �� ������ ������ ���ش�.
	string s;
	cin >> s;

	int ans = 0;
	string tmp = "";

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+') {
			ans += stoi(tmp);
			tmp = "";
		}
		else if (s[i] == '-') {
			ans -= stoi(tmp);
			tmp = "";
		}
		else tmp += s[i];
	}
	
	cout << ans;
}