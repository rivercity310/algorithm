#include <iostream>
#include <cstring>
using namespace std;


/*
���ڿ� a���� ���� c�� ã��, ���� c�� �ִ� ������ ���� ������ �����ϰ� success�� true ����
���� c�� ã�� �� ���ٸ� success ���� �Ű� ������ false�� ����
*/
char& find(char* a, char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}

	success = false;
	return a[c];
}

void Ex6() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);

	if (!b) {
		cout << "M�� �߰��� �� ����" << endl;
		return;
	}
	loc = 'S';
	cout << s << endl;
}