#ifndef COFFEE_VENDING_MACHINE
#define COFFEE_VENDING_MACHINE

#include "Container.h"

class CoffeeVendingMachine {
private:
	Container* tank;         // tank[0]�� ����, tank[1]�� ��, tank[2]�� ������
	void fill();               // 3�� �� ��� 10���� ä���
	void checkTank(int selected);          // ���� �뷮 üũ�ϱ�
	void selectEspresso();     // ����������: Ŀ�� 1, �� 1
	void selectAmericano();    // �Ƹ޸�ī��, Ŀ�� 1, �� 2
	void selectSugarCoffee();  // ����Ŀ��, Ŀ�� 1, �� 2, ���� 1
	void show();               // ���� Ŀ��, ��, ���� �ܷ� ���
public:
	CoffeeVendingMachine();
	void run();                // Ŀ�� ���Ǳ� �۵�
};


#endif