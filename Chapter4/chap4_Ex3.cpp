#include <iostream>
#include <string>

using namespace std;

/*
string Ŭ������ �̿��Ͽ� ��ĭ�� �����ϴ� ���ڿ��� �Է¹ް�, ���ڿ����� 'a'�� ������ ����ϴ� ���α׷� �ۼ�
*/

void Ex3() {
	string inputStr;
	cout << "���ڿ� �Է�: ";
	getline(cin, inputStr, '\n');

	int startIndex = 0;
	int count = 0;
	while (true) {
		int fIndex = inputStr.find('a', startIndex);
		if (fIndex == -1) break;
		
		startIndex = fIndex + 1;
		count++;
	}

	cout << "a�� ������ " << count << endl;
}