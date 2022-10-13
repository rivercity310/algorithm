#include <iostream>
#include <cstring>

using namespace std;
/*
1. ���� 5Ģ ������ �� �� �ִ� ���α׷� �ۼ�
2. ���� �ؽ�Ʈ�� �Է¹޾� ���ĺ� ������׷��� �׸��� ���α׷� �ۼ�
*/

void operation() {
	while (true) {
		cout << "? ";
		int first;
		string oper;
		int second;
		cin >> first >> oper >> second;
		
		int res;
		if (oper == "+") res = first + second;
		else if (oper == "-") res = first - second;
		else if (oper == "*") res = first * second;
		else if (oper == "/") res = first / second;
		else if (oper == "%") res = first % second;
		else {
			cout << "�߸��� �Է��Դϴ�..." << endl;
			continue;
		}

		cout << first << " " << oper << " " << second << " = " << res << endl;
	}
}

void draw() {
	cout << "���� �ؽ�Ʈ�� �Է��ϼ���: ";
	char str[10000];
	cin.getline(str, 10000, ';');
	int alphaCount[26] = { 0, };
	
	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i]) > 0) {     // isalpha: �빮�� 1, �ҹ��� 2, ���ĺ� �ƴ� �� 0
			for (char c = 'a'; c <= 'z'; c++) {
				int k = tolower(str[i]);  // int tolower(int c): �ƽ�Ű �������� ���� ��ȯ 
				if ((char)k == c) alphaCount[k - 97]++;
			}
		}
	}
	
	for (char c = 'a'; c <= 'z'; c++) {
		cout << c << " (" << alphaCount[(int)c - 97] << ") : ";
		for (int i = 0; i < alphaCount[(int)c - 97]; i++) cout << "*";
		cout << endl;
	}
}