#define MAIN

// #define WEEK1
// #define WEEK2
// #define WEEK3
#define WEEK4

#ifdef MAIN
#include <iostream>
#include <vector>
#include <algorithm>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#endif

#ifdef WEEK1
extern void boj_1620();			// ���¾� ���ϸ� ������ �̴ټ�
extern void boj_2504();			// * ���ذ�
extern void boj_9012();			// ��ȣ ���ڿ�
extern void boj_1541();			// �Ҿ���� ��ȣ
#endif

#ifdef WEEK2
extern void boj_1874();			// ���� ����
extern void boj_11866();        // �似Ǫ�� ���� (�ݺ�)
extern void boj_11866_2();		// �似Ǫ�� ���� (���)
extern void boj_4949();         // �������� ���� (����) 
extern void boj_10816();        // ���� ī��2
extern void boj_2587();			// ��ǥ��
extern void boj_4195();			// ģ�� ��Ʈ��ũ * ���ذ�
extern void boj_24060();		// ��͸� �̿��� �������� * ���ذ�
extern void boj_15828();		// Deque�� �̿��� Router ����
extern void boj_1966();			// ������ ť	* ���ذ�
extern void boj_1004();			// � ����
#endif

#ifdef WEEK3
extern void boj_11279();		// �ִ���
extern void boj_11000();		// ���ǽ� ����
#endif

#ifdef WEEK4
extern void boj_1012();			// ����� ����
extern void boj_1920();			// �� ã�� (�̺� Ž��)
extern void boj_11051();		// ���װ��2	     * ���ذ�
extern void boj_1010();			// �ٸ�����
extern void boj_9375();			// �мǿ� ���غ�	 * ���ذ�
extern void boj_2667();			// ������ȣ ���̱� (�׷���)
extern void boj_2178();			// �̷�Ž�� (�׷���)
extern void pc_test();
#endif

int main() {
	boj_2178();
}