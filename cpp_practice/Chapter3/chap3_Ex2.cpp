#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
��¥�� �ٷ�� Date Ŭ���� �ۼ�
*/

class Date {
private:
	int year, month, day;
public:
	Date(int y, int m, int d);
	Date(string f);
	void show();

	int getYear() { return this->year; }
	int getMonth() { return this->month; }
	int getDay() { return this->day; }
};

Date::Date(int y, int m, int d) {
	this->year = y;
	this->month = m;
	this->day = d;
}

// 1945/8/15 ���� ���·� �Է�
Date::Date(string f) {
	/*
	string Ŭ�������� ��ũ����¡ ����� �Լ��� ����..
	cstring ����� �ִ� strtok_s�� ����Ͽ� ���ڿ��� �и��ϵ��� ����
	char** context�� �ڸ��� ���� ���ڿ��� �����Ѵ�.

	[ ��ȯ ���� ] 
	1. string�� char[]�� ��ȯ: strcpy(char* destination, char* source)
	2. char[]�� strtok���� �߶�: strtok_s(char* str, const char* delimeters, char** context)
	3. �߶� char[]�� �ٽ� string���� ��ȯ
	4. string �迭�� ����
	*/

	char str_buf[100];
	strcpy_s(str_buf, f.c_str());
	
	char* context = NULL;
	char* tok = strtok_s(str_buf, "/", &context);

	string str_arr[100];
	int str_cur = 0;
	while (tok != NULL) {
		str_arr[str_cur++] = string(tok);
		tok = strtok_s(NULL, "/", &context);
	}

	cout << str_arr[0] << endl;
	cout << str_arr[1] << endl;
	cout << str_arr[2] << endl;

	year = atoi(str_arr[0].c_str());
	month = atoi(str_arr[1].c_str());
	day = atoi(str_arr[2].c_str());
}

void Date::show() {
	cout << year << "�� " << month << "�� " << day << "��" << endl;
}

/*
int main() {
	Date birth(1997, 01, 26);
	Date independencyDay("1945/08/15");
	independencyDay.show();
	birth.show();
}
*/

