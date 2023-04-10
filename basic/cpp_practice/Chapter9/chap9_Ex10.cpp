#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class UI { // ȭ�� ��� �� Ű �Է� �Լ�
    static int n; // ���� ����� ���� �Է� ���� ����
public:
    static void start(); // ù�ٿ� ������ �׷��� ������ �Դϴ� ���
    static int menu(); // ���� ���� ��κ��� ����
    static int insert(); // ���� ����
    static int del(); // ���� ����
};

int UI::n = 0;
void UI::start() {
    cout << "�׷��� �������Դϴ�." << endl;
}
int UI::menu() { // �޴� ��� �� �Է�
    cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
    cin >> n;
    return n;
}
int UI::insert() { // ���� ���Կ� ���� �޴� ��� �� �Է�
    cout << "��:1, ��:2, �簢��:3 >> ";
    cin >> n;
    return n;
}
int UI::del() { // ���� ������ ���� �޴� ��� �� �Է�
    cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
    cin >> n;
    return n;
}

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	void paint() {
		draw();
	}
	Shape* getNext() { return next; }
	void setNext(Shape* p) { this->next = p->next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class GraphicEditor {
private:
	int node_size;
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() {
		pStart = pLast = NULL;
		node_size = 0;
	}

	void run() {
		UI::start();

		while (true) {
			int num = UI::menu();

			switch (num) {
			case 1:
				num = UI::insert();
				insertShape(num);
				break;
			case 2:
				if (node_size == 0) {
					cout << "List Empty!!!" << endl;
				}
				else {
					num = UI::del();
					del(num);
				}
				break;
			case 3:
				show();
				break;
			case 4:
				exit(0);
			default:
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
			}
		}
	}

	void insertShape(int num) {
		switch (num) {
		case 1:
			if (node_size == 0) {
				pStart = new Line();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Line());

			node_size++;
			break;
		case 2:
			if (node_size == 0) {
				pStart = new Rect();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Rect());

			node_size++;
			break;
		case 3:
			if (node_size == 0) {
				pStart = new Circle();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Circle());

			node_size++;
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			return;
		}
	}

	void del(int num) {
		Shape* p = pStart;
		Shape* del = pStart;
		
		if (node_size > num) {
			for (int i = 0; i < num; i++) {
				p = del;
				del = del->getNext();
			}

			if (num == 0) pStart = p->getNext();
			else p->setNext(del);

			node_size--;
			if (node_size == 1) pLast = pStart;
			delete del;
		}
		else cout << "�߸��� �ε����Դϴ�.." << endl;
	}

	void show() {
		Shape* p = pStart;
		for (int i = 0; i < node_size; i++) {
			cout << i << " : ";
			p->paint();
			p = p->getNext();
		}
	}
};

void chap9_Ex10() {
	GraphicEditor* g_editor = new GraphicEditor();
	//g_editor->run();
	 
	cout << 47 * 11 + 543 << endl;
	delete g_editor;
}