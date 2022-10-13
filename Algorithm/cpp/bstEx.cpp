#include <iostream>
using namespace std;;

class bst_ex {
private:
	struct node {
		int data;
		node* left;
		node* right;
	};

	node* root = nullptr;

	// �ļ� ��带 ã�� �Լ�
	node* successor(node* start) {
		auto current = start->right;
		while (current && current->left) current = current->left;

		return current;
	}

	node* find_impl(node* current, int value) {
		if (!current) {
			cout << endl;
			return NULL;
		}

		if (current->data == value) {
			cout << value << "��(��) ã�ҽ��ϴ�." << endl;
			return current;
		}

		// value ���� ���� ��� ���ʿ� �ִ� ���
		if (value < current->data) {
			cout << current->data << "���� �������� �̵� -> ";
			return find_impl(current->left, value);
		}

		// value ���� ���� ��� �����ʿ� �ִ� ���
		cout << current->data << "���� ���������� �̵� -> ";
		return find_impl(current->right, value);
	}

	void insert_impl(node* current, int value) {
		if (value < current->data) {
			if (!current->left) current->left = new node{ value, NULL, NULL };
			else insert_impl(current->left, value);
		}
		else {
			if (!current->right) current->right = new node{ value, NULL, NULL };
			else insert_impl(current->right, value);
		}
	}

	void inorder_impl(node* start) {
		if (!start) return;

		inorder_impl(start->left);
		cout << start->data << " ";
		inorder_impl(start->right);
	}

	node* delete_impl(node* start, int value) {
		if (!start) return NULL;

		if (value < start->data) start->left = delete_impl(start->left, value);
		else if (value > start->data) start->right = delete_impl(start->right, value);
		else {
			// �ڽ� ��尡 ���� ���ų�, ���� �ڽ� ��常 ���� ���
			if (!start->left) {
				auto tmp = start->right;
				delete start;
				return tmp;
			}

			// ������ �ڽ� ��常 ���� ���
			if (!start->right) {
				auto tmp = start->left;
				delete start;
				return tmp;
			}

			// �ڽ� ��尡 �� �� �ִ� ���
			auto succNode = successor(start);
			start->data = succNode->data;

			// ������ ���� Ʈ������ �ļ��� ã�� ����
			start->right = delete_impl(start->right, succNode->data);
		}

		return start;
	}

public:
	bst_ex(int val) {
		root = new node{ val, NULL, NULL };
	}

	node* find(int value) {
		return find_impl(root, value);
	}

	void insert(int value) {
		if (!root) root = new node{ value, NULL, NULL };
		else insert_impl(root, value);
	}

	void inorder() {
		inorder_impl(root);
	}

	void deleteValue(int value) {
		root = delete_impl(root, value);
	}

	void inorder(node* start) {
		if (!start) return;

		inorder(start->left);
		std::cout << start->data << " ";
		inorder(start->right);
	}
};

void bstEX() {
	bst_ex tree(20);
	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);

	cout << "���� ��ȸ: ";
	tree.inorder();      // BST���� ���� ��ȸ�� ��� ���Ҹ� ������������ ����Ѵ�
	cout << endl;

	tree.deleteValue(12);
	cout << "12�� ������ �� ���� ��ȸ: ";
	tree.inorder();
	cout << endl;

	if (tree.find(12)) cout << "12�� Ʈ���� �ֽ��ϴ�." << endl;
	else cout << "12�� Ʈ���� �����ϴ�." << endl;
}