#include <iostream>
#include <cstring>

using namespace std;

/*
�� ���ο� ';'�� �������� 5���� �̸��� �����Ͽ� �Է¹޾�,
�� �̸��� ����� ȭ�鿡 ����ϰ� ���� �� �̸��� �Ǻ��϶�.

C-��Ʈ�� ���
- strlen
- strcopy_s
- cin.getline
*/

void nameInput() {
	cout << "5���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl;
	char name[100];
	char longName[100];
	
	int A = 0;
	for (int i = 0; i < 5; i++) {
		cin.getline(name, 100, ';');
		cout << i + 1 << " : " << name << endl;

		if (A <= strlen(name)) {
			A = strlen(name);
			strcpy_s(longName, name);
		}
	}

	cout << "���� �� �̸��� " << longName;
}
