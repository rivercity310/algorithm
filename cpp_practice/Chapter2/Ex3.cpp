#include <iostream>
#include <string>
using namespace std;

/*
1. <Enter>Ű�� �Էµ� ������ ���ڵ��� �а�, �Էµ� ���� 'x'�� ������ ���
2. ���ڿ� �ΰ��� �Է¹ް� ������ �����ϴ�, �ٸ��� �ٸ��ϴ� ���
*/

void checkX() {
	cout << "���ڵ��� �Է��϶� (100�� �̸�)\n";
	char buf[100];
	cin.getline(buf, 100, '\n');

	int count = 0;
	for (int i = 0; i < 100; i++) 
		if (buf[i] == 'x') count++;
	
	cout << "x�� ������ " << count << endl;
}

void inputStr() {
	string str1;
	cout << "�� ��ȣ�� �Է��ϼ���: ";
	getline(cin, str1);

	string str2;
	cout << "�� ��ȣ�� �ٽ� �ѹ� �Է��ϼ���: ";
	getline(cin, str2);

	if (str1 == str2) cout << "�����ϴ�.\n";
	else cout << "�ٸ��ϴ�.\n";
}