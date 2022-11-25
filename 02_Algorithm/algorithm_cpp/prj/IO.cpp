#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// ��� ���� ostream Ŭ����
void ostream_ex() {
	cout.put('A');
	cout.put(97);     // a

	cout.put('C').put('+').put('+');       // ������ �����ϹǷ� �޼��� ü�̴� ����

	char str[] = "I Love C++ Programming";
	cout.write(str, 6);                     // str���� n�� ��� -> I Love ���

	cout.flush();                           // ���ۿ� �ִ� ���� ���� ���
}


// �Է� ���� istream Ŭ����
void istream_ex() {
	// ���� �б�

	// 01. int get()
	int ch;
	while ((ch = cin.get()) != EOF) {		// get(): �Է� ��Ʈ������ ���ڸ� �о� ����
		cout.put(ch);
		if (ch == '\n') break;
	}

	// 02. istream& get(char& ch)
	char c;
	while (true) {
		cin.get(c);   // Ű�� c�� �о��
		if (cin.eof()) break;

		cout.put(c);
		if (c == '\n') break;
	}




	// ���ڿ� �б�
	
	// 01. istream& get(char* s, int n)
	// �Է� ��Ʈ������ n - 1���� ���ڸ� �о� s�� ���� �������� '\0' ����
	char cmd[80];
	while (true) {
		cin.get(cmd, 80);
		if (strcmp(cmd, "exit") == 0) break;
		
		cin.ignore(1);         // ���ۿ� �����ִ� '\n' ���� (���ѷ��� ����)
	}
	cout << cmd << endl;


	// 02. ���� �б� 
	// istream& get(char* s, int n, char delim='\n')
	// istream& getline(char* s, int n, char delim='\n')   -> delim�� ������ ���� ���ڸ� ��Ʈ������ ����

	char line[80];
	cin.getline(line, 80);   // getline �Լ��� '\n'�� ��Ʈ�� ���ۿ��� �������ֱ� ������ ignore() ���ص� ��
	cout << line << endl;
}




/*
[ C++�� ���� ����� ���� ����� ���� �������� �ִ�. ]
- ���� �÷���
- ���� �Լ�
- ������
*/

// ios -> ����� �ֻ��� ��ü
// �����÷��� -> ios ��ü ���� ����� ���ǵ�
void formatflag_ex() {
	cout << 30 << "\n";			// 10���� ���
	
	cout.unsetf(ios::dec);		// 10���� ����
	cout.setf(ios::hex);		// 16���� ����
	cout << 30 << "\n";

	cout.setf(ios::showbase);	// 16������ 0x���ξ� ���̵��� ����
	cout << 30 << "\n";

	cout.setf(ios::uppercase);	// 16������ A~F�� �빮�ڷ� ���
	cout << 30 << "\n";

	// ��Ʈ OR �������� ���ÿ� 2�� ���� ����
	cout.setf(ios::dec | ios::showpoint);   // 10���� ǥ���� ���ÿ� �Ǽ��� �Ҽ��� ���� ������ 0���� ���
	cout << 23.5 << "\n";

	cout.setf(ios::scientific);		// �Ǽ��� ���л���� ǥ������ ���
	cout << 23.5 << "\n";

	cout.setf(ios::showpos);		// ����� ��� + ��ȣ�� �Բ� ���
	cout << 23.5 << endl;
}

void format_function_ex() {
	cout.width(10);				// ���� 1ȸ ����� �ʺ� 10ĭ���� ���� ( << �����ڿ��� ��ȿ )
	cout << "Hello" << "\n";

	cout.fill('-');				// ��ĭ�� '-' ���ڷ� ä��
	cout.width(10);
	cout << "Hello" << "\n";		

	cout.precision(5);			// ��µǴ� ������ �ڸ����� 5�� ���� (�ݿø�)
	cout << 11. / 3. << "\n";

}

// �����ڸ� �̿��� ����� ���� ���� ���
void manipulator_ex() {
	/*
	[ ������ : �뵵 ]

	01. �Ű������� ���� ������
	- endl : ��Ʈ�� ���۸� ��� ���(flush)�ϰ� ���� �ٷ� �ѱ�
	- oct : ���� �ʵ带 8���� ������� ���
	- dec : ���� �ʵ带 10���� ������� ���
	- hex : ���� �ʵ带 16���� ������� ���
	- left : ���� �������� ���
	- right : ������ �������� ���
	- fixed : �Ǽ� �ʵ带 ���� �Ҽ��� ������� ���
	- scientific : �Ǽ� �ʵ带 ���� ����� ������� ���
	- flush : ��Ʈ�� ���� ���� ���
	- showbase : 16������ ��� 0x, 8������ ��� 0�� �տ� �ٿ� ���
	- noshowbase : showbase ���� ���
	- showpoint : �Ǽ����� ����, ���� �κа� �Ҽ��� ������ ���ڸ� ���� ���� ���� 0���� ä���� ���
	- noshowpoint : showpoint ���� ���
	- showpos : ����� ��� + ��ȣ�� �ٿ� ���
	- skipws : �Է� ��Ʈ������ ���� ���ڸ� ���� �ʰ� �ǳ� ��
	- noskipws : skipws ���
	- boolalpha : �Ҹ� ���� ���ڿ� "true", "false"�� ���

	02. �Ű������� ������ ������ -> iomanip ������Ͽ� ����
	- setw(n) : ��� �ʺ� n���� ����
	- setfill(c) : ����� c�� ä���� ���
	- resetioflags(flags) : flags�� ������ �÷��׵� ����
	- setbase(base) : base�� ����� ���� ������ ����
	- setioflags(flags) : flags�� ��Ʈ�� ����� �÷��׷� ����
	- setprecision(n) : ��µǴ� ���� ��ȿ ���� �ڸ����� n���� ����
	- 
	*/


	cout << hex << showbase << 30 << "\n";
	cout << dec << showpos << 100 << "\n";
	cout << true << " " << false << "\n";
	cout << boolalpha << true << " " << false << endl;

	cout << endl;

	cout << showbase;
	cout << setw(8) << "Number";
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;

	for (int i = 0; i < 50; i += 5) {
		cout << setw(8) << setfill('.') << dec << i;
		cout << setw(10) << setfill(' ') << oct << i;
		cout << setw(10) << setfill(' ') << hex << i << endl;
	}
}