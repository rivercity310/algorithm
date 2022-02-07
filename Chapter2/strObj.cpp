#include <iostream>
#include <string>
using namespace std;

void strObj() {
	// 1. �� ���ڿ��� ���� ��Ʈ�� ��ü ����
	string str;

	// 2. address�� ���ڿ��� ������ copyAddress ��Ʈ�� ��ü ����
	string address("����� ����� ��� 1��");
	string copyAddress(address);

	// 3. C-��Ʈ���� ������ ��Ʈ�� ��ü ����
	char text[] = { 'l', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0' };
	string title(text);
	string title2(text, 3);


	// ��Ʈ�� ���
	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
	cout << title2 << endl;     // lov ��� (3���� ����)
	cout << address.size() << endl;
}

void rotateStr() {
	string s;
	cout << "���ڿ� �Է� (�ѱ� X)" << endl;
	getline(cin, s, '\n');
	
	for (int i = 0; i < s.length(); i++) {
		string first = s.substr(0, 1);
		string sub = s.substr(1, s.length() - 1);
		s = sub + first;

		cout << s << endl;
	}
}

void strAdd() {
	string s;
	cout << "���� ���ڿ��� �Է��ϼ���" << endl;
	getline(cin, s, '\n');

	int sum = 0;
	int startIndex = 0;    // ���ڿ� ���� �˻��� ���� �ε���
	while (true) {
		int fIndex = s.find('+', startIndex);   // '+' ���� �˻�
	
		// '+' ���ڰ� ������
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}

		int count = fIndex - startIndex;   // ���꽺Ʈ������ �ڸ� ���� ����
		string part = s.substr(startIndex, count);

		cout << part << endl;
		sum += stoi(part);
		startIndex = fIndex + 1;
	}

	cout << "���ڵ��� ���� " << sum << endl;
}

void replaceStr() {
	string s;
	cout << "���� ���� ���ڿ� �Է�, ���� &����" << endl;
	getline(cin, s, '&');
	cin.ignore();    // '&' �ڿ� ������� <Enter> Ű�� �����ϱ� ���� �ڵ�

	string f, r;
	cout << endl << "find: ";
	getline(cin, f, '\n');   // �˻��� ���ڿ� �Է�
	cout << "replace: ";
	getline(cin, r, '\n');   // ��ġ�� ���ڿ� �Է�

	int startIndex = 0;
	while (true) {
		int fIndex = s.find(f, startIndex);
		if (fIndex == -1) break;

		s.replace(fIndex, f.length(), r);
		startIndex = fIndex + r.length();
	}

	cout << s << endl;
}
