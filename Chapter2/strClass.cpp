#include <iostream>
#include <string>    // string Ŭ������ ����ϱ� ���� �������

using namespace std;

/*
�ش� �뷡�� �θ� ������ �̸��� ���� ���α׷� �ڵ�
string���� ���ڿ��� �Է¹ޱ� ���� C++ ǥ�� ���̺귯������ �����ϴ� ���� �Լ�
getline(istream&, string&)�� ����Ͽ���.
*/

void Quiz() {
	string song("Falling in love with you");
	string elvis("Elvis presley");
	string singer;

	cout << song + "�� �θ� ������? ";
	cout << "(��Ʈ: ù���ڴ�" << elvis[0] << ") ";
	getline(cin, singer);

	if (singer == elvis) cout << "����!";
	else cout << "Ʋ�Ƚ��ϴ�. ������ " << elvis + "�Դϴ�." << endl;
}
