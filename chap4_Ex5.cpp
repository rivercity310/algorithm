#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/*
string Ŭ������ �̿��Ͽ� ���� �� ���� �Է¹ް� ���� �ϳ��� �����ϰ� �����Ͽ� ����ϴ� ���α׷� �ۼ�
*/

char randomAlphabet[26];

void Ex5() {
	// randomAlphabet �ʱ�ȭ
	int index = 0;
	for (char c = 'a'; c <= 'z'; c++) 
		randomAlphabet[index++] = c;

	cout << "�Ʒ��� ���� �� ���� �Է��ϼ��� (exit�� �Է��ϸ� �����մϴ�)" << endl;
	while (true) {
		string inputStr;
		getline(cin, inputStr, '\n');
		if (inputStr == "exit") break;

		srand(time(NULL));
		int randomAlphabetIndex = rand() % 26;
		int randomIndex = rand() % inputStr.size();

		// ���ĺ��� �ƴ� ���ڰ� �ε����� ���� ��� ����
		while (true) {
			char c = inputStr[randomIndex];
			if (isalpha(c) == 1 || isalpha(c) == 2) break;
			
			randomIndex = rand() % inputStr.size();
		}

		cout << "���� ���ĺ� �ε���: " << randomAlphabetIndex << endl;
		cout << "���� �ε���: " << randomIndex << endl;

		inputStr[randomIndex] = randomAlphabet[randomAlphabetIndex];
		cout << inputStr << endl;
	}
}