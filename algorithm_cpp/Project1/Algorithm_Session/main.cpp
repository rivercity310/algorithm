#define MAIN
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define WEEK1
#define WEEK2

#ifdef MAIN
#include <iostream>
#include <stack>
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
extern void boj_11866();        // �似Ǫ�� ����
extern void boj_4949();         // �������� ���� (����)  * ���ذ�
#endif

int main() {
	boj_4949();
}