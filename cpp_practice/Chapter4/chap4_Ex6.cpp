#include <iostream>
#include <string>

using namespace std;

/*
Ex6: string Ŭ������ �̿��Ͽ� ���� �� ���� �Է¹ް� �Ųٷ� ����ϴ� ���α׷� �ۼ�
*/

void Ex6() {
	cout << "���� �� ���� �Է��ϼ���" << endl;
	string input;
	getline(cin, input, '\n');

	/* ȸ���ϴ� ����
	for (int i = 1; i <= input.size(); i++) {
		string first = input.substr(0, i);
		string remains = input.substr(i, input.size());

		string res = remains + first;
		cout << res << endl;
	}
	*/
	
	string res1, res2, res3;
	for (int i = 0; i < input.size(); i++) {
		char k = input[input.length() - i - 1];
		res1.push_back(k);           
		res2.append(1, k);           
		res3.insert(i, 1, k);        
	}

	/*
	[ char -> string ]
	1. push_back()
	2. append()
	3. insert(����(��)�� ���� ��ġ �ε���, �����Ϸ��� ���� ����, char || string)
	*/

	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;
}