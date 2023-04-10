#include<iostream>
using namespace std;

class Dept {
    int size; // scores �迭�� ũ�� 
    int* scores; // ���� �Ҵ� ���� ���� �迭�� �ּ� 
public:
    Dept(int size) { // ������ 
        this->size = size;
        scores = new int[size];
    }
    //Dept(Dept& dept); // ���� ������ 
    ~Dept(); // �Ҹ��� 
    int getSize() { return size; }
    void read(); // size ��ŭ Ű���忡�� ������ �о� scores �迭�� ���� 
    bool isOver60(int index); // index�� �л��� ������ 60���� ũ�� true ���� 
};

int countPass(Dept& dept) { // dept �а��� 60�� �̻����� ����ϴ� �л��� �� ���� 
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) count++;
    }
    return count;
}

/*
Dept::Dept(Dept& dept) {
    this->size = dept.size;
    this->scores = new int[this->size];
    for (int i = 0; i < this->size; i++) {
        this->scores[i] = dept.scores[i];
    }
}
*/

Dept::~Dept() {
    delete[] scores;
}

void Dept::read() {
    cout << size << "�� ���� �Է�>> ";
    for (int i = 0; i < size; ++i) {
        cin >> scores[i];
    }
}
bool Dept::isOver60(int index) {
    if (scores[index] > 60)
        return true;
    else
        return false;
}

void Ex12() {
    Dept com(10); // �� 10���� �ִ� �а� com 
    com.read();  // �� 10���� �л����� ������ Ű����κ��� �о� scores �迭�� ���� 
    int n = countPass(com); // com �а��� 60�� �̻����� ����� �л��� ���� ���� 
    cout << "60�� �̻��� " << n << "��";
}
