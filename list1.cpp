#include <iostream>
#include <vector>
#include <iomanip>

/*
[ �ܼ� ���� ����Ʈ ���� ]
*/

using namespace std;

typedef struct node {
	int data;
	struct node* next;
} Node;

/* ���� ����Ʈ�� �����ϴ� ����ü */
typedef struct {
	Node* head;			/* �Ӹ� ��带 ����Ű�� ������ */
	Node* current;		/* ���� ������ ��带 ����Ű�� ������ */
} List;

static Node* AllocNode(void) {
	return new Node;
}

static void SetNode(Node* n, int x, Node* next) {
	n->data = x;
	n->next = next;
}

void Initialize(List* list) {
	list->head = NULL;
	list->current = NULL;
}

Node* Search(List* list, int x) {
	Node* p = list->head;
	while (p) {
		if (p->data == x) {
			list->current = p;
			return p;
		}

		p = p->next;
	}

	return NULL;
}

/* �Ӹ��� ��� ���� */
void InsertFront(List* list, int x) {
	Node* p = list->head;
	list->head = list->current = AllocNode();
	SetNode(list->head, x, p);
}

/* ������ ��� ���� */
void InsertRear(List* list, int x) {
	if (!list->head)
		InsertFront(list, x);
	else {
		Node* p = list->head;
		
		/* p�� ���� ��带 ����Ű���� ���� */
		while (p->next)
			p = p->next;

		p->next = list->current = AllocNode();
		SetNode(p->next, x, NULL);
	}
}

/* �Ӹ� ��� ���� */
void RemoveFront(List* list) {
	if (list->head) {
		Node* p = list->head->next;
		delete list->head;
		list->head = list->current = p;
	}
}

/* ���� ��� ���� */
void RemoveRear(List* list) {
	if (list->head) {
		if (list->head->next == NULL)
			RemoveFront(list);
		else {
			Node* p = list->head;
			Node* pre = NULL;

			while (p->next) {
				pre = p;
				p = p->next;
			}

			pre->next = NULL;
			delete p;
			list->current = pre;
		}
	}
}

/* ������ ��� ���� */
void RemoveCurrent(List* list) {
	if (list->head) {
		if (list->current == list->head)
			RemoveFront(list);
		else {
			Node* p = list->head;
			
			while (p->next != list->current)
				p = p->next;

			p->next = list->current->next;
			delete list->current;
			list->current = p;
		}
	}
}

/* ��� ��� ���� */
void Clear(List* list) {
	while (list->head)
		RemoveFront(list);
	list->current = NULL;
}

/* ��� ��� ��� */
void PrintNodes(const List* list) {
	if (list->head == NULL)
		puts("��尡 �����ϴ�!");
	else {
		Node* p = list->head;

		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

int Select_Menu() {
	vector<string> msg = {
		"�Ӹ��� ��� ����", "������ ��� ����", "�Ӹ� ��� ����",
		"���� ��� ����", "���� ��� ����", "��� �˻�", "��� ��� ���",
		"��� ��� ���� & ����"
	};

	int ch = NULL;
	do {
		for (int i = 0; i < msg.size(); i++) {
			cout << "(" << i + 1 << ")";
			cout << setw(30) << left << msg[i];
			if (i % 3 == 2)
				putchar('\n');
		}
		cout << endl;

		cin >> ch;

	} while (ch < 0 || ch > msg.size());

	return ch;
}

void list1_test() {
	List list;
	Initialize(&list);

	do {
		int x;
		switch (Select_Menu()) {
		/* �Ӹ��� ���� */
		case 1:
			cout << "������ ������: ";
			cin >> x;
			InsertFront(&list, x);
			break;

		/* ������ ���� */
		case 2:
			cout << "������ ������: ";
			cin >> x;
			InsertRear(&list, x);
			break;

		/* �Ӹ� ���� */
		case 3:
			RemoveFront(&list);
			break;

		/* ���� ���� */
		case 4:
			RemoveRear(&list);
			break;

		/* ���� ��� ���� */
		case 5:
			RemoveCurrent(&list);
			break;

		/* ��� �˻� */
		case 6: {
			cout << "�˻��� ������: ";
			cin >> x;

			Node* p = Search(&list, x);
			if (p) cout << p->data << " ����\n";
			else cout << "�������� �ʴ� ������\n";
			break;
		}

		/* ��� ��� ��� */
		case 7:
			PrintNodes(&list);
			break;

		/* ��� ��� ���� & ���� */
		case 8:
			Clear(&list);
			return;
		}
	} while (true);
}