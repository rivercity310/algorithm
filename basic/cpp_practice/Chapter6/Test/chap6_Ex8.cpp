#include <iostream>
#include <string>
using std::string;

class Trace {
	static string log;
public:
	static void put(string tag, string info);
	static void print(string tag = "none");
};

string Trace::log = "";
void Trace::put(string tag, string info) {
	log.append(tag + "\t" + info + "\n");
}

void Trace::print(string tag) {
	string msg, newlog = ""; //= tag == "none" ? "��� Trace ������ ����մϴ�." : tag + " �±��� Trace ������ ����մϴ�.";
	
	if (tag == "none") {
		msg = "��� Trace ������ ����մϴ�.";
		newlog = log;
	}
	else {
		msg = tag + " �±��� Trace ������ ����մϴ�.";
		
		string delimiter = "\n";

		// ��ȣ���� ���� �ڷ��� (unsigned int)
		size_t pos = 0;
		string token;
		while ((pos = log.find(delimiter)) != string::npos) {
			token = log.substr(0, pos);
			std::cout << token << std::endl;
			log.erase(0, pos + delimiter.length());
		}

		std::cout << log << std::endl;
	}
	
	std::cout << "------- " << msg << " -------" << std::endl;
	std::cout << newlog << std::endl;
}

void f() {
	int a, b, c;
	std::cout << "�� ���� ������ �Է��ϼ���: ";
	std::cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");    // ����� ���� ����
	c = a + b;
	Trace::put("f()", "�� ���");
	std::cout << "���� " << c << std::endl;
}

void chap6_Ex8() {
	Trace::put("main()", "���α׷��� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::print("f()");  // "f()" �±׸� ���� ����� ������ ��� ����Ѵ�.
	Trace::print();      // ��� ����� ������ ����Ѵ�.
}