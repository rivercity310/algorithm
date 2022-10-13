#include <iostream>

using namespace std;

void swapWithCallByValue(int a, int b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void swapWithCallByAddress(int *a, int *b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void swapWithCallByReference(int& a, int& b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void callBy() {
	int m = 2, n = 9;
	swapWithCallByValue(m, n);
	cout << m << ", " << n << endl;        // ���� ����Ǿ� ���޵ǹǷ� ���ҵ��� ����

	swapWithCallByAddress(&m, &n);
	cout << m << ", " << n << endl;        // ���ּҸ� �����Ͽ����Ƿ� ���� ���ҵ�

	swapWithCallByReference(m, n);         // ������ ���� ȣ��
	cout << m << ", " << n << endl;
}




/*
// ���� ���� ȣ��, �Ҹ��ڸ� �����
void increase1(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);         // ���� ��ü�� ������ ������ ����
}

// ������ ���� ȣ��, ������ �Ҹ��� ����X
void increase2(Circle& c) {
	int r = c.getRadius();
	c.setRadius(r + 1);         // c�� �����ϴ� ���� ��ü�� ������ 1 ����
}
*/


/*
char c = 'a';

char get() {
	return c;
}

char& find() {        // char Ÿ���� ���� ����
	return c;         // ���� c�� ���� ���� ����
}

void referenceReturn() {
	find() = 'b';       // c = 'b'�� ��
}
*/



char& find(char s[], int idx) {
	return s[idx];
}

void referenceReturn() {
	char name[] = "Seungsu";
	cout << name << endl;

	find(name, 0) = 'K';
	cout << name << endl;

	char& ref = find(name, 2);   // ref�� name[2]�� ���� ����
	ref = 't';
	cout << name << endl;
}

/*
[ ��� ]
Seungsu
Keungsu
Ketngsu
*/