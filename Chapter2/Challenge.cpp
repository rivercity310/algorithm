#include <iostream>
#include <string>

using namespace std;

void rsp() {

	cout << "���� ���� �� ������ �մϴ�. ";
	cout << "����, ����, �� �߿��� �Է��ϼ���." << endl;

	string p1;
	string p2;
	cout << "�ι̿�: ";
	getline(cin, p1);

	cout << "�ٸ���: ";
	getline(cin, p2);

	int r = p1 == "����" ? 0 : p1 == "����" ? 1 : 2;
	int j = p2 == "����" ? 0 : p2 == "����" ? 1 : 2;

	if (r == j) cout << "�����ϴ�" << endl;
	else if ((r == 0 && j == 1) || (r == 1 && j == 2) || (r == 3 && j == 0)) cout << "�ٸ��� �¸�" << endl;
	else cout << "�ι̿� �¸�" << endl;
}
