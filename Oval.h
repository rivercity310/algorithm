#ifndef OVAL_H
#define OVAL_H

/*
[ �־��� �簢���� �����ϴ� Ÿ���� �߻�ȭ�� Ŭ���� Oval�� ������ ���� ]
- �������� �簢�� �ʺ�� ���̸� ������ width, height
- �ʺ�� ���� ���� �Ű� ������ �޴� ������
- �ʺ�� ���̸� 1�� �ʱ�ȭ�ϴ� �Ű� ���� ���� ������
- width�� height�� ����ϴ� �Ҹ���
- Ÿ���� �ʺ� �����ϴ� getWidth() �Լ� ���
- Ÿ���� ���̸� �����ϴ� getHeight() �Լ� ���
- Ÿ���� �ʺ�� ���̸� �����ϴ� set(int w, int h) �Լ� ���
- Ÿ���� �ʺ�� ���̸� ȭ�鿡 ����ϴ� show() �Լ� ���
*/

class Oval {
private:
	int width, height;
public:
	Oval();
	Oval(int w, int h);
	~Oval();
	int getWidth();
	int getHeight();
	void set(int w, int h);
	void show();
};


#endif