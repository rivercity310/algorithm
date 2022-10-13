#include <iostream>
using namespace std;

class Power {
private:
	int kick;
	int punch;

public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}

	// ���� ������ �ߺ� (��� �Լ��� �ۼ�)
	Power operator+(Power op2) {
		Power tmp;
		tmp.kick = this->kick + op2.kick;
		tmp.punch = this->punch + op2.punch;

		return tmp;
	}

	bool operator==(Power op2) {
		if (this->kick == op2.kick && this->punch == op2.punch) return true;
		else return false;
	}

	Power& operator+=(Power op2) {
		kick += op2.kick;
		punch += op2.punch;

		return *this;		// ��ü �ڽ��� ������ ����
	}

	
	/*
	[ �ܺ� �Լ��� friend�� �����ϴ� ��� ��� �Լ��� �����ϴ� ���ʹ� ���� �ٸ��� (�Ű�����) ]
	friend Power operator+(Power op1, Power op2) {
		Power tmp;
		tmp.kick = op1.kick + op2.kick;
		tmp.punch = op1.punch + op2.punch;

		return tmp;
	}
	*/


	// ���� ������ �ߺ� (����, ������ ���� �ٸ� ����), ������ �Ű����� ����
	// ���� ������ �ߺ�
	Power& operator++() {
		kick++;
		punch++;

		return *this;
	}

	Power& operator--() {
		kick--;
		punch--;

		return *this;
	}

	/*
	friend Power& operator++(Power& op) {
		op.kick++;
		op.punch++;

		return op;
	}
	*/

	bool operator!() {
		if (kick == 0 && punch == 0) return true;
		else return false;
	}


	// ���� ������ �ߺ� (�Ű����� x���� �ǹ̾��� ���� ���޵ǹǷ� ����, ���� ������ ����)
	Power operator++(int x) {       
		Power tmp = *this;		// ���� ���¸� �����س��� ������Ŵ
		kick++;
		punch++;

		return tmp;
	}

	Power operator--(int x) {
		Power tmp = *this;
		kick--;
		punch--;

		return tmp;
	}

	/*
	friend Power& operator++(Power& op, int x) {
		Power tmp = op;
		op.kick++;
		op.punch++;

		return tmp;
	}
	*/


	friend Power& operator<<(Power& op, int n) {
		op.kick += n;
		op.punch += n;

		return op;
	}


	void to_string() {
		cout << "(" << kick << ", " << punch << ")" << endl;
	}
};

void operator_overloading() {
	Power a(1, 2), b(3, 4);
	Power c = a + b;
	c.to_string();

	Power d = c;
	if (d == c) cout << "����" << endl;
	else cout << "�ٸ�" << endl;

	Power e = c += d;
	e.to_string();

	Power f = ++e;
	f.to_string();

	f++;
	f.to_string();

	f--;
	f.to_string();

	Power k;
	k << 1 << 2 << 3 << 4 << 5;
	k.to_string();
}