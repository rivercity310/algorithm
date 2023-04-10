#include <iostream>
using std::string;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		std::cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�." << std::endl;
		std::cout << getSourceString() << " �Է�: ";
		std::cin >> src;
		std::cout << "��ȯ ���: " << convert(src) << getDestString() << std::endl;
	}
};

class WonToDollar : public Converter {
protected:
	double convert(double src);
	string getSourceString() { return "��"; }
	string getDestString() { return "�޷�"; }
public:
	WonToDollar(double ratio) : Converter(ratio) {}
};

double WonToDollar::convert(double src) {
	return src / ratio;
}

void chap9_Ex1() {
	WonToDollar wd(1010);  // 1�޷� = 1010��
	wd.run();
}


class KmToMile : public Converter {
protected:
	double convert(double src);
	string getSourceString() { return "km"; }
	string getDestString() { return "mile"; }
public:
	KmToMile(double ratio) : Converter(ratio) {};
};

double KmToMile::convert(double src) {
	return src / ratio;
}

void chap9_Ex2() {
	KmToMile toMile(1.609344);
	toMile.run();
}