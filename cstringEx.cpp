#include <iostream>
#include <cstring>

using namespace std;

/*
��Ȯ�� ��ȣ�� �Է¹����� �����ϴ� ���α׷�
*/

void correctPassword() {
	char password[11];     // ���� 10��, �ѱ� 5�� ���� ����
	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���" << endl;
	
	while (true) {
		cout << "��ȣ: ";
		cin.getline(password, 11);

		// strcmp: �־��� �� ���ڿ��� ������ ��, ������ 0�� return�Ѵ�. 
		if (strcmp(password, "C ++") == 0) {
			cout << "���α׷��� ���� �����մϴ�." << endl;
			break;
		}
		else {
			cout << "��ȣ�� Ʋ���ϴ�!" << endl;
		}
	}
}