#ifndef CIRCLE_H
#define CIRCLE_H

// �߻�Ŭ���� Circle
class Circle {
private:
	int radius;
public:
	Circle();
	~Circle();
	void setRadius(int radius);
	double getArea();
};

#endif