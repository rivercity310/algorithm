#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct queueNode {
	int data;
	struct queueNode* next;
} QueueNode;

typedef struct {
	QueueNode* front;
} LinkedQueueType;

/* 
1. static �Լ��� �ٸ� ���Ͽ��� ȣ������ ���Ѵ�.
2. �ٸ� ���Ͽ��� ������ �Լ����� ����� �� �ִ�.
*/
static QueueNode* allocNode() {
	return (QueueNode*)malloc(sizeof(QueueNode));
}

static void init(LinkedQueueType q[], int size) {
	for (int i = 0; i < size; i++) {
		q[i].front = NULL;
	}
}

static int is_empty(LinkedQueueType q[], int i) {
	return q[i].front == NULL;
}

static void push(LinkedQueueType q[], int data, int i) {
	QueueNode* tmp = allocNode();
	tmp->data = data;
	tmp->next = NULL;

	// �ش� ť�� ���������
	if (is_empty(q, i)) {
		q[i].front = tmp;
		return;
	}

	// �� ��带 ã�� �� ���� ��忡 Ǫ��
	QueueNode* p = q[i].front;
	while (p->next) p = p->next;
	p->next = tmp;

}

static int pop(LinkedQueueType q[], int i) {
	QueueNode* tmp = q[i].front;
	int data = tmp->data;

	q[i].front = q[i].front->next;

	free(tmp);
	return data;
}

static void print_queue(LinkedQueueType q[], int i) {
	QueueNode* tmp = q[i].front;

	for (; tmp; tmp = tmp->next) 
		printf("%d => ", tmp->data);
	puts("NULL");
}

static void terminate(LinkedQueueType q[], int size) {
	for (int i = 0; i < size; i++) {
		QueueNode* tmp = q[i].front;
		QueueNode* p = tmp;

		printf("[ Queue(%d) �޸� ���� �۾� ���� ]\n", i);
		while (tmp) {
			tmp = p->next;
			printf("%d ����\n", p->data);
			free(p);
			p = tmp;
		}

		puts("\n");
	}
}

void Multi_Linked_Queue_Test() {
	LinkedQueueType q[MAX];
	init(q, MAX);

	for (int i = 0; i < MAX; i++) {
		
		printf("[ Queue(%d) push �۾��� �����մϴ�. ]\n", i);

		push(q, 1, i);
		push(q, 2, i);
		push(q, 3, i);
		print_queue(q, i);

		puts("\n");
	}

	for (int i = 0; i < MAX; i++) {
		printf("q[%d]�� �ּ� = %d\n", i, &q[i]);
		printf("q[%d].front�� ����� ������ �ּ�\n", i);
		for (QueueNode* tmp = q[i].front; tmp; tmp = tmp->next)
			printf("tmp->data = %d, data�� �ּ� = %lu, tmp->next = %lu, tmp->next�� �ּ� = %lu\n", tmp->data, &(tmp->data), tmp->next, &tmp->next);

		puts("\n");
	}

	puts("\n");

	
	for (int i = 0; i < MAX; i++) {
		
		printf("[ Queue(%d) pop �۾��� �����մϴ�. ]\n", i);
		printf("q[%d] = %u, q[%d].front = %u\n", i, &q[i], i, q[i].front);

		putchar('\n');

		while (!is_empty(q, i)) {
			int a = pop(q, i);
			printf("poped: %d\n", a);
			print_queue(q, i);
		}

		puts("---------------------------------------------------------------------------------------\n");
	}
	
	terminate(q, MAX);
}
