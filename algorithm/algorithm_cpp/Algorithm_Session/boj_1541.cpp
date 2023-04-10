#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
�Ҿ���� ��ȣ
*/

void boj_1541() {
	string s;
	cin >> s;

	istringstream iss(s);
	string buf;
	char sep = '-';
	
	int ans = 0;
	int idx = 0;

	while (getline(iss, buf, sep)) {
		istringstream iss2(buf);
		string buf2;
		char sep2 = '+';

		if (idx == 0)
			while (getline(iss2, buf2, sep2))
				ans += stoi(buf2);
		else
			while (getline(iss2, buf2, sep2))
				ans -= stoi(buf2);
		
		idx++;
	}

	cout << ans;
}