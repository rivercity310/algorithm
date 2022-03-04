#pragma once

class GameObject {
protected:
	int distance;    // �ѹ� �̵��Ÿ�
	int x, y;        // ���� ��ġ ��ǥ
public:
	GameObject(int startX, int startY, int distance);
	
	virtual ~GameObject();
	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX();
	int getY();
	bool collide(GameObject* p);
};