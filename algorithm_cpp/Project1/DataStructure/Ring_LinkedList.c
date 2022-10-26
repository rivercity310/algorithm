#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

/*
[ ���� ���Ḯ��Ʈ ]
- ������ ����� ��ũ�� ù��° ��带 ����Ű�� ����Ʈ
  => �� ��忡�� �ٸ� ��� ���� ������ �����ϴٴ� ����
*/

typedef struct node {
	int data;
	struct node* next;
} Node;

Node* rll_insert_first(Node* head, int x) {
	Node* tmp;
	if ((tmp = (Node*)malloc(sizeof(Node)))) {
		tmp->data = x;

		if (head == NULL) {
			head = tmp;
			tmp->next = head;
			return head;
		}
		
		/* p�� ������ ���� �̵� */
		Node* p = head;
		do {
			p = p->next;
		} while (p->next != head);

		tmp->next = head;
		head = tmp;
		p->next = tmp;
	}

	return head;
}

Node* rll_insert_last(Node* head, int x) {
	Node* tmp;
	if ((tmp = (Node*)malloc(sizeof(Node)))) {
		tmp->data = x;

		if (head == NULL) {
			head = tmp;
			tmp->next = head;
			return head;
		}

		Node* p = head;
		do {
			p = p->next;
		} while (p->next != head);

		/* 
		������ ��尡 ������ tmp ��带 ����Ű�� �ϰ�, 
		������ ��尡 head ��带 ����Ű�� �Ѵ�.
		*/
		p->next = tmp;
		tmp->next = head;
	}

	return head;
}

void rll_print(Node* head) {
	if (head == NULL) return;

	for (Node* p = head; p->next != head; p = p->next)
		printf("%d ", p->data);
	putchar('\n');
}

void rll_terminate(Node* head) {
	Node* p = head;
	while (p->next != head) {
		Node* tmp = p->next;
		printf("Dealloc: %d\n", p->data);
		free(p);
		p = tmp;
	}
}

void Ring_LinkedList() {
	Node* head = NULL;

	for (int i = 0; i < MAX; i++) {
		if (i < 10) head = rll_insert_first(head, i);
		else head = rll_insert_last(head, i);
	}

	rll_print(head);
	rll_terminate(head);
}