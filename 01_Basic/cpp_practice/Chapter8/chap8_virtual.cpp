#include <iostream>

class BaseIO {
public:
	int mode;
};

class In : virtual public BaseIO {
public:
	int readPos;
};

class Out : virtual public BaseIO {
public:
	int writePos;
};

class InOut : public In, public Out {
public:
	bool safe;
};

void chap8_virtual() {
	InOut ioObj;

	// mode�� �ϳ��̹Ƿ� ��ȣ�� �ذ�
	ioObj.mode = 10;    
}