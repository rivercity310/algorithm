#include <iostream>

class Shape {
	Shape* next;
protected:
	virtual void draw();
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
};

void Shape::paint() {
	draw();       // ���� ���ε�
}

void Shape::draw() {
	std::cout << "-- Shape -- " << std::endl;
}

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}


class Circle : public Shape {
protected:
	virtual void draw() { std::cout << "Circle" << std::endl; }
};

class Rect : public Shape {
protected:
	virtual void draw() { std::cout << "Rect" << std::endl; }
};

class Line : public Shape {
protected:
	virtual void draw() { std::cout << "Line" << std::endl; }
};


void chap9_Shape() {
	Shape* pStart = NULL;
	Shape* pLast;

	pStart = new Circle();     // ó���� �� ���� ����
	pLast = pStart;

	pLast = pLast->add(new Rect());
	pLast = pLast->add(new Circle());
	pLast = pLast->add(new Line());
	pLast = pLast->add(new Rect());

	// ����� ��� ������ ȭ�鿡 �׸���
	Shape* p = pStart;
	while (p != NULL) {
		p->paint();
		p = p->getNext();
	}

	// ���� ����� ��� ������ �����Ѵ�
	p = pStart;
	while (p != NULL) {
		Shape* q = p->getNext();    // ���� ���� �ּ� ���
		delete p;      // �⺻ Ŭ������ ���� �Ҹ��� ȣ��
		p = q;
	}
}