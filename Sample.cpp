/*
// �����ڰ� �ۼ��� Ŭ����
class Sample {
	int a;
public:
	void setA(int x) {
		this->a = x;
	}
};


// �����Ϸ��� ���� ��ȯ�� Ŭ����
class Sample {
	int a;
public:
	void setA(Sample* this, int x) {
		this->a = x;
	}
};

int main() {
	Sample obj;
	obj.setA(5) => obj.setA(&obj, 5);
}
*/