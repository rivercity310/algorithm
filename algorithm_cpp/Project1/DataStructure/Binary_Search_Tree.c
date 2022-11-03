#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
[ ���� Ž��Ʈ��, BST ]
���� ����Ʈ��: ��Ʈ���� ���� ��
������ ����Ʈ��: ��Ʈ���� ū ��

BST�� ������ȸ�ϸ� ������������ ���ĵ� ���� ���� �� �ִ�.
*/


typedef struct tr {
	int data;
	struct tr* left;
	struct tr* right;
} TreeNode;

/* ��ȯ���� ����� Ž�� �Լ� */
static TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) 
		return NULL;

	if (node->data == key)
		return node;

	else if (node->data > key) 
		return search(node->left, key);
	
	return search(node->right, key);
}

/* �ݺ����� ����� Ž�� �Լ� */
static TreeNode* search2(TreeNode* node, int key) {
	while (node) {
		if (node->data == key)
			return node;

		else if (node->data > key)
			node = node->left;

		else
			node = node->right;
	}

	return NULL;
}

static TreeNode* new_node(int data) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->data = data;
	tmp->left = tmp->right = NULL;

	return tmp;
}

/* ���Կ��� : Ž���� ������ ��ġ�� ���ο� ��带 �����ϴ� ��ġ�� �� */
static TreeNode* insert_node(TreeNode* node, int key) {
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < node->data)
		node->left = insert_node(node->left, key);
	else if (key > node->data)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

static TreeNode* min_value_node(TreeNode* node);

/* 
���� ������ ���� 3���� ��찡 ���� 

1. �ܸ� ����� ���
=> ����. �θ� ��带 ã�� ���Ḹ ������ ��

2. �ڽ����� �ϳ��� ����Ʈ���� ���� ���
=> �θ� ����� �����Ϸ��� ����� �ڽ� ��带 �����Ű�� ����

3. �ڽ����� �ΰ��� ����Ʈ���� ��� ���� ���
=> �����Ϸ��� ���� ���� ����� ���� ���� ��带 ���� ��� ��ġ�� ��������,
   ���� ��ġ�� �ִ� ��� ����
   (���� ����Ʈ������ ���� ū �� or ������ ����Ʈ������ ���� ���� ��)
*/
static TreeNode* delete_node(TreeNode* root, int key) { // key ��� ���� �� ��Ʈ ��ȯ
	if (root == NULL) return root;
	if (key < root->data) 			// Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� ����
		root->left = delete_node(root->left, key);
	else if (key > root->data) 		// Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
		root->right = delete_node(root->right, key);
	else {				// Ű�� ��Ʈ�� ������ �� ��带 ������
		if (root->left == NULL) {	// (1) or (2)
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	// (1) or (2)
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right); 		// (3)
		root->data = temp->data; 				// ���� Ű ����
		root->right = delete_node(root->right, temp->data); 	// ���� ��� ����
	}
	return root;
}

static TreeNode* min_value_node(TreeNode* node) {
	TreeNode* curr = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (curr->left)
		curr = curr->left;

	return curr;
}

static void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void Binary_Search_Tree() {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	int n;
	scanf_s("%d", &n);

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		root = insert_node(root, rand() % 100);

	puts("[ BST Inorder ]");
	inorder(root);
	puts("\n");

	for (int i = 0; i < 3; i++) {
		printf("del: ");
		scanf_s("%d", &n);
		delete_node(root, n);
	
		puts("[ BST Inorder ]");
		inorder(root);
		puts("\n");
	}
}